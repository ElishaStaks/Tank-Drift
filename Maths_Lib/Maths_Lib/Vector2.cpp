#include "Vector2.h"
#include <math.h>



Vector2::Vector2()
{
}

//Constructor that takes in the x and y axis 
Vector2::Vector2(float x, float y) : m_x(x), m_y(y)
{

}

Vector2::~Vector2()
{
}


//Addition operator for vec2
Vector2 Vector2::operator+(const Vector2& other) const
{
	return { m_x + other.m_x, m_y + other.m_y };
}

//Subtraction operator for vec2
Vector2 Vector2::operator-(const Vector2 & other) const
{
	return { m_x - other.m_x, m_y - other.m_y };
}

//Multiplication operator for vec2
Vector2 Vector2::operator*(float scalar)
{
	return { m_x * scalar, m_y * scalar };
}

//Division operator for vec2
Vector2 Vector2::operator/(float scalar)
{
	return { m_x / scalar, m_y / scalar };
}

//Addition and equal to operator for vec2
Vector2& Vector2::operator+=(const Vector2 & other)
{
	m_x + other.m_x, m_y + other.m_y;
	return *this;
}

//Subtraction and equal to operator for vec2
Vector2& Vector2::operator-=(const Vector2& other)
{
	m_x -= other.m_x, m_y -= other.m_y;
	return *this;
}

//Multiplication and equal to operator for vec2
Vector2& Vector2::operator*=(float scalar)
{
	m_x * scalar, m_y * scalar;
	return *this;
}

//Division and equal to operator for vec2
Vector2& Vector2::operator/=(float scalar)
{
	m_x /= scalar, m_y /= scalar;
	return *this;
}

float Vector2::operator[](int index)
{
	return m[index];
}

Vector2::operator float* ()
{
	return m;
}

//Making the vector a unit length of 1
//making the magnitude equal to 1
void Vector2::normalise()
{
	float mag = sqrt(m_x * m_x + m_y * m_y);
	m_x /= mag, m_y /= mag;
}

//Returning the square rooted magnitude
float Vector2::magnitude()const
{
	{return sqrt(m_x * m_x + m_y * m_y); };
}

//Compares if the length of the vector is bigger than or less than some value
float Vector2::magnitudeSqr() const
{
	{return (m_x * m_x + m_y * m_y); };
}

//Checks the distance between the two points of the vector
//Then checks the magnitude of the vector
float Vector2::distance(const Vector2 & other) const
{
	float diffX = m_x - other.m_x;
	float diffY = m_y - other.m_y;
	return sqrt(diffX * diffX + diffY * diffY);
}

//dot projects a vector on another vector
float Vector2::dot(const Vector2& other) const
{
	return m_x * other.m_x + m_y * other.m_y;
}

//cross product between two vectors that result in a third vector that is perpendicular to both
Vector2 Vector2::cross(const Vector2 & other) const
{
	return { m_y * other.m_x - m_x * other.m_y, m_x * other.m_y - m_y * other.m_x };
}

///////////////////////////////////////////////////////////
//friend + operator
Vector2 operator+(float scalar, const Vector2 & other)
{
	return Vector2 {other.m_x + scalar, other.m_y + scalar};
}

//friend - operator
Vector2 operator-(float scalar, const Vector2 & other)
{
	return Vector2 {other.m_x - scalar, other.m_y - scalar};
}

//friend * operator
Vector2 operator*(float scalar, const Vector2 & other)
{
	return Vector2 { other.m_x * scalar, other.m_y * scalar};
}

//friend / operator
Vector2 operator/(float scalar, const Vector2 & other)
{
	return Vector2 {other.m_x / scalar, other.m_y / scalar};
}
/////////////////////////////////////////////////////////////
