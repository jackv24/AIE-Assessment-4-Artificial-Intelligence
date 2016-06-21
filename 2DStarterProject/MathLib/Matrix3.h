#pragma once

#include "Vector3.h"

class Matrix3
{
public:
	Matrix3();
	Matrix3(float c1r1, float c1r2, float c1r3,
		float c2r1, float c2r2, float c2r3,
		float c3r1, float c3r2, float c3r3);
	~Matrix3();

	operator float*();
	Matrix3 operator + (const Matrix3& other);
	Matrix3 operator - (const Matrix3& other);
	Matrix3 operator * (const Matrix3& other);
	Vector3 operator * (const Vector3& other);

	//Static methods to build and return new matrices
	static Matrix3 CreateIdentity();
	static Matrix3 CreateRotation(float angle);
	static Matrix3 CreateScale(const Vector3& scale);
	static Matrix3 CreateTranslation(const Vector3& translation);

	Matrix3 GetTranspose();
	void setRotateX(float angle);
	void setRotateY(float angle);
	void setRotateZ(float angle);

private:
	float m_array[3][3];
};

