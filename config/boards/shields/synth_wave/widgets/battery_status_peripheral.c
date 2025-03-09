#include <zephyr/kernel.h>
#include <zephyr/bluetooth/services/bas.h>
#include <zephyr/logging/log.h>
#include <zmk/display.h>
#include <zmk/usb.h>
#include <zmk/events/usb_conn_state_changed.h>
#include <zmk/event_manager.h>
#include <zmk/events/battery_state_changed.h>
#include <zmk/split/bluetooth/central.h>
#include "battery_status_peripheral.h"

LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

static sys_slist_t peripheral_widgets = SYS_SLIST_STATIC_INIT(&peripheral_widgets);

LV_IMG_DECLARE(batt_100);
LV_IMG_DECLARE(batt_75);
LV_IMG_DECLARE(batt_50);
LV_IMG_DECLARE(batt_25);
LV_IMG_DECLARE(batt_5);
LV_IMG_DECLARE(batt_0);

LV_IMG_DECLARE(batt_50_chg);

static void set_peripheral_battery_symbol(lv_obj_t *icon, uint8_t level) {
    // if (level == 1) {
    //     lv_img_set_src(icon, &batt_50_chg);
    // } else 
    if (level > 95) {
        lv_img_set_src(icon, &batt_100);
    } else if (level > 74) {
        lv_img_set_src(icon, &batt_75);
    } else if (level > 49) {
        lv_img_set_src(icon, &batt_50);
    } else if (level > 24) {
        lv_img_set_src(icon, &batt_25);
    } else if (level > 5) {
        lv_img_set_src(icon, &batt_5);
    } else {
        lv_img_set_src(icon, &batt_0);
    }
}

void handle_peripheral_battery_state_changed(const zmk_event_t *event) {
    const struct zmk_peripheral_battery_state_changed *ev = as_zmk_peripheral_battery_state_changed(event);
    uint8_t level = ev->state_of_charge;
    struct zmk_widget_peripheral_battery_status *widget;

    SYS_SLIST_FOR_EACH_CONTAINER(&peripheral_widgets, widget, node) {
        set_peripheral_battery_symbol(widget->obj, level);
    }
}

ZMK_LISTENER(peripheral_battery_listener, handle_peripheral_battery_state_changed);
ZMK_SUBSCRIPTION(peripheral_battery_listener, zmk_peripheral_battery_state_changed);

int zmk_widget_peripheral_battery_status_init(struct zmk_widget_peripheral_battery_status *widget, lv_obj_t *parent) {
    widget->obj = lv_img_create(parent);

    sys_slist_append(&peripheral_widgets, &widget->node);
    return 0;
}

lv_obj_t *zmk_widget_peripheral_battery_status_obj(struct zmk_widget_peripheral_battery_status *widget) {
    return widget->obj;
}