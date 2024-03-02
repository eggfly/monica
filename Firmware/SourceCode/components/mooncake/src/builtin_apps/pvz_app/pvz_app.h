/**
 * @brief 
 * @version 0.1
 * @date 2023-05-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once
#include "../../app/app.h"
#include "../../system_data_def.h"
#include <lvgl.h>
#include <iostream>
#include <string>
#include <vector>


namespace MOONCAKE {
    namespace BUILTIN_APP {


        namespace PVZ {


            struct Data_t {
                /* Update data in 1Hz */
                uint32_t update_interval = 1000;
                uint32_t update_count = 0;
                bool running = false;

                DataTime_t* time_ptr = nullptr;
                bool* just_wake_up_ptr = nullptr;
                bool* key_home_ptr = nullptr;
            };

        }


        class PvZ : public APP_BASE {
            private:
                PVZ::Data_t _data;

                static void _lvgl_event_cb(lv_event_t* e);
                void _update_data();



            public:
                PvZ() = default;
                ~PvZ() = default;

                void onSetup();

                /* Life cycle */
                void onCreate();
                void onResume();
                void onRunning();
                void onRunningBG();
                void onPause();
                void onDestroy();
            
        };


    }
}
