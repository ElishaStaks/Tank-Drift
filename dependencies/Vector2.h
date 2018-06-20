#pragma once
class Vector2
{
public:

	union
	{
		//struct which holds the x and y axis for vec2
		struct
		{
			float m_x, m_y;
		};
		//if the data index 0 is called it calls the x value
		float m[2];
	};

	Vector2();
	Vector2(float x, float y);
	~Vector2();

	//creating the operations for vec2
	Vector2 operator + (const Vector2& other) const;
	Vector2 operator - (const Vector2& other) const;
	Vector2 operator * (float scalar);
	Vector2 operator / (float scalar);

	//friend operators works like inheritance
	friend Vector2 operator + (float scalar, const Vector2& other);
	friend Vector2 operator - (float scalar, const Vector2& other);
	friend Vector2 operator * (float scalar, const Vector2& other);
	friend Vector2 operator / (float scalar, const Vector2& other);

	//creating the operator and equal too vec3 operations
	Vector2& operator += (const Vector2& other);
	Vector2& operator -= (const Vector2& other);
	Vector2& operator *= (float scalar);
	Vector2& operator /= (float scalar);

	//====================== AABB =====================================//
	// utilities
	//float min(float a, float b) { return a < b ? a : b; }
	//float max(float a, float b) { return a > b ? a : b; }

	//Vector2 vmin(const Vector2& a, const Vector2& b) {
	//	return { min(a.m_x, b.m_x), min(a.m_y, b.m_y) };
	//}
	//Vector2 vmax(const Vector2& a, const Vector2& b) {
	//	return { max(a.m_x, b.m_x), max(a.m_y, b.m_y) };
	//}

	//float clamp(float t, float a, float b) {
	//	return max(a, min(b, t));
	//}
	//Vector2 clampVec2(const Vector2& t, const Vector2& a, const Vector2& b) {
	//	return vmax(a, vmin(b, t));
	//}
	//====================== AABB =====================================//

	//allows arrays with index
	float operator [] (int index);
	//converts int to float
	//eg int a = 10, float b = 20.0f
	//a = (int)f
	explicit operator float* ();

	//scales the magnitude to length 1 function
	void normalise();
	//length of the vector function
	float magnitude()const;
	//Square root the magnitude function
	float magnitudeSqr()const;
	//The distance between the points of the vector function
	float distance(const Vector2& other) const;
	//dot function
	float dot(const Vector2& other)const;
	//cross function
	Vector2 cross(const Vector2& other)const;



};
