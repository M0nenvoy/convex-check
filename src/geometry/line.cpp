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
