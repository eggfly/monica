/**
 * @file sketchpad.cpp
 * @author Forairaaaaa
 * @brief
 * @version 0.1
 * @date 2023-05-29
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "watch_face.h"
#include "../assets/assets.h"
#include "math.h"
#include <esp_log.h>
#include "ui.h"



namespace UserApps
{

    static const char *TAG = "BlackWatch";

    void BlackWatch::color_changer_create(lv_obj_t *parent)
    {
    }

    void BlackWatch::color_changer_anim_cb(void *var, int32_t v)
    {
    }

    void BlackWatch::color_changer_event_cb(lv_event_t *e)
    {
    }

    void BlackWatch::color_event_cb(lv_event_t *e)
    {
    }

    void BlackWatch::_lvgl_event_cb(lv_event_t *e)
    {
        /* Get event code */
        lv_event_code_t code = lv_event_get_code(e);
    }

    void BlackWatch::_update_drawing()
    {
    }

    void BlackWatch::onSetup()
    {
        setAppName("BlackWatch");
        setAllowBgRunning(false);
        setAppIcon((void *)&ui_img_app_icon_hdpi_wf_user_custom_png);
    }

    /* Life cycle */
    void BlackWatch::onCreate()
    {
        printf("[%s] onCreate\n", getAppName().c_str());

        /* Reset data to default */
        {
            BlackWatchFace::Data_t data;
            _data = data;
        }

        /* Get data's pointer from database */
        _data.key_home_ptr = (bool *)getDatabase()->Get(MC_KEY_HOME)->addr;
        /* Reset at first */
        *_data.key_home_ptr = false;

        _data.screen = lv_obj_create(NULL);
        lv_scr_load_anim(_data.screen, LV_SCR_LOAD_ANIM_FADE_IN, 50, 0, false);
        /* Set background color */
        lv_obj_set_style_bg_color(_data.screen, lv_color_hex(0x000000), LV_STATE_DEFAULT);
        /* Add event callback */
        lv_obj_add_event_cb(_data.screen, _lvgl_event_cb, LV_EVENT_ALL, (void *)this);

        ui_init();
    }

    void BlackWatch::onResume()
    {
        printf("[%s] onResume\n", getAppName().c_str());
    }

    void BlackWatch::onRunning()
    {
        /* If pressed key Home */
        if (*_data.key_home_ptr)
        {
            /* Reset */
            *_data.key_home_ptr = false;

            /* Quit */
            destroyApp();
        }
    }

    void BlackWatch::onRunningBG()
    {
    }

    void BlackWatch::onPause()
    {
        printf("[%s] onPause\n", getAppName().c_str());
    }

    void BlackWatch::onDestroy()
    {
        printf("[%s] onDestroy\n", getAppName().c_str());
    }

}
