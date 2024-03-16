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
void lv_100ask_2048_simple_test();
}

namespace MOONCAKE {
namespace BUILTIN_APP {

void Game2048::onSetup() {
  setAppName("2048");
  setAllowBgRunning(false);
  setAppIcon((void *)&ui_img_game_2048_108_png);
}

void Game2048::onCreate() {
  LvglGameBase::onCreate();
  // eggfly
  lv_100ask_2048_simple_test();
}

void Game2048::onDestroy() {
  LvglGameBase::onDestroy();
  // reboot!
  esp_restart();
}

} // namespace BUILTIN_APP
} // namespace MOONCAKE
