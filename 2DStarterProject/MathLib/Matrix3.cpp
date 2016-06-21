#include "Matrix3.h"
#include <math.h>

Matrix3::Matrix3()
{
	for (int c = 0; c < 3; c++)
		for (int r = 0; r < 3; r++)
			m_array[c][r] = 0;
}
Matrix3::Matrix3(float c1r1, float c1r2, float c1r3,
	float c2r1, float c2r2, float c2r3,
	float c3r1, float c3r2, float c3r3)
{
	//Matrix is column-major
	m_array[0][0] = c1r1;
	m_array[0][1] = c1r2;
	m_array[0][2] = c1r3;
	m_array[1][0] = c2r1;
	m_array[1][1] = c2r2;
	m_array[1][2] = c2r3;
	m_array[2][0] = c3r1;
	m_array[2][1] = c3r2;
	m_array[2][2] = c3r3;
}
Matrix3::~Matrix3()
{
}

Matrix3::operator float*()
{
	return *m_array;
}
Matrix3 Matrix3::operator + (const Matrix3& other)
{
	Matrix3 newMatrix;

	//Iterate through and add each value
	for (int c = 0; c < 3; c++)
		for (int r = 0; r < 3; r++)
			newMatrix.m_array[c][r] = m_array[c][r] + other.m_array[c][r];

	return newMatrix;
}
Matrix3 Matrix3::operator - (const Matrix3& other)
{
	Matrix3 newMatrix;

	//Iterate through and subtract each value
	for (int c = 0; c < 3; c++)
		for (int r = 0; r < 3; r++)
			newMatrix.m_array[c][r] = m_array[c][r] - other.m_array[c][r];

	return newMatrix;
}
Matrix3 Matrix3::operator * (const Matrix3& other)
{
	Matrix3 newMatrix;

	//Iterate through rows and columns
	for (int r = 0; r < 3; r++)
		for (int c = 0; c < 3; c++)		
			//For each row on left, go through columns on right
			for (int i = 0; i < 3; i++)
				newMatrix.m_array[c][r] += m_array[i][r] * other.m_array[c][i];

	return newMatrix;
}
Vector3 Matrix3::operator * (const Vector3& other)
{
	//turn vectors into arrays for matrix operations
	float vector[3] = { other.x, other.y, other.z };
	float newVector[3] = { 0, 0, 0 };

	//Iterate through rows and columns
	for (int c = 0; c < 3; c++)
		for (int r = 0; r < 3; r++)
			newVector[r] += m_array[c][r] * vector[c];

	//Return matrix vector as actual Vector
	return Vector3(newVector[0], newVector[1], newVector[2]);
}

Matrix3 Matrix3::CreateIdentity()
{
	Matrix3 identity(
		1, 0, 0,
		0, 1, 0,
		0, 0, 1);

	return identity;
}
Matrix3 Matrix3::CreateRotation(float angle)
{
	Matrix3 newMatrix = CreateIdentity();

	newMatrix.m_array[0][0] = cosf(angle);
	newMatrix.m_array[0][1] = sinf(angle);
	newMatrix.m_array[1][0] = -sinf(angle);
	newMatrix.m_array[1][1] = cosf(angle);

	return newMatrix;
}
Matrix3 Matrix3::CreateScale(const Vector3& scale)
{
	Matrix3 newMatrix = CreateIdentity();

	newMatrix.m_array[0][0] = scale.x;
	newMatrix.m_array[1][1] = scale.y;

	return newMatrix;
}
Matrix3 Matrix3::CreateTranslation(const Vector3& translation)
{
	Matrix3 newMatrix = CreateIdentity();

	newMatrix.m_array[2][0] = translation.x;
	newMatrix.m_array[2][1] = translation.y;
	newMatrix.m_array[2][2] = 1.0f;

	return newMatrix;
}

Matrix3 Matrix3::GetTranspose()
{
	Matrix3 transpose;

	//Swap rows and columns
	for (int c = 0; c < 3; c++)
		for (int r = 0; r < 3; r++)
			transpose.m_array[c][r] = m_array[r][c];

	return transpose;
}
void Matrix3::setRotateX(float angle)
{
	m_array[0][0] = 1;
	m_array[0][1] = 0;
	m_array[0][2] = 0;
	m_array[1][0] = 0;
	m_array[1][1] = cosf(angle);
	m_array[1][2] = sinf(angle);
	m_array[2][0] = 0;
	m_array[2][1] = -sinf(angle);
	m_array[2][2] = cosf(angle);
}
void Matrix3::setRotateY(float angle)
{
	m_array[0][0] = cosf(angle);
	m_array[0][1] = 0;
	m_array[0][2] = -sinf(angle);
	m_array[1][0] = 0;
	m_array[1][1] = 1;
	m_array[1][2] = 0;
	m_array[2][0] = sinf(angle);
	m_array[2][1] = 0;
	m_array[2][2] = cosf(angle);
}
void Matrix3::setRotateZ(float angle)
{
	m_array[0][0] = cosf(angle);
	m_array[0][1] = sinf(angle);
	m_array[0][2] = 0;
	m_array[1][0] = -sinf(angle);
	m_array[1][1] = cosf(angle);
	m_array[1][2] = 0;
	m_array[2][0] = 0;
	m_array[2][1] = 0;
	m_array[2][2] = 1;
}