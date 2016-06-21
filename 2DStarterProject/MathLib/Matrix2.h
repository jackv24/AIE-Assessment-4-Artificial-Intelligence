#pragma once

#include "Vector2.h"

class Matrix2
{
public:
	Matrix2();
	Matrix2(float c1r1, float c1r2, float c2r1, float c2r2);
	~Matrix2();

	operator float*();
	Matrix2 operator + (const Matrix2& other);
	Matrix2 operator - (const Matrix2& other);
	Matrix2 operator * (const Matrix2& other);
	Vector2 operator * (const Vector2& other);

	static Matrix2 CreateIdentity();
	Matrix2 GetTranspose();
	void setRotateZ(float angle);

private:
	float m_array[2][2];
};

