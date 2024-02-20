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


#define SPEED_UP_FLASH_WHILE_DEV    0

/* Walking anim, thanks to Bashir Ahmed */
/* https://lottiefiles.com/directdesign22 */
LV_IMG_DECLARE(ui_img_icon_lc_walking_00);
LV_IMG_DECLARE(ui_img_icon_lc_walking_01);
LV_IMG_DECLARE(ui_img_icon_lc_walking_02);
LV_IMG_DECLARE(ui_img_icon_lc_walking_03);
LV_IMG_DECLARE(ui_img_icon_lc_walking_04);
LV_IMG_DECLARE(ui_img_icon_lc_walking_05);
LV_IMG_DECLARE(ui_img_icon_lc_walking_06);
LV_IMG_DECLARE(ui_img_icon_lc_walking_07);
LV_IMG_DECLARE(ui_img_icon_lc_walking_08);
LV_IMG_DECLARE(ui_img_icon_lc_walking_09);
LV_IMG_DECLARE(ui_img_icon_lc_walking_10);
LV_IMG_DECLARE(ui_img_icon_lc_walking_11);
LV_IMG_DECLARE(ui_img_icon_lc_walking_12);
LV_IMG_DECLARE(ui_img_icon_lc_walking_13);
LV_IMG_DECLARE(ui_img_icon_lc_walking_14);
LV_IMG_DECLARE(ui_img_icon_lc_walking_15);
LV_IMG_DECLARE(ui_img_icon_lc_walking_16);
LV_IMG_DECLARE(ui_img_icon_lc_walking_17);
LV_IMG_DECLARE(ui_img_icon_lc_walking_18);
LV_IMG_DECLARE(ui_img_icon_lc_walking_19);
LV_IMG_DECLARE(ui_img_icon_lc_walking_20);
LV_IMG_DECLARE(ui_img_icon_lc_walking_21);
LV_IMG_DECLARE(ui_img_icon_lc_walking_22);
LV_IMG_DECLARE(ui_img_icon_lc_walking_23);
LV_IMG_DECLARE(ui_img_icon_lc_walking_24);
LV_IMG_DECLARE(ui_img_icon_lc_walking_25);
LV_IMG_DECLARE(ui_img_icon_lc_walking_26);
LV_IMG_DECLARE(ui_img_icon_lc_walking_27);
LV_IMG_DECLARE(ui_img_icon_lc_walking_28);
LV_IMG_DECLARE(ui_img_icon_lc_walking_29);
LV_IMG_DECLARE(ui_img_icon_lc_walking_30);

static const lv_img_dsc_t *anim_lc_walking[] = {
    &ui_img_icon_lc_walking_00,
    &ui_img_icon_lc_walking_01,
    &ui_img_icon_lc_walking_02,
    &ui_img_icon_lc_walking_03,
    &ui_img_icon_lc_walking_04,
    &ui_img_icon_lc_walking_05,
    &ui_img_icon_lc_walking_06,
    &ui_img_icon_lc_walking_07,
    &ui_img_icon_lc_walking_08,
    &ui_img_icon_lc_walking_09,
    &ui_img_icon_lc_walking_10,
    &ui_img_icon_lc_walking_11,
    &ui_img_icon_lc_walking_12,
    &ui_img_icon_lc_walking_13,
    &ui_img_icon_lc_walking_14,
    &ui_img_icon_lc_walking_15,
    &ui_img_icon_lc_walking_16,
    &ui_img_icon_lc_walking_17,
    &ui_img_icon_lc_walking_18,
    &ui_img_icon_lc_walking_19,
    &ui_img_icon_lc_walking_20,
    &ui_img_icon_lc_walking_21,
    &ui_img_icon_lc_walking_22,
    &ui_img_icon_lc_walking_23,
    &ui_img_icon_lc_walking_24,
    &ui_img_icon_lc_walking_25,
    &ui_img_icon_lc_walking_26,
    &ui_img_icon_lc_walking_27,
    &ui_img_icon_lc_walking_28,
    &ui_img_icon_lc_walking_29,
    &ui_img_icon_lc_walking_30,
};

#define NUM_ANIM_LC_WALKING 31

LV_IMG_DECLARE(ui_img_anim_spring_wreath_99);

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
