/*
 * Copyright (c) 2022 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#include <zmk/display.h>
#include <zmk/event_manager.h>
#include <zmk/events/position_state_changed.h>
#include <zmk/event_manager.h>
#include <zmk/events/ble_active_profile_changed.h>
#include <zmk/events/endpoint_changed.h>
#include <zmk/endpoints.h>

#include "output_status.h"

static sys_slist_t widgets = SYS_SLIST_STATIC_INIT(&widgets);

// Объявления изображений
extern const lv_img_dsc_t first;
extern const lv_img_dsc_t second;
extern const lv_img_dsc_t third;
extern const lv_img_dsc_t fourth;
extern const lv_img_dsc_t fifth;

struct output_status_state {
    struct zmk_endpoint_instance selected_endpoint;
    bool active_profile_connected;
    bool active_profile_bonded;
};

static struct output_status_state get_state(const zmk_event_t *_eh) {
    return (struct output_status_state){.selected_endpoint = zmk_endpoints_selected(),
                                        .active_profile_connected = zmk_ble_active_profile_is_connected(),
                                        .active_profile_bonded = !zmk_ble_active_profile_is_open()};
}

static void set_status_symbol(lv_obj_t *label, struct output_status_state state) {
    char text[10] = {};

    switch (state.selected_endpoint.transport) {
    case ZMK_TRANSPORT_USB:
        strcat(text, LV_SYMBOL_USB);
        break;
    case ZMK_TRANSPORT_BLE:
        if (state.active_profile_bonded) {
            if (state.active_profile_connected) {
                const lv_img_dsc_t *img;
                switch (state.selected_endpoint.ble.profile_index + 1) {
                    case 1: img = &first; break;
                    case 2: img = &second; break;
                    case 3: img = &third; break;
                    case 4: img = &fourth; break;
                    case 5: img = &fifth; break;
                    default: img = &first; // Значение по умолчанию
                }
                lv_img_set_src(label, img);
            } else {
                snprintf(text, sizeof(text), LV_SYMBOL_WIFI " %i " LV_SYMBOL_CLOSE,
                         state.selected_endpoint.ble.profile_index + 1);
            }
        } else {
            snprintf(text, sizeof(text), LV_SYMBOL_WIFI " %i " LV_SYMBOL_SETTINGS,
                     state.selected_endpoint.ble.profile_index + 1);
        }
        break;
    }

    lv_label_set_text(label, text);
}

static void output_status_update_cb(struct output_status_state state) {
    struct zmk_widget_output_status *widget;
    SYS_SLIST_FOR_EACH_CONTAINER(&widgets, widget, node) { set_status_symbol(widget->obj, state); }
}

ZMK_DISPLAY_WIDGET_LISTENER(widget_output_status, struct output_status_state,
                            output_status_update_cb, get_state)
ZMK_SUBSCRIPTION(widget_output_status, zmk_endpoint_changed);
#if defined(CONFIG_ZMK_BLE)
ZMK_SUBSCRIPTION(widget_output_status, zmk_ble_active_profile_changed);
#endif

int zmk_widget_output_status_init(struct zmk_widget_output_status *widget, lv_obj_t *parent) {
    widget->obj = lv_label_create(parent);

    sys_slist_append(&widgets, &widget->node);

    widget_output_status_init();
    return 0;
}

lv_obj_t *zmk_widget_output_status_obj(struct zmk_widget_output_status *widget) {
    return widget->obj;
}
