#include "Vector3.h"
#include <math.h>

Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}
Vector3::Vector3(float xVal, float yVal, float zVal)
{
	x = xVal;
	y = yVal;
	z = zVal;
}
Vector3::~Vector3()
{

}

Vector3 Vector3::operator + (const Vector3& other)
{
	Vector3 newVector;

	newVector.x = x + other.x;
	newVector.y = y + other.y;
	newVector.z = z + other.z;

	return newVector;
}
Vector3 Vector3::operator - (const Vector3& other)
{
	Vector3 newVector;

	newVector.x = x - other.x;
	newVector.y = y - other.y;
	newVector.z = z - other.z;

	return newVector;
}
Vector3 Vector3::operator * (const float& other)
{
	Vector3 newVector;

	newVector.x = x * other;
	newVector.y = y * other;
	newVector.z = z * other;

	return newVector;
}
Vector3 operator * (const float& lhs, const Vector3& rhs)
{
	Vector3 newVector;

	newVector.x = lhs * rhs.x;
	newVector.y = lhs * rhs.y;
	newVector.z = lhs * rhs.z;

	return newVector;
}
Vector3::operator float*()
{
	//Return vector values as array
	return (float*)this;
}

float Vector3::dot(const Vector3& other)
{
	return x * other.x + y * other.y + z * other.z;
}
Vector3 Vector3::cross(const Vector3& other)
{
	return Vector3(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
}
float Vector3::magnitude()
{
	return sqrt(x * x + y * y + z * z);
}
void Vector3::normalise()
{
	float length = magnitude();

	x /= length;
	y /= length;
	z /= length;
}