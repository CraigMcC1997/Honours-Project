#include "Collidable.h"

//update this to take the points passed in
//and find the hull of those points
//instead of just storing the points as is
void Collidable::setConvexHull(vector<glm::vec3> points)
{
	//auto hull = qh.getConvexHull(&points[0].x, points.size(), true, false);
	////auto hull = qh.getConvexHull(points, true, false);
	//auto indexBuffer = hull.getIndexBuffer();
	//auto vertexBuffer = hull.getVertexBuffer();

	convexHull = points;
}

vector<glm::vec3> Collidable::getConvexHull()
{
	return convexHull;
}


//algorithm for computing the centroid of a set of points
//for(auto it=points.begin(); it< points.end(); it++) {
//	C += *it;
//}
//C /= N;

