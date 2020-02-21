#include "MinkowskiSum.h"

vector<glm::vec3> MinkowskiSum::sum(vector<glm::vec3> pointSet1, vector<glm::vec3> pointSet2)
{
	vector<glm::vec3> summation;

	for (int i = 0; i <= pointSet1.size() -1; i++) {
		for (int j = 0; j <= pointSet2.size() -1; j++) {
			summation.push_back(pointSet1[i] + pointSet2[j]);
		}
	}
	return summation;
}
