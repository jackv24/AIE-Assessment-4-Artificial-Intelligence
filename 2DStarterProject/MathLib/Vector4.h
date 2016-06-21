#pragma once

class Vector4
{
public:
	//Constructors
	Vector4();
	Vector4(float xVal, float yVal, float zVal, float wVal);
	//Deconstructor
	~Vector4();

	//Operator overloads
	Vector4 operator + (const Vector4& other);
	Vector4 operator - (const Vector4& other);
	Vector4 operator * (const float& other);
	operator float*();

	//Public functions
	float dot(const Vector4& other);
	Vector4 cross(const Vector4& other);
	float magnitude();
	void normalise();

	//Public variables
	float x = 0;
	float y = 0;
	float z = 0;
	float w = 0;
};

//Operator overload outside class at it takes the class
Vector4 operator * (const float& lhs, const Vector4& rhs);