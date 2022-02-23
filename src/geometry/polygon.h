#include <glm/vec2.hpp>
#include <stack>

#include "line.h"

bool is_convex(const glm::vec2 p[], int n);

// Find the convex hull
std::stack<glm::ivec2> graham_scan(glm::ivec2 points_in[], int points_count);

// Find out the orientation of the 3 points.
int orientation(glm::ivec2 p, glm::ivec2 q, glm::ivec2 r);
