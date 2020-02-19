#include "Maths.h"

namespace Maths {
    //CODE BASED ON ->>> http://in2gpu.com/2014/05/18/gjk-algorithm-3d/
    glm::vec3 cross(const glm::vec3 v1, const glm::vec3 v2)
    {
        return glm::vec3(v1.y * v2.z - v1.z * v2.y,
            v1.z * v2.x - v1.x * v2.z,
            v1.x * v2.y - v1.y * v2.x);
    }

    glm::vec3 doubleCross(const glm::vec3 v1, const glm::vec3 v2)
    {
        return cross(cross(v1, v2), v1);
    }
}