#pragma once

class Vector2
{
public:
	//Constructors
	Vector2();
	Vector2(float xVal, float yVal);
	//Deconstructor
	~Vector2();

	//Operator overloads
	Vector2 operator + (const Vector2& other);
	Vector2 operator - (const Vector2& other);
	Vector2 operator * (const float& other);
	operator float*();

	//Public functions
	float dot(const Vector2& other);
	float magnitude();
	void normalise();

	//Public variables
	float x = 0;
	float y = 0;
};

//Operator overload outside class at it takes the class
Vector2 operator * (const float& lhs, const Vector2& rhs);