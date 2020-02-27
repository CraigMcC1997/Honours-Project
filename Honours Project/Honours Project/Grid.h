//############################################
//Code based on work from Dr Marco Gilardi's
//Collision Detection Module
//############################################

#pragma once
#include <glm\glm.hpp>
#include "Shape.h"
#include <map>
#include <vector>

using namespace std;
using namespace glm;

typedef pair<int, int> Indices;

class Grid
{
private:
	int cellSize, height, width;
	int columns, rows;
	map <Indices, vector<Shape*>> objBuckets;
	Indices computeCellIndices(vec2 position);
public:
	Grid(int width, int height, int cellSize);
	virtual ~Grid();
	void registerObj(Shape* obj);
	vector<Shape*> getNeighbours(Shape* obj);
	void clearGrid();
};