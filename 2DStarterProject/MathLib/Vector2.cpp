#include "Vector2.h"
#include <math.h>

Vector2::Vector2()
{
	x = 0;
	y = 0;
}
Vector2::Vector2(float xVal, float yVal)
{
	x = xVal;
	y = yVal;
}
Vector2::~Vector2()
{
	
}

Vector2 Vector2::operator + (const Vector2& other)
{
	Vector2 newVector;

	newVector.x = x + other.x;
	newVector.y = y + other.y;

	return newVector;
}
Vector2 Vector2::operator - (const Vector2& other)
{
	Vector2 newVector;

	newVector.x = x - other.x;
	newVector.y = y - other.y;

	return newVector;
}
Vector2 Vector2::operator * (const float& other)
{
	Vector2 newVector;

	newVector.x = x * other;
	newVector.y = y * other;

	return newVector;
}
Vector2 operator * (const float& lhs, const Vector2& rhs)
{
	Vector2 newVector;

	newVector.x = lhs * rhs.x;
	newVector.y = lhs * rhs.y;

	return newVector;
}
Vector2::operator float*()
{
	return (float*)this;
}

float Vector2::dot(const Vector2& other)
{
	return x * other.x + y * other.y;
}
float Vector2::magnitude()
{
	return sqrt(x * x + y * y);
}
void Vector2::normalise()
{
	float length = magnitude();

	x /= length;
	y /= length;
}