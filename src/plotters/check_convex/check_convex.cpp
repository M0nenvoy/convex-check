#include <plotters/const.h>

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
