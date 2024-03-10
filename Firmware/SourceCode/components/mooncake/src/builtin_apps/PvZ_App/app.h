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
#include "../lvgl_game_base/lv_game_base.h"
#include <iostream>
#include <lvgl.h>
#include <string>
#include <vector>

namespace MOONCAKE {
namespace BUILTIN_APP {

class PvZ : public LvglGameBase {

public:
  PvZ() = default;
  ~PvZ() = default;

  void onSetup();

  /* Life cycle */
  virtual void onCreate() override;
  virtual void onDestroy() override;
};

} // namespace BUILTIN_APP
} // namespace MOONCAKE
