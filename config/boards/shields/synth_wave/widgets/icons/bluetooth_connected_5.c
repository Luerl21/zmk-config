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
#ifndef LV_ATTRIBUTE_IMG_BLUETOOTH_CONNECTED_5
#define LV_ATTRIBUTE_IMG_BLUETOOTH_CONNECTED_5
#endif
const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_IMG_BLUETOOTH_CONNECTED_5 uint8_t
    bluetooth_connected_5_map[] = {
        0xff, 0xff, 0xff, 0xff, /*Color of index 0*/
        0x00, 0x00, 0x00, 0xff, /*Color of index 1*/

        0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x3e, 0x00, 0x30, 0x60, 0x00, 0xc1, 0x80, 0x60, 
        0x30, 0x01, 0x80, 0xc0, 0x40, 0x10, 0x01, 0x30, 0x40, 0x80, 0x08, 0x02, 0x0c, 0x20, 0x8f, 0x88, 
        0x02, 0x02, 0x20, 0x80, 0x08, 0x02, 0x0c, 0x20, 0x8f, 0x88, 0x02, 0x30, 0x20, 0x80, 0x08, 0x02, 
        0x00, 0x20, 0x40, 0x11, 0xf1, 0x3e, 0x40, 0x60, 0x36, 0x0d, 0x80, 0xc0, 0x30, 0x6d, 0xf6, 0xc1, 
        0x80, 0x0f, 0x8b, 0xfa, 0x3e, 0x00, 0x00, 0x17, 0x1d, 0x00, 0x00, 0x00, 0x16, 0x0d, 0x00, 0x00, 
        0x00, 0x16, 0x0d, 0x00, 0x00, 0x00, 0x16, 0x0d, 0x00, 0x00, 0x00, 0x17, 0x1d, 0x00, 0x00, 0x0f, 
        0x8b, 0xfa, 0x3e, 0x00, 0x30, 0x6d, 0xf6, 0xc1, 0x80, 0x60, 0x36, 0x0d, 0x80, 0xc0, 0x40, 0x11, 
        0xf1, 0x00, 0x40, 0x80, 0x08, 0x02, 0x3e, 0x20, 0x80, 0x08, 0x02, 0x00, 0x20, 0x8f, 0x88, 0x02, 
        0x3e, 0x20, 0x80, 0x08, 0x02, 0x00, 0x20, 0x80, 0x08, 0x02, 0x3e, 0x20, 0x40, 0x10, 0x01, 0x00, 
        0x40, 0x60, 0x30, 0x01, 0x80, 0xc0, 0x30, 0x60, 0x00, 0xc1, 0x80, 0x0f, 0x80, 0x00, 0x3e, 0x00
};

const lv_img_dsc_t bluetooth_connected_5 = {
    .header.always_zero = 0,
    .header.w = 35,
    .header.h = 32,
    .data_size = 168,
    .header.cf = LV_IMG_CF_INDEXED_1BIT,
    .data = bluetooth_connected_5_map,
};