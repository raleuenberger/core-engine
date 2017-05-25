#include "Math/Vector3d.h"

Vector3d::Vector3d()
{
}

Vector3d::Vector3d(float xVal, float yVal, float zVal) : x(xVal), y(yVal), z(zVal)
{
}


Vector3d::~Vector3d()
{
}


Vector3d Vector3d::Cross(Vector3d const& rhs)
{
	return Vector3d
	(
		(this->y * rhs.z) - (this->z * rhs.y),
		(this->z * rhs.x) - (this->x * rhs.z),
		(this->x * rhs.y) - (this->y * rhs.x)
	);
}

float Vector3d::Dot(Vector3d const& rhs)
{
	return (this->x * rhs.x) + (this->y * rhs.y) + (this->z * rhs.z);
}

float Vector3d::Magnitude()
{
	return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}

Vector3d Vector3d::Normalized()
{
	float magnitude = this->Magnitude();
	if (magnitude == 0) return Vector3d(0, 0, 0);
	else return Vector3d(this->x / magnitude, this->y / magnitude, this->z / magnitude);
}

void Vector3d::Normalize()
{
	*this = this->Normalized();
}

Vector3d Vector3d::operator+(Vector3d const& rhs)
{
	return Vector3d(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z);
}

Vector3d Vector3d::operator-(Vector3d const& rhs)
{
	return Vector3d(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z);
}

Vector3d Vector3d::operator-()
{
	return Vector3d(-this->x, -this->y, -this->z);
}

float Vector3d::operator*(Vector3d const& rhs)
{
	return Dot(rhs);
}

Vector3d Vector3d::operator*(float scalar)
{
	return Vector3d(this->x * scalar, this->y * scalar, this->z * scalar);
}

Vector3d Vector3d::operator/(float scalar)
{
	return Vector3d(this->x / scalar, this->y / scalar, this->z / scalar);
}

std::string Vector3d::ToString()
{
	return "(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ", " + std::to_string(this->z) + ")";
}