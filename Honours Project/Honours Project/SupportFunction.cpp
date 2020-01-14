#include "SupportFunction.h"

unsigned int SupportFunction::furthestPoint(glm::vec3 direction, vector<glm::vec3> points)
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

glm::vec3 SupportFunction::support(glm::vec3 direction, vector<glm::vec3> points, vector<glm::vec3> points2)
{
    // get furthest point of first body along an arbitrary direction
    int i = furthestPoint(direction, points);

    // get furthest point of second body along the opposite direction
    int j = furthestPoint(-direction, points2);

    // subtract (Minkowski sum) the two points to see if bodies 'overlap'
    glm::vec3 returnContainer;
    returnContainer = points[i] - points2[j];

    return returnContainer;
}
