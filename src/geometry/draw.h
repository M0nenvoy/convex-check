#include <tga/TgaImage.h>
#include <glm/vec2.hpp>

namespace Draw {
    void line(TgaImage& image, glm::ivec2 a, glm::ivec2 b, u32 color);
    void circle_symmetry(TgaImage& img, glm::ivec2 c, glm::ivec2 p, u32 color);
    void circle(TgaImage& img, glm::vec2 c, int r, u32 color);
    void polygon(TgaImage& img, glm::ivec2 p[], int n, u32 color);
}
