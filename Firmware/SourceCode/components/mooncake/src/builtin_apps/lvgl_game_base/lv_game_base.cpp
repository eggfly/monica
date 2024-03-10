
#include "lv_game_base.h"
#include "../assets/assets.h"
#include <ArduinoJson.hpp>

/* If not include this, lv_fs acts strange in my wsl linux env */
#include <stdio.h>
#include <stdlib.h>
#include <esp_system.h>


namespace MOONCAKE {
    namespace BUILTIN_APP {


        void LvglGameBase::_lvgl_event_cb(lv_event_t* e)
        {
            /* Get event code */
            lv_event_code_t code = lv_event_get_code(e);

        }


        void LvglGameBase::_update_data()
        {
        }



        void LvglGameBase::onSetup()
        {
            setAppName("Plants vs Zombies");
            setAllowBgRunning(false);
            setAppIcon((void*)&ui_img_pvz_108_png);
        }


        /* Life cycle */
        void LvglGameBase::onCreate()
        {
            printf("[%s] onCreate\n", getAppName().c_str());
            /* make data goes default */
            {
                LV_GAME_BASE::Data_t data;
                _data = data;
            }

            _data.key_home_ptr = (bool*)getDatabase()->Get(MC_KEY_HOME)->addr;
            /* Reset at first */
            *_data.key_home_ptr = false;
            
            // pvz_start();
            // ballgame_start();
            // fly_game_start();
            // 

        }


        void LvglGameBase::onResume()
        {
            printf("[%s] onResume\n", getAppName().c_str());
        }


        void LvglGameBase::onRunning()
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
                destroyApp();
                // esp_restart();
            }

        }


        void LvglGameBase::onRunningBG()
        {

        }


        void LvglGameBase::onPause()
        {
            printf("[%s] onPause\n", getAppName().c_str());
        }


        void LvglGameBase::onDestroy()
        {
            printf("[%s] onDestroy\n", getAppName().c_str());
        }



    }
}

