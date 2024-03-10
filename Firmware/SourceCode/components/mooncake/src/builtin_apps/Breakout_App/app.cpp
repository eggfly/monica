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
void ballgame_start();
void ballgame_all_clear(lv_event_t *e);
}

namespace MOONCAKE {
namespace BUILTIN_APP {

void Breakout::onSetup() {
  setAppName("Breakout");
  setAllowBgRunning(false);
  setAppIcon((void *)&ui_img_breakout_108_png);
}

void Breakout::onCreate() {
  LvglGameBase::onCreate();
  // eggfly
  ballgame_start();
}

void Breakout::onDestroy() {
  LvglGameBase::onDestroy();
  ballgame_all_clear(nullptr);
}

} // namespace BUILTIN_APP
} // namespace MOONCAKE
