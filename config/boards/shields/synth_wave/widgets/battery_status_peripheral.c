#include <zephyr/kernel.h>
#include <zephyr/bluetooth/services/bas.h>
#include <zephyr/logging/log.h>
#include <zmk/display.h>
#include "battery_status.h"
#include <zmk/usb.h>
#include <zmk/events/usb_conn_state_changed.h>
#include <zmk/event_manager.h>
#include <zmk/events/battery_state_changed.h>
#include <zmk/split/bluetooth/central.h>

LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

static sys_slist_t peripheral_widgets = SYS_SLIST_STATIC_INIT(&peripheral_widgets);

struct zmk_widget_peripheral_battery_status {
    sys_snode_t node;
    lv_obj_t *obj;
};

LV_IMG_DECLARE(batt_100);
LV_IMG_DECLARE(batt_100_chg);
LV_IMG_DECLARE(batt_75);
LV_IMG_DECLARE(batt_75_chg);
LV_IMG_DECLARE(batt_50);
LV_IMG_DECLARE(batt_50_chg);
LV_IMG_DECLARE(batt_25);
LV_IMG_DECLARE(batt_25_chg);
LV_IMG_DECLARE(batt_5);
LV_IMG_DECLARE(batt_5_chg);
LV_IMG_DECLARE(batt_0);
LV_IMG_DECLARE(batt_0_chg);

static void set_peripheral_battery_symbol(lv_obj_t *icon, uint8_t level) {
    if (level > 95) {
        lv_img_set_src(icon, state.usb_present ? &batt_100_chg : &batt_100);
    } else if (level > 74) {
        lv_img_set_src(icon, state.usb_present ? &batt_75_chg : &batt_75);
    } else if (level > 49) {
        lv_img_set_src(icon, state.usb_present ? &batt_50_chg : &batt_50);
    } else if (level > 24) {
        lv_img_set_src(icon, state.usb_present ? &batt_25_chg : &batt_25);
    } else if (level > 5) {
        lv_img_set_src(icon, state.usb_present ? &batt_5_chg : &batt_5);
    } else {
        lv_img_set_src(icon, state.usb_present ? &batt_0_chg : &batt_0);
    }
}

static uint8_t get_peripheral_battery_level() {
    uint8_t peripheral_level = 0;
    zmk_split_get_peripheral_battery_level(0, &peripheral_level);
    return peripheral_level;
}

void peripheral_battery_status_update_cb() {
    uint8_t level = get_peripheral_battery_level();
    struct zmk_widget_peripheral_battery_status *widget;

    SYS_SLIST_FOR_EACH_CONTAINER(&peripheral_widgets, widget, node) {
        set_peripheral_battery_symbol(widget->obj, level);
    }
}

int zmk_widget_peripheral_battery_status_init(struct zmk_widget_peripheral_battery_status *widget, lv_obj_t *parent) {
    widget->obj = lv_img_create(parent);

    sys_slist_append(&peripheral_widgets, &widget->node);

    peripheral_battery_status_update_cb();

    return 0;
}

lv_obj_t *zmk_widget_peripheral_battery_status_obj(struct zmk_widget_peripheral_battery_status *widget) {
    return widget->obj;
}