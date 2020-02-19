 #include "GJK.h"

//CODE BASED ON ->>> http://in2gpu.com/2014/05/18/gjk-algorithm-3d/


bool GJK::performDetection(/*vector<glm::vec3> hull1, vector<glm::vec3> hull2*/)
{

    //!! FOR TEST PURPOSES !!
    // Final edition = shapes will create their own convex hulls for their data
    // Shapes hulls will be passed in from the game class

    // create a set of points in 3D space
    // pass them into the convex hull class which calculates the hull of the points
    // convex hull is passed back the game as a set of points stored in a vector
    // points are written to console window for testing purposes

    ////CONVEX HULL CALCULATOR
    //int size = points.size();
    //vector<glm::vec3> hull1;
    //vector<glm::vec3> hull2;

    //if (size >= 4) {	//make sure there are enough points for a 3D shape
    //    hull1 = cHull->createHull(points);
    //    hull2 = cHull->createHull(points2);
    //}
    //else
    //    cout << "not enought vertices for 3D shape, minimum required: 4.\nCurrent vertex count"
    //    << size << endl;

    //cout << "Points on first hull: " << endl;
    //for (int i = 0; i <= hull1.size() - 1; i++)
    //    cout << "(" << hull1[i].x << ", " << hull1[i].y << ", " << hull1[i].z << ")\n";

    //cout << "Points on second hull: " << endl;
    //for (int i = 0; i <= hull2.size() - 1; i++)
    //    cout << "(" << hull2[i].x << ", " << hull2[i].y << ", " << hull2[i].z << ")\n";







    //direction = glm::vec3(0, 1, 0);

    //unsigned int furthestIndex = support->furthestPoint(direction, hull1);
    //cout << "\n\n" << endl;
    //cout << "furthest point: " << furthestIndex << endl;

    //glm::vec3 furthestVertice = points[furthestIndex];
    //cout << "x: " << furthestVertice.x << endl;
    //cout << "y: " << furthestVertice.y << endl;
    //cout << "z: " << furthestVertice.z << endl;

    ////direction  two point clouds  
    //glm::vec3 furthestPoint = support->support(direction, hull1, hull2);
    //cout << "\n\n" << endl;
    //cout << "x: " << furthestPoint.x << endl;
    //cout << "y: " << furthestPoint.y << endl;
    //cout << "z: " << furthestPoint.z << endl;






    ////TESTING THE GJK
    cout << "TESTING THE GJK" << endl;

	// TEST CODE ONLY!!
	simplex[2] = support->support(direction, points, points2);
	direction = -simplex[2];	//opposite direction
	simplex[1] = support->support(direction, points, points2);

	if (dot(simplex[1], direction) < 0)
		return false;

	direction = Maths::doubleCross(simplex[2] - simplex[1], -simplex[1]);

	simplexSize = 2; //begin with a line

	while (steps < 50) {
		simplex[0] = support->support(direction, points, points2);
		if (dot(simplex[0], direction) < 0)
			return false;
		else {
			if (ContainsOrigin(direction)) {
				return true;
			}
		}
		steps++;
	}
	return false;
}


// EVERYTHING BELOW HERE IS FOR TESTING PURPOSES ONLY!!! 
// CODE TAKEN FROM ->>> http://in2gpu.com/2014/05/18/gjk-algorithm-3d/
// THE BELOW IS NOT ALL MY WORK AND SHOULD NOT APPEAR IN FINAL CODE WITHOUT 
// PERSONALISED CHANGES AND EDITIONS


bool GJK::ContainsOrigin(glm::vec3 direction)
{
	if (simplexSize == 2)
		return triangle(direction);

	else if (simplexSize == 3)
		return tetrahedron(direction);

	return false;
}

bool GJK::triangle(glm::vec3 direction)
{
	glm::vec3 ao = -simplex[0];					//Line AO
	glm::vec3 ab = simplex[1] - simplex[0];		//Line AB
	glm::vec3 ac = simplex[2] - simplex[0];		//Line AC
	glm::vec3 abc = Maths::cross(ab, ac);		//Face ABC

	//origin can't be behind points B,C or line BC 

	glm::vec3 ab_abc = Maths::cross(ab, abc);	//Line AB on face ABC
	
	//is the origin away from AB?
	if (dot(ab_abc, ao) > 0) {
		simplex[2] = simplex[1];
		simplex[1] = simplex[0];

		//not facing origin, find new direction
		direction = Maths::doubleCross(ab, ao);

		//can't build tetrahedron, early exit
		return false;
	}

	glm::vec3 abc_ac = Maths::cross(abc, ac);	//Line AC on face ABC

	// is the origin away from AC? 
	if (dot(abc_ac, ao) > 0) {
		simplex[1] = simplex[0];

		direction = Maths::doubleCross(ac, ao);

		//direction change; can't build tetrahedron
		return false;
	}

	//above or below face ABC
	if (dot(abc, ao) > 0) {
		//base of tetrahedron
		simplex[3] = simplex[2];
		simplex[2] = simplex[1];
		simplex[1] = simplex[0];

		//new direction
		direction = abc;
	}
	else {
		//upside down tetrahedron
		simplex[3] = simplex[1];
		simplex[2] = simplex[0];
		direction = -abc;
	}

	simplexSize = 3;
	return false;
}

bool GJK::tetrahedron(glm::vec3 direction) {
	glm::vec3 ao = -simplex[0];					//Line AO
	glm::vec3 ab = simplex[1] - simplex[0];		//Line AB
	glm::vec3 ac = simplex[2] - simplex[0];		//Line AC
	glm::vec3 abc = Maths::cross(ab, ac);		//FACE ABC

	//CASE 1
	//in front of face ABC
	if (dot(abc, ao) > 0)
		checkTetrahedron(ao, ab, ac, abc, direction);

	//CASE 2
	glm::vec3 ad = simplex[3] - simplex[0];		//Line AD
	glm::vec3 acd = Maths::cross(ac, ad); 		//Face ACD
	
	//in front of face ACD
	if (dot(acd,ao) > 0) {
		simplex[1] = simplex[2];
		simplex[2] = simplex[3];
		ab = ac;
		ac = ad;
		abc = acd;

		checkTetrahedron(ao, ab, ac, abc, direction);
	}

	//CASE 3
	glm::vec3 adb = Maths::cross(ad, ab); //ADB triangle

	//in front of face ADB
	if (dot(adb,ao) > 0) {
		simplex[2] = simplex[1];
		simplex[1] = simplex[3];
		ac = ab;
		ab = ad;
		abc = adb;

		checkTetrahedron(ao, ab, ac, abc, direction);
	}
	//origin within tetrahedron already built
	return true;
}

bool GJK::checkTetrahedron(const glm::vec3 ao, const glm::vec3 ab, 
	const glm::vec3 ac, const glm::vec3 abc, glm::vec3 direction) 
{
	glm::vec3 ab_abc = Maths::cross(ab, abc);		//Line AB on face ABC

	if (dot(ab_abc,ao) > 0)
	{
		simplex[2] = simplex[1];
		simplex[1] = simplex[0];

		//direction is not ab_abc because it does not point towards the origin
		direction = Maths::doubleCross(ab, ao);

		//start again from triangle checks
		simplexSize = 2;
		return false;
	}

	glm::vec3 acp = Maths::cross(abc, ac);		//Face 

	if (dot(acp,ao) > 0) {
		simplex[1] = simplex[0];

		//direction is not abc_ac because it's not point towards the origin
		direction = Maths::doubleCross(ac, ao);

		//start again from triangle checks
		simplexSize = 2;
		return false;
	}

	//build new tetrahedron with new base
	simplex[3] = simplex[2];
	simplex[2] = simplex[1];
	simplex[1] = simplex[0];

	direction = abc;
	simplexSize = 3;
	return false;
}