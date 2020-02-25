#include "Transform.h"

Transform::Transform()
{
	transformMatrix = glm::mat4(1.0f, 0.0f, 0.0f, 0.0f,
								0.0f, 1.0f, 0.0f, 0.0f,
								0.0f, 0.0f, 1.0f, 0.0f,
								0.0f, 0.0f, 0.0f, 1.0f);
}

// Translate the object by creating a Translation matrix and 
// multiplying it to the transform matrix
void Transform::Translate(glm::vec3& translation)
{
	glm::mat4 translationMatrix = glm::mat4(1.0f, 0.0f, 0.0f, 0.0f,
											0.0f, 1.0f, 0.0f, 0.0f,
											0.0f, 0.0f, 1.0f, 0.0f,
											translation.x, translation.y, translation.z, 1.0f);

	transformMatrix = translationMatrix * transformMatrix;
}

// Translate the object by creating a Scaling matrix and 
// multiplying it to the transform matrix
void Transform::Scale(glm::vec3 scaling)
{
	glm::mat4 scalingMatrix = glm::mat4(scaling.x, 0.0f, 0.0f, 0.0f,
										0.0f, scaling.y, 0.0f, 0.0f,
										0.0f, 0.0f, scaling.z, 0.0f, 
										0.0f, 0.0f, 0.0f, 1.0f); 

	transformMatrix = scalingMatrix * transformMatrix;
}

// Translate the object by creating a Rotation matrix and 
// multiplying it to the transform matrix
void Transform::RotateX(float angle)
{
	//rotation along the Z axis
	glm::mat4 rotateMatrix = glm::mat4(	1.0f, 0.0f, 0.0f, 0.0f,
										0.0f, cos(angle), -sin(angle), 0.0f,
										0.0f, sin(angle), cos(angle), 0.0f,
										0.0f, 0.0f, 0.0f, 1.0f);

	transformMatrix = rotateMatrix * transformMatrix;
}

void Transform::RotateY(float angle)
{
	//rotation along the Z axis
	glm::mat4 rotateMatrix = glm::mat4(	cos(angle), 0.0f, -sin(angle), 0.0f,
										 0.0f, 1.0f, 0.0f, 0.0f,
										sin(angle), 0.0f, cos(angle), 0.0f,
										0.0f, 0.0f, 0.0f, 1.0f);

	transformMatrix = rotateMatrix * transformMatrix;
}

void Transform::RotateZ(float angle)
{
	//rotation along the Z axis
	glm::mat4 rotateMatrix = glm::mat4(	cos(angle), -sin(angle), 0.0f, 0.0f,
										sin(angle), cos(angle), 0.0f, 0.0f,
										0.0f, 0.0f, 1.0f, 0.0f,
										0.0f, 0.0f, 0.0f, 1.0f);

	transformMatrix = rotateMatrix * transformMatrix;
}



glm::vec3 Transform::getPosition()
{
	return glm::column(transformMatrix, 3); // The forth column of the transformation matrix contains the position of the object in homogeneous coords
}

glm::vec3 Transform::getScale()
{
	float sx = glm::length(glm::column(transformMatrix, 0)); // It measures the length of the local x axis
	float sy = glm::length(glm::column(transformMatrix, 1)); // It measures the length of the local y axis
	float sz = glm::length(glm::column(transformMatrix, 2)); // It measures the length of the local z axis

	return glm::vec3(sx, sy, sz);
}

glm::vec3 Transform::getOrientation()
{
	glm::vec3 col0 = glm::normalize(glm::column(transformMatrix, 0)); // By normalising the x axis whe get the cosine (in the first component of the vector)
													   // and sine (in the second component of the vector) of the angle by which the object is rotated
	return glm::vec3(col0.x, col0.y, col0.z);
}

// This gives the y axis of the object expressed in world coordinates
glm::vec3 Transform::getUpDir()
{
	glm::vec3  col1 = column(transformMatrix, 1);
	return glm::vec3(col1.x, col1.y, col1.z); // y Axis
}

// This gives the x axis of the object expressed in world coordinates
glm::vec3 Transform::getLeftDir()
{
	glm::vec3 col0 = column(transformMatrix, 0);
	return glm::vec3(col0.x, col0.y, col0.z); // x Axis
}

glm::mat4 Transform::localToWorldMatrix()
{
	return transformMatrix; //This matrix transforms local coordinates into world coordinates (if we are not using any hierarchical data structure)
}

glm::mat4 Transform::worldToLocalMatrix()
{
	return inverse(transformMatrix);
}