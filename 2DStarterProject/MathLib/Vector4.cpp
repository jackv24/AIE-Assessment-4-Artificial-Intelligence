#include "Vector4.h"
#include <math.h>

Vector4::Vector4()
{
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}
Vector4::Vector4(float xVal, float yVal, float zVal, float wVal)
{
	x = xVal;
	y = yVal;
	z = zVal;
	w = wVal;
}
Vector4::~Vector4()
{

}

Vector4 Vector4::operator + (const Vector4& other)
{
	Vector4 newVector;

	newVector.x = x + other.x;
	newVector.y = y + other.y;
	newVector.z = z + other.z;
	newVector.w = w + other.w;

	return newVector;
}
Vector4 Vector4::operator - (const Vector4& other)
{
	Vector4 newVector;

	newVector.x = x - other.x;
	newVector.y = y - other.y;
	newVector.z = z - other.z;
	newVector.w = w - other.w;

	return newVector;
}
Vector4 Vector4::operator * (const float& other)
{
	Vector4 newVector;

	newVector.x = x * other;
	newVector.y = y * other;
	newVector.z = z * other;
	newVector.w = w * other;

	return newVector;
}
Vector4 operator * (const float& lhs, const Vector4& rhs)
{
	Vector4 newVector;

	newVector.x = lhs * rhs.x;
	newVector.y = lhs * rhs.y;
	newVector.z = lhs * rhs.z;
	newVector.w = lhs * rhs.w;

	return newVector;
}
Vector4::operator float*()
{
	//Return vector values as array
	return (float*)this;
}

float Vector4::dot(const Vector4& other)
{
	return x * other.x + y * other.y + z * other.z + w * other.w;
}
Vector4 Vector4::cross(const Vector4& other)
{
	return Vector4(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x, 0);
}
float Vector4::magnitude()
{
	return sqrt(x * x + y * y + z * z + w * w);
}
void Vector4::normalise()
{
	float length = magnitude();

	x /= length;
	y /= length;
	z /= length;
	w /= length;
}