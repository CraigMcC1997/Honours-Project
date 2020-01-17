#include "GJK.h"

glm::vec3 GJK::tripleProduct(glm::vec3 a, glm::vec3 b, glm::vec3 c) {

    glm::vec3 r;

    float ac = a.x * c.x + a.y * c.y + a.z * c.z; // perform a.dot(c)
    float bc = b.x * c.x + b.y * c.y + b.z * c.z; // perform b.dot(c)

    // perform b * a.dot(c) - a * b.dot(c)
    r.x = b.x * ac - a.x * bc;
    r.y = b.y * ac - a.y * bc;
    r.z = b.z * ac - a.z * bc;
    return r;
}

int GJK::performGJK(/*vector<glm::vec3> hull1, vector<glm::vec3> hull2*/)
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






	//TESTING THE GJK
	cout << "TESTING THE GJK" << endl;

    size_t index = 0; // index of current vertex of simplex
    glm::vec3 a, b, c, ao, ab, ac, abperp, acperp, simplex[3];

    // if initial direction is zero – set it to any arbitrary axis (we choose X)
    if ((direction.x == 0) && (direction.y == 0))
        direction.x = 1.f;

    // set the first support as initial point of the new simplex
    a = simplex[0] = support->support(direction, hull1, hull2);

    if (dot(a, direction) <= 0)
        return 0; // no collision

    direction = -a; // The next search direction is always towards the origin, so the next search direction is negate(a)

    while (1) {
        iter_count++;

        a = simplex[0] = support->support(direction, hull1, hull2);

        if (dot(a, direction) <= 0)
            return 0; // no collision

        ao = -a; // from point A to Origin is just negative A

        // simplex has 2 points (a line segment, not a triangle yet)
        if (index < 3) {
            b = simplex[0];
            ab = b - a; // from point A to B
            direction = tripleProduct(ab, ao, ab); // normal to AB towards Origin
            if ((direction.x * direction.x + direction.y * direction.y + direction.z * direction.z) == 0)
                direction.x = -direction.x;
            continue; // skip to next iteration
        }

        b = simplex[1];
        c = simplex[0];
        ab = b - a; // from point A to B
        ac = c - a; // from point A to C

        acperp = tripleProduct(ab, ac, ac);

        if (dot(acperp, ao) >= 0) {

            direction = acperp; // new direction is normal to AC towards Origin

        }
        else {

            abperp = tripleProduct(ac, ab, ab);

            if (dot(abperp, ao) < 0)
                return 1; // collision

            simplex[0] = simplex[1]; // swap first element (point C)

            direction = abperp; // new direction is normal to AB towards Origin
        }

        simplex[1] = simplex[2]; // swap element in the middle (point B)
        --index;
    }

    return 0;

}