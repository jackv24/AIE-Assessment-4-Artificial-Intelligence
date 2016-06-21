#pragma once

#include "Vector4.h"

class Matrix4
{
public:
	Matrix4();
	Matrix4(float c1r1, float c1r2, float c1r3, float c1r4,
		float c2r1, float c2r2, float c2r3, float c2r4,
		float c3r1, float c3r2, float c3r3, float c3r4,
		float c4r1, float c4r2, float c4r3, float c4r4);
	~Matrix4();

	operator float*();
	Matrix4 operator + (const Matrix4& other);
	Matrix4 operator - (const Matrix4& other);
	Matrix4 operator * (const Matrix4& other);
	Vector4 operator * (const Vector4& other);

	static Matrix4 CreateIdentity();
	Matrix4 GetTranspose();
	void setRotateX(float angle);
	void setRotateY(float angle);
	void setRotateZ(float angle);

private:
	float m_array[4][4];
};

