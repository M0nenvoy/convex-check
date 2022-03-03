#include "polygon.h"
#include <algorithm>

glm::ivec2 p0;

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

enum Orientation {
    COLLINEAER,
    CW,
    CCW
};

glm::ivec2 next2top(std::stack<glm::ivec2>& s) {
    glm::ivec2 top  = s.top();
    s.pop();
    glm::ivec2 next = s.top();

    s.push( top );
    return next;
}


int orientation(glm::ivec2 p0, glm::ivec2 p1, glm::ivec2 p2) {
    glm::ivec2 p01 = p0 - p1;
    glm::ivec2 p02 = p0 - p2;

    // Z-coordinate of the crossproduct [p01 x p02].
    const int z = p01.x * p02.y - p01.y * p02.x;

    if (z == 0) return COLLINEAER;
    if (z > 0)  return CW;
    return CCW;
}

// Graham compare
int gcompare(const glm::ivec2 p1, const glm::ivec2 p2) {
    int orient = orientation(p0, p1, p2);
    if (orient == COLLINEAER)
        return      ((p0.x * p0.x - p2.x * p2.x) + (p0.y * p0.y - p2.y * p2.y))
                <   ((p0.x * p0.x - p1.x * p1.x) + (p0.y * p0.y - p1.y * p1.y))
                ? 0 : 1;
    return orient == CCW ? 1 : 0;
}

std::stack<glm::ivec2> graham_scan(glm::ivec2 pin[], int n) {
    union Pl {
        glm::ivec2 p;
        long l;
    };
    // Find the point with the smallest 'y' coordinate.
    // If such a point is not unique, choose the point
    // with the smallest x coordinate.
    Pl sm       = { .p = pin[0] }; // The smallest point.
    int smidx   = 0;               // The index of the smallest point
    for (int i = 1; i < n; i++) {
        // For comprasion let's use the fact that
        // 'y' coordinate in a ivec2 structure happens
        // to be more significant than x.
        Pl n = { .p = pin[i] };
        if (sm.l > n.l) {
            sm.l  = n.l;
            smidx = i;
        }
    }
    p0 = sm.p; // The smallest point
    std::swap(pin[0], pin[smidx]);
    std::sort (pin + 1, pin + n, gcompare);

    std::stack<glm::ivec2> s;

    s.push(pin[0]);
    s.push(pin[1]);
    s.push(pin[2]);

    for (int i = 3; i < n; i++) {
        while( !s.empty()
                && orientation(next2top(s), s.top(), pin[i]) != CCW
            ) s.pop();
        s.push(pin[i]);
    }

    return s;
}
