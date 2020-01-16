#include "GJK.h"

void GJK::performGJK()
{

	//!! FOR TEST PURPOSES !!
	// Final edition = shapes will create their own convex hulls for their data
	// Shapes hulls will be passed in from the game class

	// create a set of points in 3D space
	// pass them into the convex hull class which calculates the hull of the points
	// convex hull is passed back the game as a set of points stored in a vector
	// points are written to console window for testing purposes

	//CONVEX HULL CALCULATOR
	int size = points.size();
	vector<glm::vec3> hull1;
	vector<glm::vec3> hull2;

	if (size >= 4) {	//make sure there are enough points for a 3D shape
		hull1 = cHull->createHull(points);
		hull2 = cHull->createHull(points2);
	}
	else
		cout << "not enought vertices for 3D shape, minimum required: 4.\nCurrent vertex count"
		<< size << endl;

	cout << "Points on first hull: " << endl;
	for (int i = 0; i <= hull1.size() - 1; i++)
		cout << "(" << hull1[i].x << ", " << hull1[i].y << ", " << hull1[i].z << ")\n";

	cout << "Points on second hull: " << endl;
	for (int i = 0; i <= hull2.size() - 1; i++)
		cout << "(" << hull2[i].x << ", " << hull2[i].y << ", " << hull2[i].z << ")\n";







	direction = glm::vec3(0, 1, 0);

	unsigned int furthestIndex = support->furthestPoint(direction, hull1);
	cout << "\n\n" << endl;
	cout << "furthest point: " << furthestIndex << endl;

	glm::vec3 furthestVertice = points[furthestIndex];
	cout << "x: " << furthestVertice.x << endl;
	cout << "y: " << furthestVertice.y << endl;
	cout << "z: " << furthestVertice.z << endl;

											  //direction  two point clouds  
	glm::vec3 furthestPoint = support->support(direction, hull1, hull2);
	cout << "\n\n" << endl;
	cout << "x: " << furthestPoint.x << endl;
	cout << "y: " << furthestPoint.y << endl;
	cout << "z: " << furthestPoint.z << endl;

}