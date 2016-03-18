#ifndef UTIL_H
#define UTIL_H

#include "../types.h"

typedef enum {
    RGB565,
    RGBA4444
} PixelFormat;

void utf8_to_utf16(u16* dst, const char* src, size_t max_len);
u16 pack_color(u8 r, u8 g, u8 b, u8 a, PixelFormat format);
u8* load_image(const char* image, u32 width, u32 height);
u16* image_data_to_tiles(u8* img, u32 width, u32 height, PixelFormat format, u32* size);
u16* image_to_tiles(const char* image, u32 width, u32 height, PixelFormat format, u32* size);

#endif