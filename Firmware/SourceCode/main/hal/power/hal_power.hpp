/**
 * @file hal_power.hpp
 * @author Forairaaaaa
 * @brief 
 * @version 0.1
 * @date 2023-05-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once
#include <driver/i2c.h>
#include <esp_log.h>


/**
 * @brief Modify from "hal_tp.hpp"
 * 
 */
namespace AXP2101 {


    static const char* TAG = "AXP2101";


    struct Config_t {
        int pin_scl     = -1;
        int pin_sda     = -1;
        int pin_int     = -1;
        i2c_port_t i2c_port = (i2c_port_t)0;

        uint8_t dev_addr = 0x34;
    };


    class AXP2101 {
        private:
            Config_t _cfg;
            uint8_t _data_buffer[2];

            inline esp_err_t _writrReg(uint8_t reg, uint8_t data)
            {
                _data_buffer[0] = reg;
                _data_buffer[1] = data; 
                return i2c_master_write_to_device(_cfg.i2c_port, _cfg.dev_addr, _data_buffer, 2, portMAX_DELAY);
            }

            inline esp_err_t _readReg(uint8_t reg, uint8_t readSize)
            {
                /* Store data into buffer */
                return i2c_master_write_read_device(_cfg.i2c_port, _cfg.dev_addr, &reg, 1, _data_buffer, readSize, portMAX_DELAY);
            }


        public:

            /* Config */
            inline Config_t config() { return _cfg; }
            inline void config(const Config_t& cfg) { _cfg = cfg; }
            inline void setPin(const int& sda, const int& scl, const int& intr)
            {
                _cfg.pin_sda = sda;
                _cfg.pin_scl = scl;
                _cfg.pin_int = intr;
            }


            inline bool init(const int& sda, const int& scl, const int& intr = -1)
            {
                setPin(sda, scl, intr);
                return init();
            }

            inline bool init()
            {
                gpioInit();




                /* Limit charging current */
                _readReg(0x62, 1);
                ESP_LOGI(TAG, "read 0x62 get: 0x%X", _data_buffer[0]);
                
                /* 100mA -> 0b00000100 */
                // 200mA -> 0b00001000
                // 400mA -> 0b00001010
                // 500mA -> 0b00001011
                _data_buffer[0] = _data_buffer[0] & 0b11100000;
                _data_buffer[0] = _data_buffer[0] | 0b00001011;
                _writrReg(0x62, _data_buffer[0]);

                _readReg(0x62, 1);
                ESP_LOGI(TAG, "read charge current limit 0x62 get: 0x%X", _data_buffer[0]);


                return true;
            }


            /* Setup gpio and reset */
            inline void gpioInit()
            {
                ESP_LOGD(TAG, "setup gpio");

                if (_cfg.pin_int > 0) {
                    gpio_reset_pin((gpio_num_t)_cfg.pin_int);
                    gpio_set_direction((gpio_num_t)_cfg.pin_int, GPIO_MODE_INPUT);
                }
            }


            /* Power key status */
            inline bool isKeyPressed()
            {
                /* IRQ status 1 */
                _readReg(0x49, 1);
                if (_data_buffer[0] & 0b00001000) {
                    /* Clear */
                    _writrReg(0x49, _data_buffer[0]);
                    return true;
                }
                return false;
            }

            inline bool isKeyLongPressed()
            {
                /* IRQ status 1 */
                _readReg(0x49, 1);
                if (_data_buffer[0] & 0b00000100) {
                    /* Clear */
                    _writrReg(0x49, _data_buffer[0]);
                    return true;
                }
                return false;
            }


            /* Charging status */
            inline bool isCharging()
            {
                /* PMU status 2 */
                _readReg(0x01, 1);
                if ((_data_buffer[0] & 0b01100000) == 0b00100000) {
                    return true;
                }
                return false;
            }

            inline bool isBatteryStandby()
            {
                /* PMU status 2 */
                _readReg(0x01, 1);
                if ((_data_buffer[0] & 0b01100000) == 0b00000000) {
                    return true;
                }
                return false;
            }

            inline bool isChargeDone()
            {
                /* PMU status 2 */
                _readReg(0x01, 1);
                if ((_data_buffer[0] & 0b00000111) == 0b00000100) {
                    return true;
                }
                return false;
            }


            /* Bettery status */
            inline uint8_t batteryLevel()
            {
                /* Battery percentage data */
                _readReg(0xA4, 1);
                return _data_buffer[0];
            }


            inline void setRegisterBit(uint8_t registers, uint8_t bit)
            {
                _readReg(registers, 1);
                int val = _data_buffer[0];
                if (val == -1) {
                    return;
                }                       
                _writrReg(registers, (val | (1ULL << (bit))));
            }

            void enableBattVoltageMeasure(void)
            {
                setRegisterBit(0x30, 0);
            }

            uint16_t inline readRegisterH5L8(uint8_t highReg, uint8_t lowReg)
            {
                _readReg(highReg, 1);
                int h5 = _data_buffer[0];
                _readReg(lowReg, 1);
                int l8 = _data_buffer[0];
                if (h5 == -1 || l8 == -1)return 0;
                return ((h5 & 0x1F) << 8) | l8;
            }

            uint16_t getBattVoltage(void)
            {
                return readRegisterH5L8(0x34, 0x35);
            }

            /* Power control */
            inline void powerOff()
            {
                /* PMU common configuration */
                _readReg(0x10, 1);
                /* Soft power off */
                _writrReg(0x10, (_data_buffer[0] | 0b00000001));
            }

    };
    

    



}
