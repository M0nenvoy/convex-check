#pragma once

#include <glm/vec2.hpp>
#include <glm/geometric.hpp>

#include "const.h"

// Определение положения различных сущностей относительно
// прямой.

// Position relative to a line
enum Position2Line {
    LEFT = 1,
    RIGHT,
    BEFORE,
    AFTER,
    START,
    END,
    INSIDE,
};
// Определение расположения точки p относительно
// отрезка ab
int classify(glm::vec2 p, glm::vec2 a, glm::vec2 b);

// Find the intersection of two lines and write it to {p}.
// If none was found return 0
// If lines are the same, return 1
// If lines intersect, return 2
int lines_intersect(glm::vec2 n1, glm::vec2 n2, float d1, float d2, glm::vec2& p);
