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
		float m[3];
	};

	Vector3();
	Vector3(float x, float y, float z);
	~Vector3();

	//creating the normal vec3 operations
	Vector3 operator + (const Vector3& other);
	Vector3 operator - (const Vector3& other);
	Vector3 operator * (float scalar);
	Vector3 operator / (float scalar);

	//friend operators works like inheritance
	friend Vector3 operator + (float scalar, const Vector3& other);
	friend Vector3 operator - (float scalar, const Vector3& other);
	friend Vector3 operator * (float scalar, const Vector3& other);
	friend Vector3 operator / (float scalar, const Vector3& other);


	//creating the operator and equal too vec3 operations
	Vector3& operator += (const Vector3& other);
	Vector3& operator -= (const Vector3& other);
	Vector3& operator *= (float scalar);
	Vector3& operator /= (float scalar);

	// Finds the angle between a vector 3
	float angleBetween(const Vector3& a, const Vector3& b);

	//converts int to float
	//eg int a = 10, float b = 20.0f
	//a = (int)f
	explicit operator float* ();
	float operator [] (int index);

	//scales the magnitude to length 1 function
	void normalise();
	Vector3 normalised();
	//length of the vector function
	float magnitude()const;
	//Square root the magnitude function
	float magnitudeSqr()const;
	//The distance between the points of the vector function
	float distance(const Vector3& other) const;
	static float dot(const Vector3& a, const Vector3& b);
	float dot(const Vector3& other)const;
	Vector3 cross(const Vector3& other)const;



	
};
