#include "SAT.h"

bool SAT::performDetection(vector<glm::vec3>& hull1, vector<glm::vec3>& hull2)
{
	// projections
	// based on algorithms from --->>https://www.metanetsoftware.com/technique/tutorialA.html
	glm::vec3 proj;
	glm::vec3 a, b;
	proj.x = ((dot(a, b)) / (b.x * b.x + b.y * b.y + b.z * b.z)) * b.x;
	proj.y = ((dot(a, b)) / (b.x * b.x + b.y * b.y + b.z * b.z)) * b.y;
	proj.z = ((dot(a, b)) / (b.x * b.x + b.y * b.y + b.z * b.z)) * b.z;


	return false;
}

#include <vector>
#include <limits>

/// Returns whether the two given convex polygons intersect using the
/// separating axis theorem. The given polygons can be in clockwise or
/// counter-clockwise order (does not matter).
//bool SAT::performDetection(std::vector<glm::vec3>& a, std::vector<glm::vec3>& b)
//{
//	// loop over the vertices(-> edges -> axis) of the first polygon
//	for (auto i = 0; i < a.size(); ++i) {
//		// calculate the normal vector of the current edge
//		// this is the axis will we check in this loop
//		auto current = a[i];
//		auto next = a[(i + 1) % a.size()];
//		auto edge = next - current;
//
//		glm::vec3 axis{};
//		axis[0] = -edge[1];
//		axis[1] = edge[0];
//
//		// loop over all vertices of both polygons and project them
//		// onto the axis. We are only interested in max/min projections
//		auto aMaxProj = -std::numeric_limits<float>::infinity();
//		auto aMinProj = std::numeric_limits<float>::infinity();
//		auto bMaxProj = -std::numeric_limits<float>::infinity();
//		auto bMinProj = std::numeric_limits<float>::infinity();
//		for (const auto& v : a) {
//			auto proj = dot(axis, v);
//			if (proj < aMinProj) aMinProj = proj;
//			if (proj > aMaxProj) aMaxProj = proj;
//		}
//
//		for (const auto& v : b) {
//			auto proj = dot(axis, v);
//			if (proj < bMinProj) bMinProj = proj;
//			if (proj > bMaxProj) bMaxProj = proj;
//		}
//
//		if (aMaxProj < bMinProj || aMinProj > bMaxProj) {
//			return true;
//		}
//	}
//
//	// at this point, we have checked all axis but found no separating axis
//	// which means that the polygons must intersect.
//	return false;
//}