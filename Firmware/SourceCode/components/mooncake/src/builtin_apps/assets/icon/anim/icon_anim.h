/**
 * @file launcher_icon.h
 * @author Forairaaaaa
 * @brief
 * @version 0.1
 * @date 2023-05-15
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once

/*! CPP guard */
#ifdef __cplusplus
extern "C" {
#endif

#include <lvgl.h>
#include "local_def.h"

/* Walking anim, thanks to Bashir Ahmed */
/* https://lottiefiles.com/directdesign22 */
LV_IMG_DECLARE(ui_img_icon_lc_walking_00_png);
LV_IMG_DECLARE(ui_img_icon_lc_walking_01_png);
LV_IMG_DECLARE(ui_img_icon_lc_walking_02_png);
LV_IMG_DECLARE(ui_img_icon_lc_walking_03_png);
LV_IMG_DECLARE(ui_img_icon_lc_walking_04_png);
LV_IMG_DECLARE(ui_img_icon_lc_walking_05_png);
LV_IMG_DECLARE(ui_img_icon_lc_walking_06_png);
LV_IMG_DECLARE(ui_img_icon_lc_walking_07_png);
LV_IMG_DECLARE(ui_img_icon_lc_walking_08_png);
LV_IMG_DECLARE(ui_img_icon_lc_walking_09_png);
LV_IMG_DECLARE(ui_img_icon_lc_walking_10_png);
LV_IMG_DECLARE(ui_img_icon_lc_walking_11_png);
LV_IMG_DECLARE(ui_img_icon_lc_walking_12_png);
LV_IMG_DECLARE(ui_img_icon_lc_walking_13_png);
LV_IMG_DECLARE(ui_img_icon_lc_walking_14_png);
LV_IMG_DECLARE(ui_img_icon_lc_walking_15_png);
LV_IMG_DECLARE(ui_img_icon_lc_walking_16_png);
LV_IMG_DECLARE(ui_img_icon_lc_walking_17_png);
LV_IMG_DECLARE(ui_img_icon_lc_walking_18_png);
LV_IMG_DECLARE(ui_img_icon_lc_walking_19_png);
LV_IMG_DECLARE(ui_img_icon_lc_walking_20_png);
LV_IMG_DECLARE(ui_img_icon_lc_walking_21_png);
LV_IMG_DECLARE(ui_img_icon_lc_walking_22_png);
LV_IMG_DECLARE(ui_img_icon_lc_walking_23_png);
LV_IMG_DECLARE(ui_img_icon_lc_walking_24_png);
LV_IMG_DECLARE(ui_img_icon_lc_walking_25_png);
LV_IMG_DECLARE(ui_img_icon_lc_walking_26_png);
LV_IMG_DECLARE(ui_img_icon_lc_walking_27_png);
LV_IMG_DECLARE(ui_img_icon_lc_walking_28_png);
LV_IMG_DECLARE(ui_img_icon_lc_walking_29_png);
LV_IMG_DECLARE(ui_img_icon_lc_walking_30_png);

static const lv_img_dsc_t *anim_lc_walking[] = {
    &ui_img_icon_lc_walking_00_png,
    &ui_img_icon_lc_walking_01_png,
    &ui_img_icon_lc_walking_02_png,
    &ui_img_icon_lc_walking_03_png,
    &ui_img_icon_lc_walking_04_png,
    &ui_img_icon_lc_walking_05_png,
    &ui_img_icon_lc_walking_06_png,
    &ui_img_icon_lc_walking_07_png,
    &ui_img_icon_lc_walking_08_png,
    &ui_img_icon_lc_walking_09_png,
    &ui_img_icon_lc_walking_10_png,
    &ui_img_icon_lc_walking_11_png,
    &ui_img_icon_lc_walking_12_png,
    &ui_img_icon_lc_walking_13_png,
    &ui_img_icon_lc_walking_14_png,
    &ui_img_icon_lc_walking_15_png,
    &ui_img_icon_lc_walking_16_png,
    &ui_img_icon_lc_walking_17_png,
    &ui_img_icon_lc_walking_18_png,
    &ui_img_icon_lc_walking_19_png,
    &ui_img_icon_lc_walking_20_png,
    &ui_img_icon_lc_walking_21_png,
    &ui_img_icon_lc_walking_22_png,
    &ui_img_icon_lc_walking_23_png,
    &ui_img_icon_lc_walking_24_png,
    &ui_img_icon_lc_walking_25_png,
    &ui_img_icon_lc_walking_26_png,
    &ui_img_icon_lc_walking_27_png,
    &ui_img_icon_lc_walking_28_png,
    &ui_img_icon_lc_walking_29_png,
    &ui_img_icon_lc_walking_30_png,
};

#define NUM_ANIM_LC_WALKING 31

LV_IMG_DECLARE(ui_img_anim_spring_wreath_00);  // assets\anim_spring_wreath_0.png
LV_IMG_DECLARE(ui_img_anim_spring_wreath_01);  // assets\anim_spring_wreath_1.png
LV_IMG_DECLARE(ui_img_anim_spring_wreath_02);  // assets\anim_spring_wreath_2.png
LV_IMG_DECLARE(ui_img_anim_spring_wreath_03);  // assets\anim_spring_wreath_3.png
LV_IMG_DECLARE(ui_img_anim_spring_wreath_04);  // assets\anim_spring_wreath_4.png
LV_IMG_DECLARE(ui_img_anim_spring_wreath_05);  // assets\anim_spring_wreath_5.png
LV_IMG_DECLARE(ui_img_anim_spring_wreath_06);  // assets\anim_spring_wreath_6.png
LV_IMG_DECLARE(ui_img_anim_spring_wreath_07);  // assets\anim_spring_wreath_7.png
LV_IMG_DECLARE(ui_img_anim_spring_wreath_08);  // assets\anim_spring_wreath_8.png
LV_IMG_DECLARE(ui_img_anim_spring_wreath_09);  // assets\anim_spring_wreath_9.png
LV_IMG_DECLARE(ui_img_anim_spring_wreath_10); // assets\anim_spring_wreath_10.png
LV_IMG_DECLARE(ui_img_anim_spring_wreath_11); // assets\anim_spring_wreath_11.png
LV_IMG_DECLARE(ui_img_anim_spring_wreath_12); // assets\anim_spring_wreath_12.png
LV_IMG_DECLARE(ui_img_anim_spring_wreath_13); // assets\anim_spring_wreath_13.png
LV_IMG_DECLARE(ui_img_anim_spring_wreath_14); // assets\anim_spring_wreath_14.png
LV_IMG_DECLARE(ui_img_anim_spring_wreath_15); // assets\anim_spring_wreath_15.png
LV_IMG_DECLARE(ui_img_anim_spring_wreath_16); // assets\anim_spring_wreath_16.png
LV_IMG_DECLARE(ui_img_anim_spring_wreath_17); // assets\anim_spring_wreath_17.png
LV_IMG_DECLARE(ui_img_anim_spring_wreath_18); // assets\anim_spring_wreath_18.png
LV_IMG_DECLARE(ui_img_anim_spring_wreath_19); // assets\anim_spring_wreath_19.png
LV_IMG_DECLARE(ui_img_anim_spring_wreath_20); // assets\anim_spring_wreath_20.png
LV_IMG_DECLARE(ui_img_anim_spring_wreath_21); // assets\anim_spring_wreath_21.png
LV_IMG_DECLARE(ui_img_anim_spring_wreath_22); // assets\anim_spring_wreath_22.png
LV_IMG_DECLARE(ui_img_anim_spring_wreath_23); // assets\anim_spring_wreath_23.png
LV_IMG_DECLARE(ui_img_anim_spring_wreath_24); // assets\anim_spring_wreath_24.png
LV_IMG_DECLARE(ui_img_anim_spring_wreath_25); // assets\anim_spring_wreath_25.png
LV_IMG_DECLARE(ui_img_anim_spring_wreath_26); // assets\anim_spring_wreath_26.png

static const lv_img_dsc_t *anim_spring_wreath[] = {
    &ui_img_anim_spring_wreath_00,
    &ui_img_anim_spring_wreath_01,
#if SPEED_UP_FLASH_WHILE_DEV == 0
    &ui_img_anim_spring_wreath_02,
    &ui_img_anim_spring_wreath_03,
    &ui_img_anim_spring_wreath_04,
    &ui_img_anim_spring_wreath_05,
    &ui_img_anim_spring_wreath_06,
    &ui_img_anim_spring_wreath_07,
    &ui_img_anim_spring_wreath_08,
    &ui_img_anim_spring_wreath_09,
    &ui_img_anim_spring_wreath_10,
    &ui_img_anim_spring_wreath_11,
    &ui_img_anim_spring_wreath_12,
    &ui_img_anim_spring_wreath_13,
    &ui_img_anim_spring_wreath_14,
    &ui_img_anim_spring_wreath_15,
    &ui_img_anim_spring_wreath_16,
    &ui_img_anim_spring_wreath_17,
    &ui_img_anim_spring_wreath_18,
    &ui_img_anim_spring_wreath_19,
    &ui_img_anim_spring_wreath_20,
    &ui_img_anim_spring_wreath_21,
    &ui_img_anim_spring_wreath_22,
    &ui_img_anim_spring_wreath_23,
    &ui_img_anim_spring_wreath_24,
    &ui_img_anim_spring_wreath_25,
    &ui_img_anim_spring_wreath_26,
#endif
};

// eggfly
#if SPEED_UP_FLASH_WHILE_DEV == 0
#define NUM_ANIM_SPRING_WREATH 27
#else 
#define NUM_ANIM_SPRING_WREATH 2
#endif

extern lv_img_dsc_t anim_spring_wreath_raw[NUM_ANIM_SPRING_WREATH];

extern lv_img_dsc_t anim_lc_walking_raw[NUM_ANIM_LC_WALKING];
extern lv_img_dsc_t *anim_lc_walking_ptrs[NUM_ANIM_LC_WALKING];

void init_anim_spring_wreath_dsc(const void * addr);

void init_anim_lc_walking_dsc_and_ptrs(const void * addr);

#ifdef __cplusplus
}
#endif /* End of CPP guard */
