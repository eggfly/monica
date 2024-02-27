/**
 * @file wf_spring_wreath.h
 * @author Forairaaaaa
 * @brief
 * @version 0.1
 * @date 2023-05-27
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once
#include "../../app/app.h"
#include "../../system_data_def.h"
#include <lvgl.h>

namespace MOONCAKE {
namespace BUILTIN_APP {

namespace SETTINGS_BRIGHTNESS {

struct Data_t {
  /* Update data in 10Hz */
  uint32_t update_interval = 100;
  uint32_t update_count = 0;
  bool running = false;

  bool *just_wake_up_ptr = nullptr;
  bool *key_home_ptr = nullptr;
};

} // namespace SETTINGS_BRIGHTNESS

class SettingsBrightness : public APP_BASE {
private:
  SETTINGS_BRIGHTNESS::Data_t _data;

  static void _lvgl_event_cb(lv_event_t *e);
  void _update_anim();
  void _update_data();
  void _set_anim_index(uint16_t index);

public:
  SettingsBrightness() = default;
  ~SettingsBrightness() = default;

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

} // namespace BUILTIN_APP
} // namespace MOONCAKE
