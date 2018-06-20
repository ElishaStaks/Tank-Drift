#pragma once
class Vector3
{
public:

	union
	{
		//struct which holds the x, y and z axis for vec3
		struct
		{
			float m_x, m_y, m_z;
		};
	};

	Vector3();
	Vector3(float x, float y, float z);

	//creating the vec3 operations
	Vector3 operator + (const Vector3& other);
	Vector3 operator - (const Vector3& other);
	Vector3 operator -= (const Vector3& other);
	Vector3 operator * (float scalar);
	Vector3 operator / (float scalar);
	Vector3 operator /= (float scalar);

	//scales the magnitude to length 1 function
	Vector3 normalised()const;
	//length of the vector function
	float magnitude()const;
	//Square root the magnitude function
	float magnitudeSqr()const;
	//The distance between the points of the vector function
	float distance(const Vector3& other) const;


	~Vector3();
};
