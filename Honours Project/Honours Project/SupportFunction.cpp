#include "SupportFunction.h"

unsigned int SupportFunction::furthestPoint(const glm::vec3& direction, const vector<glm::vec3>& points) {
    float maximum = dot(direction, points[0]);

    unsigned int index = 0;

    for (int i = 1; i < points.size(); i++) {
        float current = dot(direction, points[i]);
        if (current > maximum) {
            maximum = current;
            index = i;
        }
    }
    return index;
}

glm::vec3 SupportFunction::support(const glm::vec3& direction,
    const vector<glm::vec3>& points, const vector<glm::vec3>& points2) {
    //furthest point in one direction and furthest in the opposite
    int a = furthestPoint(direction, points);
    int b = furthestPoint(-direction, points2);

    //returns a point on the edge of the minkowski difference
    glm::vec3 returnContainer;
    returnContainer = points[a] - points2[b];

    return returnContainer;
}