#include "polygon.h"

bool is_convex(const glm::vec2 p[], int n) {
    int previ = n - 1;
    glm::vec2 prev = p[previ];
    glm::vec2 cur, edge;
    for (int i = 0; i < n; i++) {
        cur = p[i];
        edge = cur - prev;
        int nclass = 0, pclass = 0;
        for (int y = 0; y < n; y++) {
            if (y == i || y == previ) continue;
            nclass = classify(p[y], prev, cur);
            if (nclass != pclass & pclass != 0) return false;
            pclass = nclass;
        }
        prev = cur;
        previ = i;
    }
    return true;
}
