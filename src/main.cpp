#include <memory.h>
#include <iostream>
#include <cmath>

#include "tga/TgaImage.h"
#include "geometry/line.h"
#include "geometry/polygon.h"
#include "geometry/draw.h"

constexpr u32 blue  = 0x00FF0000;
constexpr u32 red   = 0x000000FF;
constexpr u32 green = 0x0000FF00;
constexpr u32 white = blue & green & red;

constexpr char const* FILENAME = "test.tga";

constexpr int W = 400, H = 300; // Width and height of the image

// Pass points to draw the polygon of.
int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "No points passed\n";
        return -1;
    }
    TgaImage img = TgaImage(W, H);

    int pts = (argc - 1) >> 1;
    glm::ivec2 ipoints[pts];
    glm::vec2  fpoints[pts];

    for (int i = 1, y = 0; y < pts; i += 2, y++) {
        ipoints[y] = glm::ivec2(
            atoi(argv[i]),
            atoi(argv[i + 1])
        );
        fpoints[y] = glm::vec2(
            atof(argv[i]),
            atof(argv[i + 1])
        );
    }

    u32 color = (is_convex(fpoints, pts)) ? green : red;
    Draw::polygon(img, ipoints, pts, color);

    bool result = img.write2file(FILENAME);
    if (!result) {
        std::cerr << "Error writing to a file\n";
        return -2;
    }
    return 0;
}
