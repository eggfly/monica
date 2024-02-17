
#include "icon_anim.h"
#include <esp_log.h>

#define SPRING_WREATH_SIZE  395280
#define WALKING_SIZE        44982

lv_img_dsc_t anim_spring_wreath_raw[NUM_ANIM_SPRING_WREATH];

lv_img_dsc_t anim_lc_walking_raw[NUM_ANIM_LC_WALKING];

lv_img_dsc_t *anim_lc_walking_ptrs[NUM_ANIM_LC_WALKING];


void init_anim_spring_wreath_dsc(const void *addr)
{
    uint8_t *offset = (uint8_t *)addr;
    for (uint16_t i = 0; i < NUM_ANIM_SPRING_WREATH; i++)
    {
        anim_spring_wreath_raw[i].header.always_zero = 0;
        anim_spring_wreath_raw[i].header.w = 366;
        anim_spring_wreath_raw[i].header.h = 360;
        anim_spring_wreath_raw[i].header.cf = LV_IMG_CF_TRUE_COLOR_ALPHA;
        anim_spring_wreath_raw[i].data_size = SPRING_WREATH_SIZE;
        anim_spring_wreath_raw[i].data = offset + i * SPRING_WREATH_SIZE;
    }
}

void init_anim_lc_walking_dsc_and_ptrs(const void *addr)
{
    uint8_t *offset = (uint8_t *)addr;
    for (uint16_t i = 0; i < NUM_ANIM_LC_WALKING; i++)
    {
        anim_lc_walking_raw[i].header.always_zero = 0;
        anim_lc_walking_raw[i].header.w = 102;
        anim_lc_walking_raw[i].header.h = 147;
        anim_lc_walking_raw[i].header.cf = LV_IMG_CF_TRUE_COLOR_ALPHA;
        anim_lc_walking_raw[i].data_size = WALKING_SIZE;
        anim_lc_walking_raw[i].data = offset + i * WALKING_SIZE;
        anim_lc_walking_ptrs[i] = &anim_lc_walking_raw[i];
    }
}
