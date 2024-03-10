/**
 * @brief
 * @version 0.1
 * @date 2023-05-28
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "app.h"
#include "../assets/assets.h"
#include <ArduinoJson.hpp>

#include <lvgl.h>

/* If not include this, lv_fs acts strange in my wsl linux env */
#include <esp_system.h>
#include <stdio.h>
#include <stdlib.h>

extern "C" {

void fly_game_start();
void flygame_all_clear(lv_event_t *e);
}

namespace MOONCAKE {
namespace BUILTIN_APP {

void Aircraft::onSetup() {
  setAppName("Aircraft");
  setAllowBgRunning(false);
  setAppIcon((void *)&ui_img_aircraft_108_png);
}

void Aircraft::onCreate() {
  LvglGameBase::onCreate();
  // eggfly
  fly_game_start();
}

void Aircraft::onDestroy() {
  LvglGameBase::onDestroy();
  flygame_all_clear(nullptr);
}

} // namespace BUILTIN_APP
} // namespace MOONCAKE
