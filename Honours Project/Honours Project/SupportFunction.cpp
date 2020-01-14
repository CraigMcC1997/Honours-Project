#include "SupportFunction.h"

unsigned int SupportFunction::support(glm::vec3 direction, vector<glm::vec3> points)
{
    float maximum = dot(direction, points[0]);

    unsigned int index = 0;
    
    for (int i = 1; i < points.size(); i++) {
        float product = dot(direction, points[i]);
        if (product > maximum) {
            maximum = product;
            index = i;
        }
    }
    return index;
}
