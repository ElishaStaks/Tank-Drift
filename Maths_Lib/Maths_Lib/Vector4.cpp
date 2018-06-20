#include "Vector4.h"
#include <math.h>


Vector4::Vector4()
{
}

//Constructor which takes in the x, y, z and w axis
Vector4::Vector4(float x, float y, float z, float w) : m_x(x), m_y(y), m_z(z), m_w(w)
{
	
}

Vector4::~Vector4()
{
	 
}

//Addition operator for vec4
Vector4 Vector4::operator+(const Vector4& other)
{
	return { m_x + other.m_x, m_y + other.m_y, m_z + other.m_z, m_w + other.m_w };
}

//Subtraction operator for vec4
Vector4 Vector4::operator-(const Vector4& other)
{
	return { m_x - other.m_x, m_y - other.m_y, m_z - other.m_z, m_w - other.m_w };
}

//Multiplication operator for vec4
Vector4 Vector4::operator*(float scalar)
{
	return { m_x * scalar, m_y * scalar, m_z * scalar, m_w * scalar };
}

//Division operator for vec4
Vector4 Vector4::operator/(float scalar)
{
	return { m_x / scalar, m_y / scalar, m_z / scalar, m_w / scalar };
}
//Addition and equal to operator for vec4
Vector4& Vector4::operator+=(const Vector4& other)
{
	m_x += other.m_x, m_y += other.m_y, m_z += other.m_z, m_w += other.m_w;
	return *this;
}

//Subtraction and equal to operator for vec4
Vector4& Vector4::operator-=(const Vector4& other)
{
	m_x -= other.m_x, m_y -= other.m_y, m_z -= other.m_z, m_w -= other.m_w;
	return *this;
}

//Multiplication and equal too operator for vec4
Vector4& Vector4::operator*=(float scalar)
{
	m_x *= scalar, m_y *= scalar, m_z *= scalar, m_w *= scalar;
	return *this;
}

//Division and equal to operator for vec4
Vector4& Vector4::operator/=(float scalar)
{
	m_x /= scalar, m_y /= scalar, m_z /= scalar, m_w /= scalar;
	return *this;
}

Vector4::operator float*()
{
	return m;
}

float Vector4::operator[](int index)
{
	return m[index];
}

//Making the vector a unit length of 1
//making the magnitude equal to 1
void Vector4::normalise()
{
	float mag = sqrt(m_x * m_x + m_y * m_y + m_z * m_z + m_w * m_w);
	m_x /= mag, m_y /= mag, m_z /= mag, m_w /= mag;
}

//Returning the square rooted magnitude
float Vector4::magnitude() const
{
	{return sqrt(m_x * m_x + m_y * m_y + m_z * m_z + m_w * m_w); };
}

//Compares if the length of the vector is bigger than or less than some value
float Vector4::magnitudeSqr() const
{
	{return (m_x * m_x + m_y * m_y + m_z * m_z + m_w * m_w); };
}

//Checks the distance between the two points of the vector
//Then checks the magnitude of the vector
float Vector4::distance(const Vector4 & other) const
{
	float diffX = m_x - other.m_x;
	float diffY = m_y - other.m_y;
	float diffZ = m_z - other.m_z;
	float diffW = m_w - other.m_w;
	return sqrt(diffX * diffX + diffY * diffY + diffZ * diffZ + diffW * diffW);
}

//dot
float Vector4::dot(const Vector4 & other) const
{
	return m_x * other.m_x + m_y * other.m_y + m_z * other.m_z + m_w * other.m_w;
}

//cross
Vector4 Vector4::cross(const Vector4 & other) const
{
	return { m_y * other.m_z - m_z * other.m_y, m_z * other.m_x - m_x * other.m_z, m_x * other.m_y - m_y * other.m_x, 0};
}

///////////////////////////////////////////////////////////
//friend + operator
Vector4 operator+(float scalar, const Vector4 & other)
{
	return Vector4 {other.m_x + scalar, other.m_y + scalar, other.m_z + scalar, other.m_w + scalar};
}

//friend - operator
Vector4 operator-(float scalar, const Vector4 & other)
{
	return Vector4 {other.m_x - scalar, other.m_y - scalar, other.m_z - scalar, other.m_w - scalar};
}

//friend * operator
Vector4 operator*(float scalar, const Vector4 & other)
{
	return Vector4 {other.m_x * scalar, other.m_y * scalar, other.m_z * scalar, other.m_w * scalar};
}

//friend / operator
Vector4 operator/(float scalar, const Vector4 & other)
{
	return Vector4 {other.m_x / scalar, other.m_y / scalar, other.m_z / scalar, other.m_w / scalar};
}
/////////////////////////////////////////////////////////////