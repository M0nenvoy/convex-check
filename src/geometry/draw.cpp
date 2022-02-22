#include "draw.h"

#include <cmath>

namespace Draw {
void line(TgaImage& image, glm::ivec2 a, glm::ivec2 b, u32 color) {
    const int xa = a.x;
    const int ya = a.y;
    const int yb = b.y;
    const int xb = b.x;

    const int dx = abs(b.x - a.x);
    const int dy = abs(b.y - a.y);
    const int sy = (b.y >= a.y) ? 1 : -1;
    const int sx = (b.x >= a.x) ? 1 : -1;

    image.put_pixel(xa, ya, color);

    if (dx >= dy) {
        int d = (dy << 1) - dx;
        int y = ya;

        for (int x = xa; x != xb; x += sx) {
            d += (dy << 1);
            y += (d > 0) * sy;
            d -= (d > 0) * (dx << 1);
            image.put_pixel(x, y, color);
        }
        return;
    }

    int d = (dx << 1) - dy;
    int x = xa;

    for (int y = ya; y != yb; y += sy) {
        d += (dx << 1);
        x += (d > 0) * sx;
        d -= (d > 0) * (dy << 1);
        image.put_pixel(x, y, color);
    }
}

void circle_symmetry(TgaImage& img, glm::ivec2 c, int x, int y, u32 color) {
    img.put_pixel( x + c.x,  y + c.y, color);
    img.put_pixel(-x + c.x, -y + c.y, color);
    img.put_pixel(-x + c.x,  y + c.y, color);
    img.put_pixel( x + c.x, -y + c.y, color);
    img.put_pixel( y + c.x, -x + c.y, color);
    img.put_pixel( y + c.x,  x + c.y, color);
    img.put_pixel(-y + c.x, -x + c.y, color);
    img.put_pixel(-y + c.x,  x + c.y, color);
}
void circle(TgaImage& img, glm::ivec2 c, int r, u32 color) {
    int x = 0;
    int y = r;
    int d = 1 - r;

    circle_symmetry(img, c, x, y, color);
    while (y > x) {
        if (d < 0)
            d += 2*x + 3;
        else
            d += 2 * (x - y--) + 5;
        x++;
        circle_symmetry(img, c, x, y, color);
    }
}
void polygon(TgaImage& img, glm::ivec2 p[], int n, u32 color) {
    glm::ivec2 prev = p[n - 1];
    for (int i = 0; i < n; i++) {
        line(img, p[i], prev, color);
        prev = p[i];
    }
}

}
