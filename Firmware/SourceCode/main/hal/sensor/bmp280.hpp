
#pragma once
#include <driver/i2c.h>
#include <esp_log.h>
#include <cstring>

#include <bmp280.h>

namespace BMP280
{

    static const char *TAG = "BMP280";

    class BMP280
    {
    private:
        bmp280_t _dev;

    public:
        BMP280() {}
        ~BMP280() {}
        void init()
        {
            ESP_ERROR_CHECK(i2cdev_init());
            sensor_init();
        }

        void bmp280_test() {}

        void sensor_init()
        {
            bmp280_params_t params;
            bmp280_init_default_params(&params);
            memset(&_dev, 0, sizeof(bmp280_t));

            ESP_ERROR_CHECK(bmp280_init_desc(&_dev, BMP280_I2C_ADDRESS_1, 0, GPIO_NUM_11, GPIO_NUM_10));
            ESP_ERROR_CHECK(bmp280_init(&_dev, &params));
        }

        void readData(float *temperature, float *pressure, float *humidity)
        {
            bool bme280p = _dev.id == BME280_CHIP_ID;
            // printf("BMP280: found %s\n", bme280p ? "BME280" : "BMP280");

            // vTaskDelay(pdMS_TO_TICKS(500));
            if (bmp280_read_float(&_dev, temperature, pressure, humidity) != ESP_OK)
            {
                printf("Temperature/pressure reading failed\n");
                return;
            }

            /* float is used in printf(). you need non-default configuration in
             * sdkconfig for ESP8266, which is enabled by default for this
             * example. see sdkconfig.defaults.esp8266
             */
            // printf("Pressure: %.2f Pa, Temperature: %.2f C, Humidity: %.2f\n", *pressure, *temperature, *humidity);
        }
    };
}
