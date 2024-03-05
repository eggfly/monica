/**
 * @brief 
 * @version 0.1
 * @date 2023-05-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "pvz_app.h"
#include "../assets/assets.h"
#include <ArduinoJson.hpp>

/* If not include this, lv_fs acts strange in my wsl linux env */
#include <stdio.h>
#include <stdlib.h>
#include <esp_system.h>

extern "C" {
    void pvz_start();
    void exit_game_cb(lv_event_t *e);
}


namespace MOONCAKE {
    namespace BUILTIN_APP {


        void PvZ::_lvgl_event_cb(lv_event_t* e)
        {
            /* Get event code */
            lv_event_code_t code = lv_event_get_code(e);

        }


        void PvZ::_update_data()
        {
        }



        void PvZ::onSetup()
        {
            setAppName("Plants vs Zombies");
            setAllowBgRunning(false);
            setAppIcon((void*)&ui_img_pvz_108_png);
        }


        /* Life cycle */
        void PvZ::onCreate()
        {
            printf("[%s] onCreate\n", getAppName().c_str());
            // eggfly
            lv_disp_set_rotation(NULL, LV_DISP_ROT_270);
            /* make data goes default */
            {
                PVZ::Data_t data;
                _data = data;
            }

            _data.key_home_ptr = (bool*)getDatabase()->Get(MC_KEY_HOME)->addr;
            /* Reset at first */
            *_data.key_home_ptr = false;
            
            pvz_start();

        }


        void PvZ::onResume()
        {
            printf("[%s] onResume\n", getAppName().c_str());
        }


        void PvZ::onRunning()
        {
            /* Update data */
            if ((lv_tick_get() - _data.update_count) > _data.update_interval) {
                _update_data();
                _data.update_count = lv_tick_get();
            }


            /* If pressed key Home */
            if (*_data.key_home_ptr) {
                /* Reset */
                *_data.key_home_ptr = false;

                /* Quit */
                #ifdef ESP_PLATFORM
                /* Go back home with anim will crash */
                lv_obj_t* scr = lv_obj_create(NULL);
                lv_scr_load_anim(scr, LV_SCR_LOAD_ANIM_NONE, 0, 0, true);
                #endif
                exit_game_cb(nullptr);
                lv_disp_set_rotation(NULL, LV_DISP_ROT_NONE);
                destroyApp();
                // esp_restart();
            }

        }


        void PvZ::onRunningBG()
        {

        }


        void PvZ::onPause()
        {
            printf("[%s] onPause\n", getAppName().c_str());
        }


        void PvZ::onDestroy()
        {
            printf("[%s] onDestroy\n", getAppName().c_str());
        }



    }
}

