/**
 * @file mooncake.cpp
 * @author Forairaaaaa
 * @brief 
 * @version 0.1
 * @date 2023-05-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "mooncake.h"

#define USE_CUSTOM_WATCH_FACE_APP   0

namespace MOONCAKE {


    void Mooncake::setupDatabase()
    {
        
    }


    void Mooncake::installBuiltinApps()
    {
        APP_BASE* app_ptr = nullptr;

        /* User custom watch face */
        app_ptr = new BUILTIN_APP::PvZ;
        install(app_ptr, nullptr);

#if USE_CUSTOM_WATCH_FACE_APP == 1
        /* User custom watch face */
        app_ptr = new BUILTIN_APP::WF_User_Custom;
        install(app_ptr, nullptr);
#endif

        /* Default anim watch face */
        app_ptr = new BUILTIN_APP::WF_Spring_Wreath;
        install(app_ptr, nullptr);

        /* Sketchpad */
        app_ptr = new BUILTIN_APP::Sketchpad;
        install(app_ptr, nullptr);
        
        /* Settings */
        app_ptr = new BUILTIN_APP::Settings;
        install(app_ptr, nullptr);

        /* Settings Brightness */
        app_ptr = new BUILTIN_APP::SettingsBrightness;
        install(app_ptr, nullptr);
    }

}

