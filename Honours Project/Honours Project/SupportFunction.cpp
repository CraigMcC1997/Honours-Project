#include "SupportFunction.h"

unsigned int SupportFunction::furthestPoint(glm::vec3 direction, vector<glm::vec3> points) {
    float maximum = dot(direction, points[0]);

    unsigned int index = 0;
    float current;

    for (int i = 1; i < points.size(); i++) {
        current = dot(direction, points[i]);
        if (current > maximum) {
            maximum = current;
            index = i;
        }
    }
    return index;
}

glm::vec3 SupportFunction::support(glm::vec3 direction, 
	vector<glm::vec3> points, vector<glm::vec3> points2) {
    // furthest point in one direction and furthest in the opposite
    int a = furthestPoint(direction, points);
    int b = furthestPoint(-direction, points2);

    //returns a point on the edge of the minkowski difference
    glm::vec3 returnContainer;
    returnContainer = points[a] - points2[b];

    return returnContainer;
}



