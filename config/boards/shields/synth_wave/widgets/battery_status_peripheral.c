/*
 *
 * Copyright (c) 2021 Darryl deHaan
 * SPDX-License-Identifier: MIT
 *
 */

#include <zephyr/kernel.h>
#include <zephyr/bluetooth/services/bas.h>

#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#include <zmk/display.h>
#include "battery_status.h"
#include <zmk/usb.h>
#include <zmk/events/usb_conn_state_changed.h>
#include <zmk/event_manager.h>
#include <zmk/events/battery_state_changed.h>

static sys_slist_t widgets = SYS_SLIST_STATIC_INIT(&widgets);

struct battery_status_state {
    uint8_t level;
#if IS_ENABLED(CONFIG_USB_DEVICE_STACK)
    bool usb_present;
#endif
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

static void set_battery_symbol(lv_obj_t *icon, struct battery_status_state state) {
    uint8_t peripheral_level = 0;

    zmk_split_get_peripheral_battery_level(0, &peripheral_level);

    if (peripheral_level > 95) {
        lv_img_set_src(icon, &batt_100);
    } else if (peripheral_level > 74) {
        lv_img_set_src(icon, &batt_75);
    } else if (peripheral_level > 49) {
        lv_img_set_src(icon, &batt_50);
    } else if (peripheral_level > 24) {
        lv_img_set_src(icon, &batt_25);
    } else if (peripheral_level > 5) {
        lv_img_set_src(icon, &batt_5);
    } else {
        lv_img_set_src(icon, &batt_0);
    }
}

void battery_status_peripheral_update_cb(struct battery_status_peripheral_state state) {
    struct zmk_widget_battery_status_peripheral *widget;
    SYS_SLIST_FOR_EACH_CONTAINER(&widgets, widget, node) { set_battery_peripheral_symbol(widget->obj, state); }
}

ZMK_DISPLAY_WIDGET_LISTENER(widget_battery_status_peripheral, struct battery_status_peripheral_state,
                            battery_status_peripheral_update_cb, battery_status_peripheral_get_state)

int zmk_widget_battery_status_peripheral_init(struct zmk_widget_battery_status_peripheral *widget, lv_obj_t *parent) {
    widget->obj = lv_img_create(parent);

    sys_slist_append(&widgets, &widget->node);
    widget_battery_status_peripheral_init();

    return 0;
}

lv_obj_t *zmk_widget_battery_status_peripheral_obj(struct zmk_widget_battery_status_peripheral *widget) {
    return widget->obj;
}
