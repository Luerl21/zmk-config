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

#ifndef LV_ATTRIBUTE_IMG_LAYERS
#define LV_ATTRIBUTE_IMG_LAYERS
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_LAYERS uint8_t
    layers_map[] = {
        0xff, 0xff, 0xff, 0xff, /*Color of index 0*/
        0x00, 0x00, 0x00, 0xff, /*Color of index 1*/

        0x00, 0x00, 0x03, 0xc0, 0x07, 0xe0, 0x3f, 0xfc, 0x7f, 0xfe, 0x3f, 0xfc, 0x37, 0xec, 0x63, 0xc6, 
        0x60, 0x06, 0x18, 0x18, 0x3e, 0x7c, 0x7f, 0xfe, 0x3f, 0xfc, 0x03, 0xe0, 0x03, 0xc0, 0x00, 0x00
};

const lv_img_dsc_t layers = {
    .header.always_zero = 0,
    .header.w = 16,
    .header.h = 16,
    .data_size = 32,
    .header.cf = LV_IMG_CF_INDEXED_1BIT,
    .data = layers_map,
};
