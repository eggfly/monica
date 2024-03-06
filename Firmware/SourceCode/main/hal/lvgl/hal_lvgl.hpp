/**
 * @file hal_lvgl.hpp
 * @author Forairaaaaa
 * @brief
 * @version 0.1
 * @date 2023-05-21
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once
#include <esp_log.h>
#include <lvgl.h>
#include "../disp/hal_disp.hpp"
#include "../tp/hal_tp.hpp"

#include "lv_demos.h"
#include <stdio.h>
#include <string.h>
#include <sys/unistd.h>
#include <sys/stat.h>
#include "esp_err.h"
#include "esp_log.h"
#include "esp_spiffs.h"

#include "esp_partition.h"
#include "../../../components/mooncake/src/builtin_apps/assets/icon/anim/icon_anim.h"
#include "../../../components/mooncake/src/builtin_apps/assets/assets.h"

#include <MyBMI270.h>

// static inline uint32_t micros_start() __attribute__ ((always_inline));
// static inline uint32_t micros_start()
// {
//   uint8_t oms = millis();
//   while ((uint8_t)millis() == oms)
//     ;
//   return micros();
// }

extern "C"
{
    void spi_flash_mmap_dump(void);
}

namespace LVGL
{

    static const char *TAG = "LVGL";

    static lgfx::LGFX_Device *_disp;
    static FT3168::TP_FT3168 *_tp;
    static FT3168::TouchPoint_t _tpp;
    static BMI270::BMI270 *_imu;

    class LVGL
    {
    private:
        /*Flush the content of the internal buffer the specific area on the display
         *You can use DMA or any hardware acceleration to do this operation in the background but
         *'lv_disp_flush_ready()' has to be called when finished.*/
        static void _disp_flush(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p)
        {
            int32_t w = (area->x2 - area->x1 + 1);
            int32_t h = (area->y2 - area->y1 + 1);
            // ESP_LOGI(TAG, "flush x,y,w,h=%d,%d,%ld,%ld", area->x1, area->y1, w, h);
            _disp->startWrite();
            // eggfly: TODO: rotation support
            // _disp->setRotation(disp_drv->rotated);
            _disp->setWindow(area->x1, area->y1, area->x2, area->y2);
            // _disp->pushPixels(&color_p->full, w * h, true);
            _disp->pushPixelsDMA(&color_p->full, w * h, true);
            _disp->endWrite();

            /*IMPORTANT!!!
             *Inform the graphics library that you are ready with the flushing*/
            lv_disp_flush_ready(disp_drv);
        }

        /*Will be called by the library to read the touchpad*/
        static void _touchpad_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data)
        {
            _tp->getTouchRaw(_tpp);
            if (_tpp.x != -1)
            {
                // ESP_LOGI(TAG, "_touchpad_read: %d %d", _tpp.x, _tpp.y);
                data->point.x = _tpp.x;
                data->point.y = _tpp.y;
                data->state = LV_INDEV_STATE_PR;
            }
            else
            {
                data->state = LV_INDEV_STATE_REL;
            }
        }

        /* Will be called by the library */
        static void _imu_pointer_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data)
        {
            if (_imu->accelerationAvailable())
            {
                float x, y, z;
                int ret = _imu->readAcceleration(x, y, z);
                ESP_LOGI(TAG, "_imu_pointer_read() ret=%d %f,%f,%f", ret, x, y, z);
                data->point.x = _disp->width() / 2;
                data->point.y = _disp->height() / 2;
                data->state = LV_INDEV_STATE_PR;
            }
            else
            {
                data->state = LV_INDEV_STATE_REL;
            }
        }

        inline void _lv_port_disp_init()
        {
            static lv_disp_draw_buf_t draw_buf_dsc_3;
            lv_color_t *buf_3_1;
            lv_color_t *buf_3_2;

#if CONFIG_SPIRAM_USE_MALLOC
            buf_3_1 = (lv_color_t *)malloc(_disp->width() * _disp->height() * sizeof(lv_color_t));
            buf_3_2 = (lv_color_t *)malloc(_disp->width() * _disp->height() * sizeof(lv_color_t));
#else
            buf_3_1 = (lv_color_t *)heap_caps_malloc(_disp->width() * _disp->height() * sizeof(lv_color_t), MALLOC_CAP_SPIRAM);
            buf_3_2 = (lv_color_t *)heap_caps_malloc(_disp->width() * _disp->height() * sizeof(lv_color_t), MALLOC_CAP_SPIRAM);
#endif
            /* If failed */
            if ((buf_3_1 == NULL) || (buf_3_2 == NULL))
            {
                ESP_LOGE(TAG, "malloc buffer from PSRAM fialed");
                while (1)
                    ;
            }
            else
            {
                ESP_LOGI(TAG, "malloc buffer from PSRAM successful");
                ESP_LOGI(TAG, "free PSRAM: %d\r\n", heap_caps_get_free_size(MALLOC_CAP_SPIRAM));
            }

            lv_disp_draw_buf_init(&draw_buf_dsc_3, buf_3_1, buf_3_2,
                                  _disp->height() * _disp->height()); /*Initialize the display buffer*/

            /*-----------------------------------
             * Register the display in LVGL
             *----------------------------------*/

            static lv_disp_drv_t disp_drv; /*Descriptor of a display driver*/
            lv_disp_drv_init(&disp_drv);   /*Basic initialization*/
            /*Set up the functions to access to your display*/

            // eggfly
            disp_drv.sw_rotate = 1;
            /*Set the resolution of the display*/
            disp_drv.hor_res = _disp->width();
            disp_drv.ver_res = _disp->height();

            /*Used to copy the buffer's content to the display*/
            disp_drv.flush_cb = _disp_flush;

            /*Set a display buffer*/
            disp_drv.draw_buf = &draw_buf_dsc_3;

            /*Required for Example 3)*/
            // disp_drv.full_refresh = 1;

            /* Fill a memory array with a color if you have GPU.
             * Note that, in lv_conf.h you can enable GPUs that has built-in support in LVGL.
             * But if you have a different GPU you can use with this callback.*/
            // disp_drv.gpu_fill_cb = gpu_fill;

            /*Finally register the driver*/
            lv_disp_drv_register(&disp_drv);
        }

        inline void _lv_port_indev_init()
        {
            /**
             * Here you will find example implementation of input devices supported by LittelvGL:
             *  - Touchpad
             *  - Mouse (with cursor support)
             *  - Keypad (supports GUI usage only with key)
             *  - Encoder (supports GUI usage only with: left, right, push)
             *  - Button (external buttons to press points on the screen)
             *
             *  The `..._read()` function are only examples.
             *  You should shape them according to your hardware
             */
            {
                static lv_indev_drv_t indev_drv;

                /*------------------
                 * Touchpad
                 * -----------------*/
                /*Register a touchpad input device*/
                lv_indev_drv_init(&indev_drv);
                indev_drv.type = LV_INDEV_TYPE_POINTER;
                indev_drv.read_cb = _touchpad_read;
                lv_indev_t *indev_mouse = lv_indev_drv_register(&indev_drv);
                lv_obj_t *mouse_cursor = lv_img_create(lv_scr_act());
                lv_img_set_src(mouse_cursor, LV_SYMBOL_CLOSE);
                lv_indev_set_cursor(indev_mouse, mouse_cursor);
            }

            {
                static lv_indev_drv_t indev_imu_pointer_drv;

                lv_indev_drv_init(&indev_imu_pointer_drv);
                indev_imu_pointer_drv.type = LV_INDEV_TYPE_POINTER;
                indev_imu_pointer_drv.read_cb = _imu_pointer_read;
                lv_indev_t *indev_imu = lv_indev_drv_register(&indev_imu_pointer_drv);
                lv_obj_t *imu_cursor = lv_img_create(lv_scr_act());
                lv_img_set_src(imu_cursor, &ui_img_cursor_hand);
                lv_indev_set_cursor(indev_imu, imu_cursor);
            }
        }

    public:
        void testRects(lgfx::LGFX_Device &tft, uint16_t color)
        {
            uint32_t start;
            int32_t n, i, i2;
            int32_t cx = tft.width() / 2;
            int32_t cy = tft.height() / 2;

            tft.fillScreen(TFT_BLACK);
            n = std::min(tft.width(), tft.height());
            for (i = 2; i < n; i += 6)
            {
                i2 = i / 2;
                tft.drawRect(cx - i2, cy - i2, i, i, color);
            }
        }
        void testFastLines(lgfx::LGFX_Device &tft, uint16_t color1, uint16_t color2)
        {
            uint32_t start;
            int32_t x, y;
            int32_t w = tft.width();
            int32_t h = tft.height();

            tft.fillScreen(TFT_BLACK);

            for (y = 0; y < h; y += 5)
                tft.drawFastHLine(0, y, w, color1);
            for (x = 0; x < w; x += 5)
                tft.drawFastVLine(x, 0, h, color2);
        }

        inline void dump_memory(const void *addr, size_t offset, int size)
        {
            unsigned char *ptr = (unsigned char *)addr;
            ptr += offset;
            for (int i = 0; i < size; i++)
            {
                printf("%p: %02x\n", ptr + i, *(ptr + i));
            }
        }

        inline const void *map_partition(const char *partition_name)
        {
            const esp_partition_t *part = esp_partition_find_first(ESP_PARTITION_TYPE_DATA, ESP_PARTITION_SUBTYPE_ANY, partition_name);
            if (part != NULL)
            {
                ESP_LOGI(TAG, "found partition '%s' at offset 0x%" PRIx32 " with size 0x%" PRIx32, part->label, part->address, part->size);
                spi_flash_mmap_dump();
                static esp_partition_mmap_handle_t map_handle;
                const void *map_ptr;
                ESP_ERROR_CHECK(esp_partition_mmap(part, 0, part->size, ESP_PARTITION_MMAP_DATA, &map_ptr, &map_handle));
                ESP_LOGI(TAG, "Mapped partition to data memory address %p", map_ptr);
                spi_flash_mmap_dump();
                return map_ptr;
            }
            else
            {
                ESP_LOGE(TAG, "\tpartition not found!");
                return nullptr;
            }
        }

        inline void init_partition_mmap()
        {
            // const void * map_ptr1 = map_partition("spring_wreath");
            // if (map_ptr1) {
            //     init_anim_spring_wreath_dsc(map_ptr1);
            // }
            // const void * map_ptr2 = map_partition("walking");
            // if (map_ptr2) {
            //     init_anim_lc_walking_dsc_and_ptrs(map_ptr2);
            // }
        }

        inline void spiffs_init(const char *path, const char *partition_name)
        {
            ESP_LOGI(TAG, "Initializing SPIFFS: %s -> %s", partition_name, path);
            esp_vfs_spiffs_conf_t conf = {
                .base_path = path,
                .partition_label = partition_name,
                .max_files = 5,
                .format_if_mount_failed = true};

            // Use settings defined above to initialize and mount SPIFFS filesystem.
            // Note: esp_vfs_spiffs_register is an all-in-one convenience function.
            esp_err_t ret = esp_vfs_spiffs_register(&conf);

            if (ret != ESP_OK)
            {
                if (ret == ESP_FAIL)
                {
                    ESP_LOGE(TAG, "Failed to mount or format filesystem");
                }
                else if (ret == ESP_ERR_NOT_FOUND)
                {
                    ESP_LOGE(TAG, "Failed to find SPIFFS partition");
                }
                else
                {
                    ESP_LOGE(TAG, "Failed to initialize SPIFFS (%s)", esp_err_to_name(ret));
                }
                return;
            }

#ifdef CONFIG_EXAMPLE_SPIFFS_CHECK_ON_START
            ESP_LOGI(TAG, "Performing SPIFFS_check().");
            ret = esp_spiffs_check(conf.partition_label);
            if (ret != ESP_OK)
            {
                ESP_LOGE(TAG, "SPIFFS_check() failed (%s)", esp_err_to_name(ret));
                return;
            }
            else
            {
                ESP_LOGI(TAG, "SPIFFS_check() successful");
            }
#endif

            size_t total = 0, used = 0;
            ret = esp_spiffs_info(conf.partition_label, &total, &used);
            if (ret != ESP_OK)
            {
                ESP_LOGE(TAG, "Failed to get SPIFFS partition information (%s). Formatting...", esp_err_to_name(ret));
                esp_spiffs_format(conf.partition_label);
                return;
            }
            else
            {
                ESP_LOGI(TAG, "Partition size: total: %d, used: %d", total, used);
            }

            // Check consistency of reported partiton size info.
            if (used > total)
            {
                ESP_LOGW(TAG, "Number of used bytes cannot be larger than total. Performing SPIFFS_check().");
                ret = esp_spiffs_check(conf.partition_label);
                // Could be also used to mend broken files, to clean unreferenced pages, etc.
                // More info at https://github.com/pellepl/spiffs/wiki/FAQ#powerlosses-contd-when-should-i-run-spiffs_check
                if (ret != ESP_OK)
                {
                    ESP_LOGE(TAG, "SPIFFS_check() failed (%s)", esp_err_to_name(ret));
                    return;
                }
                else
                {
                    ESP_LOGI(TAG, "SPIFFS_check() successful");
                }
            }

            ESP_LOGI(TAG, "Opening file");
            std::string hello_path(path);
            hello_path += "/hello.txt";
            FILE *f = fopen(hello_path.c_str(), "w");
            if (f == NULL)
            {
                ESP_LOGE(TAG, "Failed to open file for writing");
                return;
            }
            fprintf(f, "Hello World!\n");
            fclose(f);
            ESP_LOGI(TAG, "File written");

            // Check if destination file exists before renaming
            struct stat st;
            std::string foo_path(path);
            foo_path += "/foo.txt";
            if (stat(foo_path.c_str(), &st) == 0)
            {
                // Delete it if it exists
                unlink(foo_path.c_str());
            }

            // Rename original file
            ESP_LOGI(TAG, "Renaming file");
            if (rename(hello_path.c_str(), foo_path.c_str()) != 0)
            {
                ESP_LOGE(TAG, "Rename failed");
                return;
            }

            // Open renamed file for reading
            ESP_LOGI(TAG, "Reading file");
            f = fopen(foo_path.c_str(), "r");
            if (f == NULL)
            {
                ESP_LOGE(TAG, "Failed to open file for reading");
                return;
            }
            char line[64];
            fgets(line, sizeof(line), f);
            fclose(f);
            // strip newline
            char *pos = strchr(line, '\n');
            if (pos)
            {
                *pos = '\0';
            }
            ESP_LOGI(TAG, "Read from file: '%s'", line);
        }
        /**
         * @brief Lvgl init
         *
         * @param disp
         * @param tp
         */
        inline void lv_port_init(lgfx::LGFX_Device *disp, FT3168::TP_FT3168 *tp, BMI270::BMI270 *imu)
        {
            _disp = disp;
            // vTaskDelay(pdMS_TO_TICKS(1000));
            // testFastLines(*disp, TFT_RED,TFT_BLUE);
            // vTaskDelay(pdMS_TO_TICKS(1000));
            // testRects(*disp, TFT_GREEN);
            _tp = tp;
            _imu = imu;

            lv_init();
            spiffs_init("/spiffs_0", "spiffs_res_0");
            spiffs_init("/spiffs_1", "spiffs_res_1");
            init_partition_mmap();
            _lv_port_disp_init();
            _lv_port_indev_init();
        }

        /**
         * @brief Update lvgl timer
         *
         */
        inline void update() { lv_timer_handler(); }
    };

}
