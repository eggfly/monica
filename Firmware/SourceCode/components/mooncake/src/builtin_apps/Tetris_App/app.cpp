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
void cube_game_start();
void tetris_all_clear(lv_event_t *e);
}

namespace MOONCAKE {
namespace BUILTIN_APP {

void Tetris::onSetup() {
  setAppName("Tetris");
  setAllowBgRunning(false);
  setAppIcon((void *)&ui_img_tetris_108_png);
}

void Tetris::onCreate() {
  LvglGameBase::onCreate();
  // eggfly
  cube_game_start();
}

void Tetris::onDestroy() {
  LvglGameBase::onDestroy();
  tetris_all_clear(nullptr);
}

} // namespace BUILTIN_APP
} // namespace MOONCAKE
