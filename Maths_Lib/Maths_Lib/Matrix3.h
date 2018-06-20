#pragma once
#include "Vector3.h"
class Matrix3
{
public:
	//Creating a union shares same space of memory
	union
	{
		struct
		{
		    //translate variable of vector3 contents
		    //With a struct of 3x3 matrix
		    Vector3 xAxis;
		    Vector3 yAxis;
			union
			{
		     Vector3 Translate;
			 Vector3 zAxis;
			};
		};
		//Vector3 type array
		float m[9];
		Vector3 m3[3];
	};
	//Default constructor
	Matrix3();
	//Copy constructor that takes in the the positions of the 3x3 matrix
	Matrix3(float a_x, float b_x, float c_x, float a_y, float b_y, float c_y, float a_z, float b_z, float c_z);
	//Copy constructor that alows us to set the axis's
	Matrix3(const Matrix3 & other);
	//Float operator that allows us to return the index in the matrix
	Vector3& operator [] (int index);
	//This operator allows us to return the matrix itself
	explicit operator float* ();
	//sets the scale of the game object which takes in the vector3
	void setScaled(const Vector3& v);
	//scales the game object which takes in a vector3
	void scale(const Vector3& v);

	void translate(float x, float y);

	//Sets the rotation of the object
	void setRotateX(float radians);
	void setRotateY(float radians);
	void setRotateZ(float radians);
	//Rotates the object
	void rotateX(float radians);
	void rotateY(float radians);
	void rotateZ(float radians);

	//Identitiy fucntion which can return the matrix3
	static Matrix3 Identity();
	//Transpose function sets the 3x3 matrix 
	Matrix3 Transpose();
	//Multiplication operator which multiplies the matrix indexes at a const
	Matrix3 operator *(const Matrix3& a_mat) const;
	//Multiplication operator which multiplies the matrix with a vector
	Vector3 operator *(const Vector3& a_vec);
	//Deconstructor
	~Matrix3();
};

