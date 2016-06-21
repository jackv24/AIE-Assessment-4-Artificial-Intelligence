#include "Matrix2.h"
#include <math.h>

Matrix2::Matrix2()
{
	m_array[0][0] = 0;
	m_array[0][1] = 0;
	m_array[1][0] = 0;
	m_array[1][1] = 0;
}
Matrix2::Matrix2(float c1r1, float c1r2, float c2r1, float c2r2)
{
	//Matrix is column-major
	m_array[0][0] = c1r1;
	m_array[0][1] = c1r2;
	m_array[1][0] = c2r1;
	m_array[1][1] = c2r2;
}
Matrix2::~Matrix2()
{
}

Matrix2::operator float*()
{
	return *m_array;
}
Matrix2 Matrix2::operator + (const Matrix2& other)
{
	Matrix2 newMatrix;

	//Iterate through and add each value
	for (int c = 0; c < 2; c++)
		for (int r = 0; r < 2; r++)
			newMatrix.m_array[c][r] = m_array[c][r] + other.m_array[c][r];

	return newMatrix;
}
Matrix2 Matrix2::operator - (const Matrix2& other)
{
	Matrix2 newMatrix;

	//Iterate through and subtract each value
	for (int c = 0; c < 2; c++)
		for (int r = 0; r < 2; r++)
			newMatrix.m_array[c][r] = m_array[c][r] - other.m_array[c][r];

	return newMatrix;
}
Matrix2 Matrix2::operator * (const Matrix2& other)
{
	Matrix2 newMatrix;

	//Iterate through rows and columns
	for (int r = 0; r < 2; r++)
		for (int c = 0; c < 2; c++)
			//For each row on left, go through columns on right
			for (int i = 0; i < 2; i++)
				newMatrix.m_array[c][r] += m_array[i][r] * other.m_array[c][i];

	return newMatrix;
}
Vector2 Matrix2::operator * (const Vector2& other)
{
	//turn vectors into arrays for matrix operations
	float vector[2] = { other.x, other.y };
	float newVector[2] = { 0, 0 };

	//Iterate through rows and columns
	for (int c = 0; c < 2; c++)
		for (int r = 0; r < 2; r++)
			newVector[r] += m_array[c][r] * vector[c];

	//Return matrix vector as actual Vector
	return Vector2(newVector[0], newVector[1]);
}

Matrix2 Matrix2::CreateIdentity()
{
	Matrix2 identity(
		1, 0,
		0, 1);

	return identity;
}
Matrix2 Matrix2::GetTranspose()
{
	Matrix2 transpose;
	
	//Swap rows and columns
	for (int c = 0; c < 2; c++)
		for (int r = 0; r < 2; r++)
			transpose.m_array[c][r] = m_array[r][c];
	
	return transpose;
}
void Matrix2::setRotateZ(float angle)
{
	m_array[0][0] = cosf(angle);
	m_array[0][1] = sinf(angle);
	m_array[1][0] = -sinf(angle);
	m_array[1][1] = cosf(angle);
}