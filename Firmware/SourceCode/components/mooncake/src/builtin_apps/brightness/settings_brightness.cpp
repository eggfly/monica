
#include "settings_brightness.h"

#include "../assets/assets.h"
#include "ui.h"
#include <esp_log.h>

namespace MOONCAKE {
namespace BUILTIN_APP {

void SettingsBrightness::_lvgl_event_cb(lv_event_t *e) {
  /* Get event code */
  lv_event_code_t code = lv_event_get_code(e);

  if (code == LV_EVENT_CLICKED) {
  }

/* Quit */
#ifndef ESP_PLATFORM
  else if (code == LV_EVENT_GESTURE) {
    // printf("gesture\n");

    if (lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_BOTTOM) {
      // app->destroyApp();
    }
  }
#endif
}

void SettingsBrightness::_update_anim() {
  /* If pressed key Home */
  if (*_data.key_home_ptr) {
    /* Reset */
    *_data.key_home_ptr = false;

    /* Quit */
    destroyApp();
  }
}

void SettingsBrightness::_update_data() {
  // ESP_LOGI("Brightness", "SettingsBrightness::_update_data");
  int32_t brightness = lv_slider_get_value(ui_Slider2);

  /* Push into database */
  getDatabase()->Put<int32_t>(MC_BRIGHTNESS, brightness);

  /* Set flag */
  getDatabase()->Put<bool>(MC_BRIGHTNESS_JUST_SET, true);

  ESP_LOGI("Brightness", "value=%ld", brightness);
}

void SettingsBrightness::onSetup() {
  setAppName("Brightness");
  setAllowBgRunning(false);
  setAppIcon((void *)&ui_img_sun_108_png);
}

/* Life cycle */
void SettingsBrightness::onCreate() {
  printf("[%s] onCreate\n", getAppName().c_str());

  /* Reset data to default */
  {
    SETTINGS_BRIGHTNESS::Data_t data;
    _data = data;
  }

  /* Get data's pointer from database */
  _data.key_home_ptr = (bool *)getDatabase()->Get(MC_KEY_HOME)->addr;
  /* Reset at first */
  *_data.key_home_ptr = false;
  ui_init();
}

void SettingsBrightness::onResume() {
  printf("[%s] onResume\n", getAppName().c_str());
}

void SettingsBrightness::onRunning() {
  /* Anim */
  _update_anim();

  /* Data */
  if ((lv_tick_get() - _data.update_count) > _data.update_interval) {
    _update_data();
    _data.update_count = lv_tick_get();
  }
}

void SettingsBrightness::onRunningBG() {}

void SettingsBrightness::onPause() {
  printf("[%s] onPause\n", getAppName().c_str());
}

void SettingsBrightness::onDestroy() {
  printf("[%s] onDestroy\n", getAppName().c_str());
}

} // namespace BUILTIN_APP
} // namespace MOONCAKE
