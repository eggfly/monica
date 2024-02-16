/**
 * @file sketchpad.h
 * @author Forairaaaaa
 * @brief
 * @version 0.1
 * @date 2023-05-29
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once
#include "../../../components/mooncake/src/app/app.h"
#include "../../../components/mooncake/src/system_data_def.h"
#include <lvgl.h>

namespace UserApps
{
    namespace BlackWatchFace
    {

        struct Data_t
        {

            lv_obj_t *screen = nullptr;

            lv_point_t touchPoint = {-1, -1};

            bool *key_home_ptr = nullptr;
        };

    }

    class BlackWatch : public MOONCAKE::APP_BASE
    {
    private:
        BlackWatchFace::Data_t _data;
        static void color_changer_create(lv_obj_t *parent);
        static void color_changer_anim_cb(void *var, int32_t v);
        static void color_changer_event_cb(lv_event_t *e);
        static void color_event_cb(lv_event_t *e);

        static void _lvgl_event_cb(lv_event_t *e);
        void _update_drawing();

    public:
        BlackWatch() = default;
        ~BlackWatch() = default;

        /**
         * @brief Lifecycle callbacks for derived to override
         *
         */
        /* Setup App configs, called when App "install()" */
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
