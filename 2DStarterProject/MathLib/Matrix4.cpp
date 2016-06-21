#include "Matrix4.h"
#include <math.h>

Matrix4::Matrix4()
{
	//Iterate through and zero out
	for (int c = 0; c < 4; c++)
		for (int r = 0; r < 4; r++)
			m_array[c][r] = 0;
}
Matrix4::Matrix4(float c1r1, float c1r2, float c1r3, float c1r4,
	float c2r1, float c2r2, float c2r3, float c2r4,
	float c3r1, float c3r2, float c3r3, float c3r4,
	float c4r1, float c4r2, float c4r3, float c4r4)
{
	//Matrix is column-major
	m_array[0][0] = c1r1;
	m_array[0][1] = c1r2;
	m_array[0][2] = c1r3;
	m_array[0][3] = c1r4;
	m_array[1][0] = c2r1;
	m_array[1][1] = c2r2;
	m_array[1][2] = c2r3;
	m_array[1][3] = c2r4;
	m_array[2][0] = c3r1;
	m_array[2][1] = c3r2;
	m_array[2][2] = c3r3;
	m_array[2][3] = c3r4;
	m_array[3][0] = c4r1;
	m_array[3][1] = c4r2;
	m_array[3][2] = c4r3;
	m_array[3][3] = c4r4;
}
Matrix4::~Matrix4()
{
}

Matrix4::operator float*()
{
	return *m_array;
}
Matrix4 Matrix4::operator + (const Matrix4& other)
{
	Matrix4 newMatrix;

	//Iterate through and add each value
	for (int c = 0; c < 4; c++)
		for (int r = 0; r < 4; r++)
			newMatrix.m_array[c][r] = m_array[c][r] + other.m_array[c][r];

	return newMatrix;
}
Matrix4 Matrix4::operator - (const Matrix4& other)
{
	Matrix4 newMatrix;

	//Iterate through and subtract each value
	for (int c = 0; c < 4; c++)
		for (int r = 0; r < 4; r++)
			newMatrix.m_array[c][r] = m_array[c][r] - other.m_array[c][r];

	return newMatrix;
}
Matrix4 Matrix4::operator * (const Matrix4& other)
{
	Matrix4 newMatrix;

	//Iterate through rows and columns
	for (int r = 0; r < 4; r++)
		for (int c = 0; c < 4; c++)
			//For each row on left, go through columns on right
			for (int i = 0; i < 4; i++)
				newMatrix.m_array[c][r] += m_array[i][r] * other.m_array[c][i];

	return newMatrix;
}
Vector4 Matrix4::operator * (const Vector4& other)
{
	//turn vectors into arrays for matrix operations
	float vector[4] = { other.x, other.y, other.z, other.w };
	float newVector[4] = { 0, 0, 0, 0 };

	//Iterate through rows and columns
	for (int c = 0; c < 4; c++)
		for (int r = 0; r < 4; r++)
			newVector[r] += m_array[c][r] * vector[c];

	//Return matrix vector as actual Vector
	return Vector4(newVector[0], newVector[1], newVector[2], newVector[3]);
}

Matrix4 Matrix4::CreateIdentity()
{
	Matrix4 identity(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1);

	return identity;
}
Matrix4 Matrix4::GetTranspose()
{
	Matrix4 transpose;

	//Swap rows and columns
	for (int c = 0; c < 4; c++)
		for (int r = 0; r < 4; r++)
			transpose.m_array[c][r] = m_array[r][c];

	return transpose;
}
void Matrix4::setRotateX(float angle)
{
	m_array[0][0] = 1;
	m_array[0][1] = 0;
	m_array[0][2] = 0;
	m_array[0][3] = 0;

	m_array[1][0] = 0;
	m_array[1][1] = cosf(angle);
	m_array[1][2] = sinf(angle);
	m_array[1][3] = 0;

	m_array[2][0] = 0;
	m_array[2][1] = -sinf(angle);
	m_array[2][2] = cosf(angle);
	m_array[2][3] = 0;

	m_array[3][0] = 0;
	m_array[3][1] = 0;
	m_array[3][2] = 0;
	m_array[3][3] = 1;
}
void Matrix4::setRotateY(float angle)
{
	m_array[0][0] = cosf(angle);
	m_array[0][1] = 0;
	m_array[0][2] = -sinf(angle);
	m_array[0][3] = 0;

	m_array[1][0] = 0;
	m_array[1][1] = 1;
	m_array[1][2] = 0;
	m_array[1][3] = 0;

	m_array[2][0] = sinf(angle);
	m_array[2][1] = 0;
	m_array[2][2] = cosf(angle);
	m_array[2][3] = 0;

	m_array[3][0] = 0;
	m_array[3][1] = 0;
	m_array[3][2] = 0;
	m_array[3][3] = 1;
}
void Matrix4::setRotateZ(float angle)
{
	m_array[0][0] = cosf(angle);
	m_array[0][1] = sinf(angle);
	m_array[0][2] = 0;
	m_array[0][3] = 0;

	m_array[1][0] = -sinf(angle);
	m_array[1][1] = cosf(angle);
	m_array[1][2] = 0;
	m_array[1][3] = 0;

	m_array[2][0] = 0;
	m_array[2][1] = 0;
	m_array[2][2] = 1;
	m_array[2][3] = 0;

	m_array[3][0] = 0;
	m_array[3][1] = 0;
	m_array[3][2] = 0;
	m_array[3][3] = 1;
}