#pragma once
#include <math.h>
#include <string>

class Vector3d
{
public:
	Vector3d();
	Vector3d(float xVal, float yVal, float zVal);
	~Vector3d();

	Vector3d Cross(Vector3d const& rhs);
	float Dot(Vector3d const& rhs);
	
	float Magnitude();

	Vector3d Normalized();
	void Normalize();

	Vector3d operator+(Vector3d const& rhs);
	Vector3d operator-(Vector3d const& rhs);
	Vector3d operator-();
	float operator*(Vector3d const& rhs);
	Vector3d operator*(float scalar);
	Vector3d operator/(float scalar);

	std::string ToString();

	float x;
	float y;
	float z;
};

typedef Vector3d Point3d;

