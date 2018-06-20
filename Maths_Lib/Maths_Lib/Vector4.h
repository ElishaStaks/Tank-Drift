#pragma once
class Vector4
{
public:
	union
	{
		//struct which holds the x, y, z  and w axis for vec4
		struct
		{
			float m_x, m_y, m_z, m_w;
		};
		float m[4];
	};

	Vector4();
	//copy constructor
	Vector4(float x, float y, float z, float w);
	~Vector4();

	//creating the normal vec3 operations
	Vector4 operator + (const Vector4& other);
	Vector4 operator - (const Vector4& other);
	Vector4 operator * (float scalar);
	Vector4 operator / (float scalar);

	//friend operators works like inheritance
	friend Vector4 operator + (float scalar, const Vector4& other);
	friend Vector4 operator - (float scalar, const Vector4& other);
	friend Vector4 operator * (float scalar, const Vector4& other);
	friend Vector4 operator / (float scalar, const Vector4& other);

	//creating the operator and equal too vec3 operations
	Vector4& operator += (const Vector4& other);
	Vector4& operator -= (const Vector4& other);
	Vector4& operator *= (float scalar);
	Vector4& operator /= (float scalar);

	//converts int to float
	//eg int a = 10, float b = 20.0f
	//a = (int)f
	explicit operator float* ();
	float operator [] (int index);

	//scales the magnitude to length 1 function
	void normalise();
	//length of the vector function
	float magnitude()const;
	//Square root the magnitude function
	float magnitudeSqr()const;
	//The distance between the points of the vector function
	float distance(const Vector4& other) const;

	float dot(const Vector4& other)const;
	Vector4 cross(const Vector4& other)const;

};

