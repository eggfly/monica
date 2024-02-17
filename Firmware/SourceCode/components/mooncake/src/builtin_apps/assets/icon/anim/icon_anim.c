
#include "icon_anim.h"
#include <esp_log.h>

#define SPRING_WREATH_SIZE 395280

lv_img_dsc_t anim_spring_wreath_raw[NUM_ANIM_SPRING_WREATH];


void init_anim_spring_wreath_dsc(const void *addr)
{
    uint8_t *offset = (uint8_t *)addr;
    for (uint16_t i = 0; i < NUM_ANIM_SPRING_WREATH; i++)
    {
        lv_memset_00(&anim_spring_wreath_raw[i], sizeof(lv_img_dsc_t));
        anim_spring_wreath_raw[i].header.always_zero = 0;
        anim_spring_wreath_raw[i].header.w = 366;
        anim_spring_wreath_raw[i].header.h = 360;
        anim_spring_wreath_raw[i].header.cf = LV_IMG_CF_TRUE_COLOR_ALPHA;
        anim_spring_wreath_raw[i].data_size = SPRING_WREATH_SIZE;
        anim_spring_wreath_raw[i].data = offset + i * SPRING_WREATH_SIZE;
        // ESP_LOGI("anim", "set data to -> 0x%p", anim_spring_wreath_raw[i].data);
    }
}
