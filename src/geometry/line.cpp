#include "line.h"

int classify(glm::vec2 p, glm::vec2 a, glm::vec2 b) {
    const glm::vec2 ap = p - a;
    const glm::vec2 ab = b - a;

    const float area = ab.x * ap.y - ap.x * ab.y;

    if (area > EPS)
        return Position2Line::LEFT;
    if (area < -EPS)
        return Position2Line::RIGHT;
    if (glm::length(ap) < EPS)
        return Position2Line::START;
    if (glm::length( p - b ) < EPS)
        return Position2Line::END;
    if ( (ap.x * ab.x < EPS) || (ap.y * ab.y < EPS) )
        return Position2Line::BEFORE;
    if ( glm::length(ab) < glm::length(ap) )
        return Position2Line::AFTER;
    return Position2Line::INSIDE;
}

int lines_intersect(glm::vec2 n1, glm::vec2 n2, float d1, float d2, glm::vec2& p) {
    const float det = n1.x * n2.y - n2.x * n1.y;
    if (det < EPS) {
        // Two lines are the same.
        return (fabs( d1 - d2 ) < EPS);
    }

    const float detx = d1 * n2.y - d2 * n1.y;
    const float dety = n1.x * d2 - n2.x * d1;

    p.x = detx / det;
    p.y = dety / det;

    return 2;
}
