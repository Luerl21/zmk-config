/*
 *
 * Copyright (c) 2021 Darryl deHaan
 * SPDX-License-Identifier: MIT
 *
 */
#include "custom_status_screen.h"

#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

LV_IMG_DECLARE(zenlogo);
LV_IMG_DECLARE(layers2);

lv_obj_t *zmk_display_status_screen() {

    lv_obj_t *screen;
    screen = lv_obj_create(NULL);

#if !IS_ENABLED(CONFIG_ZMK_SPLIT_ROLE_CENTRAL)
    lv_obj_t *zenlogo_icon;
    zenlogo_icon = lv_img_create(screen);
    lv_img_set_src(zenlogo_icon, &zenlogo);
    lv_obj_align(zenlogo_icon, LV_ALIGN_BOTTOM_MID, 0, -5);
#endif

    return screen;
}