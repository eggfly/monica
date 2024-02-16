// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.3.4
// Project name: Smartwatch

#include "../ui.h"


// COMPONENT batterygroup

lv_obj_t *ui_batterygroup_create(lv_obj_t *comp_parent) {

lv_obj_t *cui_batterygroup;
cui_batterygroup = lv_obj_create(comp_parent);
lv_obj_set_width( cui_batterygroup, 77);
lv_obj_set_height( cui_batterygroup, 22);
lv_obj_set_x( cui_batterygroup, 0 );
lv_obj_set_y( cui_batterygroup, 20 );
lv_obj_set_align( cui_batterygroup, LV_ALIGN_TOP_MID );
lv_obj_set_flex_flow(cui_batterygroup,LV_FLEX_FLOW_ROW);
lv_obj_set_flex_align(cui_batterygroup, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
lv_obj_clear_flag( cui_batterygroup, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(cui_batterygroup, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(cui_batterygroup, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_row(cui_batterygroup, 6, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_column(cui_batterygroup, 8, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_t *cui_flash;
cui_flash = lv_img_create(cui_batterygroup);
lv_img_set_src(cui_flash, &ui_img_flash_png);
lv_obj_set_width( cui_flash, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( cui_flash, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( cui_flash, LV_ALIGN_CENTER );
lv_obj_add_flag( cui_flash, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( cui_flash, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

lv_obj_t *cui_battery_percent;
cui_battery_percent = lv_label_create(cui_batterygroup);
lv_obj_set_width( cui_battery_percent, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( cui_battery_percent, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( cui_battery_percent, LV_ALIGN_CENTER );
lv_label_set_text(cui_battery_percent,"86%");
lv_obj_set_style_text_color(cui_battery_percent, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(cui_battery_percent, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(cui_battery_percent, &ui_font_Title, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_BATTERYGROUP_NUM);
children[UI_COMP_BATTERYGROUP_BATTERYGROUP] = cui_batterygroup;
children[UI_COMP_BATTERYGROUP_FLASH] = cui_flash;
children[UI_COMP_BATTERYGROUP_BATTERY_PERCENT] = cui_battery_percent;
lv_obj_add_event_cb(cui_batterygroup, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
lv_obj_add_event_cb(cui_batterygroup, del_component_child_event_cb, LV_EVENT_DELETE, children);
ui_comp_batterygroup_create_hook(cui_batterygroup);
return cui_batterygroup; 
}

