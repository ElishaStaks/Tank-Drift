#include "Vector3.h"
#include <math.h>



Vector3::Vector3()
{
	m_x = 0;
	m_y = 0;
	m_z = 0;
}

//Constructor which takes in the x, y and z axis
Vector3::Vector3(float x, float y, float z) : m_x(x), m_y(y), m_z(z)
{

}

Vector3::~Vector3()
{

}

//Addition operator for vec3
Vector3 Vector3::operator+(const Vector3& other)
{
	return { m_x + other.m_x, m_y + other.m_y, m_z + other.m_z };
}

//Subtraction operator for vec3
Vector3 Vector3::operator-(const Vector3 & other)
{
	return { m_x - other.m_x, m_y - other.m_y, m_z - other.m_z };
}

//Multiplication operator for vec3
Vector3 Vector3::operator*(float scalar)
{
	return { m_x * scalar, m_y * scalar, m_z * scalar };
}

//Division operator for vec3
Vector3 Vector3::operator/(float scalar)
{
	return { m_x / scalar, m_y / scalar, m_z / scalar };
}

Vector3::operator float*()
{
	return m;
}

float Vector3::operator[](int index)
{
	return m[index];
}

//Addition and equal to operator for vec3
Vector3& Vector3::operator+=(const Vector3 & other)
{
	m_x += other.m_x, m_y += other.m_y, m_z += other.m_z;
	return *this;
}

//Subtraction and equal to operator for vec3
Vector3& Vector3::operator-=(const Vector3& other)
{
	m_x -= other.m_x, m_y -= other.m_y, m_z -= other.m_z;
	return *this;
}

//Multiplication and equal too operator for vec3
Vector3& Vector3::operator*=(float scalar)
{
	m_x *= scalar, m_y *= scalar, m_z *= scalar;
	return *this;
}

//Division and equal to operator for vec3
Vector3& Vector3::operator/=(float scalar)
{
	m_x /= scalar, m_y /= scalar, m_z /= scalar;
	return *this;
}
// finds the angle between the vector
float Vector3::angleBetween(const Vector3 & a, const Vector3 & b)
{
	//               /   a * b   \
	//               |  -------  |       
	// angle = cos^-1\  |a|*|b|  /
	float angle = acosf(Vector3::dot(a, b));

	// finds perpendicular (90 degree angle) vector by finding the cross product
	Vector3 perpendicular = b.cross({ 0, 0, 1 });

	// finds what side of the target vector this vector is on 
	float m_dot = Vector3::dot(perpendicular, a);

	if (m_dot < 0.0f)
	{
		angle = (2.0f* 3.1415f) - angle;
	}

	return angle;
}

//Making the vector a unit length of 1
//making the magnitude equal to 1
void Vector3::normalise()
{
	float mag = sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
	m_x /= mag, m_y /= mag, m_z /= mag;
}

//Making the vector a unit length of 1
//making the magnitude equal to 1
Vector3 Vector3::normalised()
{
	float mag = sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
	return { m_x / mag, m_y / mag, m_z / mag };
}

//Returning the square rooted magnitude
float Vector3::magnitude() const
{
	{return sqrt(m_x * m_x + m_y * m_y + m_z * m_z); };
}

//Compares if the length of the vector is bigger than or less than some value
float Vector3::magnitudeSqr() const
{
	{return (m_x * m_x + m_y * m_y + m_z * m_z); };
}

//Checks the distance between the two points of the vector
//Then checks the magnitude of the vector
float Vector3::distance(const Vector3 & other) const
{
	float diffX = m_x - other.m_x;
	float diffY = m_y - other.m_y;
	float diffZ = m_z - other.m_z;
	return sqrt(diffX * diffX + diffY * diffY + diffZ * diffZ);
}
//dot product for angle between
float Vector3::dot(const Vector3 & a, const Vector3 & b)
{
	return a.m_x * b.m_x + a.m_y * b.m_y + a.m_z * b.m_z;
}

//dot
float Vector3::dot(const Vector3 & other) const
{
	return m_x * other.m_x + m_y * other.m_y + m_z * other.m_z;
}

//cross
Vector3 Vector3::cross(const Vector3 & other) const
{
	return { m_y * other.m_z - m_z * other.m_y, m_z * other.m_x - m_x * other.m_z, m_x * other.m_y - m_y * other.m_x };
}

///////////////////////////////////////////////////////////
//friend + operator
Vector3 operator+(float scalar, const Vector3 & other)
{
	return Vector3 { other.m_x + scalar, other.m_y + scalar, other.m_z + scalar};
}

//friend - operator
Vector3 operator-(float scalar, const Vector3 & other)
{
	return Vector3 {other.m_x - scalar, other.m_y - scalar, other.m_z - scalar};
}

//friend * operator
Vector3 operator*(float scalar, const Vector3 & other)
{
	return Vector3 {other.m_x * scalar, other.m_y * scalar, other.m_z * scalar};
}

//friend / operator
Vector3 operator/(float scalar, const Vector3 & other)
{
	return Vector3 {other.m_x / scalar, other.m_y / scalar, other.m_z / scalar};
}

/////////////////////////////////////////////////////////////

