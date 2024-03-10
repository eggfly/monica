/**
 * @brief
 * @version 0.1
 * @date 2023-05-28
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once
#include "../../app/app.h"
#include "../../system_data_def.h"
#include <iostream>
#include <lvgl.h>
#include <string>
#include <vector>

namespace MOONCAKE {
namespace BUILTIN_APP {

namespace LV_GAME_BASE {

struct Data_t {
  /* Update data in 1Hz */
  uint32_t update_interval = 1000;
  uint32_t update_count = 0;
  bool running = false;

  DataTime_t *time_ptr = nullptr;
  bool *just_wake_up_ptr = nullptr;
  bool *key_home_ptr = nullptr;
};

} // namespace LV_GAME_BASE

class LvglGameBase : public APP_BASE {
private:
  LV_GAME_BASE::Data_t _data;

  static void _lvgl_event_cb(lv_event_t *e);
  void _update_data();

public:
  LvglGameBase() = default;
  ~LvglGameBase() = default;

  virtual void onSetup() override;

  /* Life cycle */
  virtual void onCreate() override;
  virtual void onResume() override;
  virtual void onRunning() override;
  virtual void onRunningBG() override;
  virtual void onPause() override;
  virtual void onDestroy() override;
};

} // namespace BUILTIN_APP
} // namespace MOONCAKE
