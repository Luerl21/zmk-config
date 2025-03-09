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

#ifndef LV_ATTRIBUTE_IMG_SYNTHLOGO
#define LV_ATTRIBUTE_IMG_SYNTHLOGO
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_SYNTHLOGO uint8_t
    synthlogo_map[] = {
        0xff, 0xff, 0xff, 0xff, /*Color of index 0*/
        0x00, 0x00, 0x00, 0xff, /*Color of index 1*/

        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xc0, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xc0, 0x00, 0x00, 
        0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x40, 0x00, 0x00, 
        0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x01, 0xe0, 0x40, 0x00, 0x00, 
        0x00, 0x0f, 0xc0, 0x00, 0x00, 0x00, 0x3c, 0x30, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 
        0x00, 0x1f, 0xc0, 0x00, 0x00, 0x00, 0x7f, 0xf8, 0x00, 0x00, 0x0c, 0x0f, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x7f, 0xc0, 0x00, 0x00, 0x1f, 0xff, 0xf8, 0x00, 0x00, 0x1e, 0x1e, 0x00, 0x00, 0x03, 0xe0, 
        0x00, 0x7e, 0xc0, 0x00, 0x00, 0x7f, 0xff, 0xf0, 0x00, 0x1c, 0x3e, 0x3c, 0x00, 0x00, 0x07, 0xa0, 
        0x00, 0xf8, 0xc0, 0x00, 0x00, 0xc0, 0x71, 0xf0, 0x00, 0x0c, 0x7e, 0x78, 0x00, 0x00, 0x1e, 0x20, 
        0x01, 0xf1, 0x83, 0x80, 0x00, 0x1c, 0xe1, 0xe2, 0x00, 0x1c, 0x7c, 0x71, 0x80, 0x40, 0x39, 0x00, 
        0x01, 0xc1, 0x03, 0xc0, 0x0e, 0x3c, 0xe3, 0xc7, 0x00, 0x1c, 0xfc, 0xe1, 0xc0, 0x60, 0x73, 0x80, 
        0x01, 0x80, 0x07, 0x80, 0x0e, 0x79, 0xc7, 0x8f, 0x80, 0x1c, 0xfd, 0xc3, 0xf0, 0x70, 0xe7, 0xc0, 
        0x01, 0x9f, 0xc7, 0x06, 0x1e, 0xf9, 0xc7, 0x9f, 0x00, 0x1d, 0xf9, 0xc7, 0xfc, 0xf1, 0xcf, 0xc0, 
        0x01, 0xf8, 0xc7, 0x0e, 0x3f, 0x73, 0xcf, 0x3e, 0x00, 0x39, 0xfb, 0x87, 0x9e, 0xf3, 0x9f, 0xc0, 
        0x00, 0xe0, 0xce, 0x1e, 0x3e, 0xe3, 0x8f, 0x5c, 0x00, 0x3b, 0x7f, 0x8f, 0x3e, 0xe7, 0x1e, 0xc0, 
        0x00, 0x00, 0xce, 0x3e, 0x3e, 0xe3, 0x8e, 0xdc, 0x00, 0x3e, 0x7f, 0x0e, 0x7c, 0xee, 0x3d, 0xd8, 
        0x30, 0x00, 0xcc, 0x7e, 0x7d, 0xe7, 0x1e, 0xb8, 0x00, 0x76, 0xfe, 0x1c, 0xf8, 0xec, 0x3d, 0x90, 
        0x20, 0x01, 0xdc, 0xdc, 0x7d, 0xc7, 0x1d, 0xb8, 0x00, 0x7c, 0xfe, 0x1d, 0xb8, 0xf8, 0x7b, 0x30, 
        0x20, 0x07, 0xd9, 0xbc, 0x79, 0xc7, 0x1f, 0x70, 0x00, 0x7c, 0xfc, 0x3b, 0x71, 0xf8, 0x7e, 0x60, 
        0x30, 0x0f, 0x9b, 0x38, 0x71, 0xc6, 0x1e, 0x70, 0x00, 0xf8, 0xfc, 0x3e, 0x71, 0xf0, 0x7c, 0xc0, 
        0x1c, 0x7f, 0x1e, 0x78, 0x71, 0x86, 0x1e, 0xf0, 0x00, 0x70, 0xf8, 0x3e, 0x61, 0xe0, 0x61, 0x80, 
        0x1f, 0xfe, 0x1e, 0x70, 0x21, 0x8e, 0x1c, 0xe0, 0x00, 0x21, 0xf8, 0x1c, 0x61, 0xe0, 0x67, 0x00, 
        0x0f, 0xf8, 0x1c, 0xe0, 0x01, 0x8c, 0x0c, 0xe0, 0x00, 0x01, 0xf0, 0x18, 0x30, 0xc0, 0x7c, 0x00, 
        0x07, 0xe0, 0x01, 0xe0, 0x01, 0x8c, 0x00, 0xc0, 0x00, 0x01, 0xf0, 0x00, 0x00, 0x00, 0x38, 0x00, 
        0x00, 0x00, 0x03, 0xc0, 0x01, 0x84, 0x00, 0xc0, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x01, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const lv_img_dsc_t synthlogo = {
    .header.always_zero = 0,
    .header.w = 128,
    .header.h = 32,
    .data_size = 512,
    .header.cf = LV_IMG_CF_INDEXED_1BIT,
    .data = synthlogo_map,
};
