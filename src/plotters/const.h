#include <iostream>

#include "tga/TgaImage.h"
#include "geometry/line.h"
#include "geometry/polygon.h"
#include "geometry/draw.h"

constexpr u32 blue  = 0x00FF0000;
constexpr u32 red   = 0x000000FF;
constexpr u32 green = 0x0000FF00;
constexpr u32 white = blue | green | red;

constexpr char const* FILENAME = "test.tga";

constexpr int W = 400, H = 300; // Width and height of the image
