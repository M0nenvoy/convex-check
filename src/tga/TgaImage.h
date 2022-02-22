#pragma once

#include <cstdint>

using u8    = uint8_t;
using u16   = uint16_t;
using u32   = uint32_t;

#pragma pack(push, 1)

struct  TgaHeader {
    u8  idLength;
    u8  colormap_type;
    u8  image_type;
    u16 colormap_index;
    u16 colormap_len;
    u8  colormap_entry_size;
    u16 xorigin;
    u16 yorigin;
    u16 w; // Width
    u16 h; // Height
    u8  pixel_size;
    u8  image_desc;
};

#pragma pack(pop)

class TgaImage {
    u8*     data;
    int     w;
    int     h;
public:
    TgaImage (int w, int h);
    ~TgaImage();

    inline int get_w () {
        return this->w;
    }
    inline int get_h () {
        return this->h;
    }
    u8 * getData() {
        return data;
    }
    bool write2file (const char* filename);
    void clear();
    u32 get_pixel (int x, int y) {
        int pos = ((h - 1 - y) * w + x) * 3;
        return (uint32_t) data [pos+2] + (((u32)data [pos+1]) << 8) + (((uint32_t)data [pos]) << 16);
    }
    void put_pixel(int x, int y, u32 color) {
        int pos = ((h - 1 - y) * w + x) * 3;
        data [pos]      = (u8) ( (color >> 16) & 0xFF);
        data [pos+1]    = (u8) ( (color >> 8)  & 0xFF);
        data [pos+2]    = (u8) ( (color >> 0)  & 0xFF);
    }
    u32 rgb2int(u32 r, u32 g, u32 b) {
        return r | (g << 8) | (b << 16);
    }
    void set_rgb(const u8 * ptr);
};
