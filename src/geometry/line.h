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
