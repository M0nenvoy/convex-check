#include <algorithm>
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

    for (int i = 1, y = 0; y < pts; i += 2, y++) {
        ipoints[y] = glm::ivec2(
            atoi(argv[i]),
            atoi(argv[i + 1])
        );
    }
    std::stack<glm::ivec2> s = graham_scan(ipoints, pts);

    // Convex points
    int cpts = s.size();
    glm::ivec2 cpoints[cpts];

    for (int i = 0; i < cpts; i++) {
        cpoints[i] = s.top(); s.pop();
    }
    // Draw the convex polygon
    Draw::polygon(img, cpoints, cpts, green);

    // Draw initial points so the effect of the algorithm is
    // more apparent.
    std::for_each(ipoints, ipoints + pts, [&img](auto p) {img.put_pixel(p.x, p.y, red);} );

    bool result = img.write2file(FILENAME);
    if (!result) {
        std::cerr << "Error writing to a file\n";
        return -2;
    }
    return 0;
}
