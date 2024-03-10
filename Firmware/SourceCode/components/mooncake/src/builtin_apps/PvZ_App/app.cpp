
#include "app.h"
#include "../assets/assets.h"
#include <ArduinoJson.hpp>

#include <lvgl.h>

/* If not include this, lv_fs acts strange in my wsl linux env */
#include <esp_system.h>
#include <stdio.h>
#include <stdlib.h>

extern "C" {
void pvz_start();
void exit_game_cb(lv_event_t *e);
}

namespace MOONCAKE {
namespace BUILTIN_APP {

void PvZ::onSetup() {
  setAppName("Plants vs Zombies");
  setAllowBgRunning(false);
  setAppIcon((void *)&ui_img_pvz_108_png);
}

void PvZ::onCreate() {
  LvglGameBase::onCreate();
  // eggfly
  lv_disp_set_rotation(NULL, LV_DISP_ROT_270);
  pvz_start();
}
void PvZ::onDestroy() {
  LvglGameBase::onDestroy();
  exit_game_cb(nullptr);
  lv_disp_set_rotation(NULL, LV_DISP_ROT_NONE);
}

} // namespace BUILTIN_APP
} // namespace MOONCAKE
