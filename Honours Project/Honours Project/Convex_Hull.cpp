#include "Convex_Hull.h"

 
// The function returns following values 
// 0 --> p, q and r are colinear 
// 1 --> Clockwise 
// 2 --> Counterclockwise
int Convex_Hull::orientation(glm::vec3 p, glm::vec3 q, glm::vec3 r)
{
	int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

	if (val == 0) return 0;   // colinear 
	return (val > 0) ? 1 : 2; // clock or counterclock wise 
}

vector<glm::vec3> Convex_Hull::createHull(vector<glm::vec3> points)
{
	// Initialize Result 
	vector<glm::vec3> hull;

	// Find the furthest left point on the X axis
	int leftMost = 0;
	for (int i = 1; i < points.size(); i++)
		if (points[i].x < points[leftMost].x)
			leftMost = i;

	//start at the furthest left point and move along
	//until the furthest left point is reached a second time
	int current = leftMost;
	int next;
	do {
		// Add current point to container of hull points 
		hull.push_back(points[current]);

		// Search for a point 'q' such that orientation(p, x, 
		// q) is counterclockwise for all points 'x'. The idea 
		// is to keep track of last visited most counterclock- 
		// wise point in q. If any point 'i' is more counterclock- 
		// wise than q, then update q. 
		next = (current + 1) % points.size();
		for (int i = 0; i < points.size(); i++)
		{
			// If i is more counterclockwise than current q, then 
			// update q 
			if (orientation(points[current], points[i], points[next]) == 2)
				next = i;
		}

		// Now q is the most counterclockwise with respect to p 
		// Set p as q for next iteration, so that q is added to 
		// result 'hull' 
		current = next;

	} while (current != leftMost);  // While we don't come to first point 
	return hull;
}