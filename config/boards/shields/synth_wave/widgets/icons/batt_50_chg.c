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

#ifndef LV_ATTRIBUTE_IMG_BATT_50_CHG
#define LV_ATTRIBUTE_IMG_BATT_50_CHG
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_BATT_50_CHG uint8_t
    batt_50_chg_map[] = {
        0xff, 0xff, 0xff, 0xff, /*Color of index 0*/
        0x00, 0x00, 0x00, 0xff, /*Color of index 1*/

        0x00, 0x08, 0x00, 0x00, 0x18, 0x00, 0x00, 0x38, 0x00, 0xff, 0xff, 0xc0, 0xff, 0xf7, 0xc0, 0xdd, 
        0xe0, 0xf0, 0xdf, 0xe0, 0x70, 0xdf, 0xf0, 0x30, 0xd8, 0xe0, 0x70, 0xc0, 0xc0, 0xf0, 0xff, 0xbf, 
        0xe0, 0xff, 0x7f, 0xc0, 0x03, 0x00, 0x00, 0x02, 0x00, 0x00, 0x04, 0x00, 0x00
};

const lv_img_dsc_t batt_50_chg = {
    .header.always_zero = 0,
    .header.w = 20,
    .header.h = 15,
    .data_size = 53,
    .header.cf = LV_IMG_CF_INDEXED_1BIT,
    .data = batt_50_chg_map,
};