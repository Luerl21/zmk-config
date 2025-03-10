/*
 *
 * Copyright (c) 2021 Darryl deHaan
 * SPDX-License-Identifier: MIT
 *
 */

#include <lvgl.h>

#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_BATT_0
#define LV_ATTRIBUTE_IMG_BATT_0
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_BATT_0 uint8_t
    batt_0_map[] = {
        0xff, 0xff, 0xff, 0xff, /*Color of index 0*/
        0x00, 0x00, 0x00, 0xff, /*Color of index 1*/

        0x00, 0xe0, 0x00, 0x01, 0xf0, 0x00, 0x01, 0xf0, 0x00, 0xff, 0xff, 0xc0, 0xfc, 0xe7, 0xc0, 0xc0, 
        0xe0, 0xf0, 0xc0, 0xe0, 0x70, 0xc0, 0x40, 0x30, 0xc0, 0x40, 0x70, 0xc0, 0x40, 0xf0, 0xff, 0x1f, 
        0xe0, 0xfe, 0xef, 0xc0, 0x01, 0xf0, 0x00, 0x01, 0xf0, 0x00, 0x00, 0xe0, 0x00
};

const lv_img_dsc_t batt_0 = {
    .header.always_zero = 0,
    .header.w = 20,
    .header.h = 15,
    .data_size = 53,
    .header.cf = LV_IMG_CF_INDEXED_1BIT,
    .data = batt_0_map,
};
