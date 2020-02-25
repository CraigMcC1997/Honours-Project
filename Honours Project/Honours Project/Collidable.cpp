#include "Collidable.h"

//update this to take the points passed in
//and find the hull of those points
//instead of just storing the points as is
void Collidable::setConvexHull(vector<glm::vec3> points)
{
	auto hull = qh.getConvexHull(&points[0].x, points.size(), true, false);
	//auto hull = qh.getConvexHull(points, true, false);
	auto indexBuffer = hull.getIndexBuffer();
	auto vertexBuffer = hull.getVertexBuffer();
}

vector<glm::vec3> Collidable::getConvexHull()
{
	return convexHull;
}
