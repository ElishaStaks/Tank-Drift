#include "Matrix4.h"
#include <math.h>


Matrix4::Matrix4()
{
	//Cycles through the 4x4 matrix and increments it
	for (int i = 0; i < 16; i++)
	{
		//Takes the matrix with index i which holds all the values in the 4x4 matrix such as 16
		m[i] = 0;
	}
}

//Sets the index values to each position
Matrix4::Matrix4(float a_x, float b_x, float c_x, float d_x, float a_y, float b_y, float c_y, float d_y, float a_z, float b_z, float c_z, float d_z,
	             float a_w, float b_w, float c_w, float d_w)
{
	//                                                                                                                        4x4
	//matrix index |0| = a_x     matrix index |4| = a_y    matrix index |8| = a_z     matrix index |12| = a_w          |  0  4  8  12  |
	//matrix index |1| = b_x     matrix index |5| = b_y    matrix index |9| = b_z     matrix index |13| = b_w          |  1  5  9  13  |
	//matrix index |2| = c_x     matrix index |6| = c_y    matrix index |10| = c_z    matrix index |14| = c_w          |  2  6  10 14  |
	//matrix index |3| = d_x    matrix index |7| = d_y   matrix index |11| = d_z    matrix index |15| = d_w            |  3  7  11 15  |

	m[0] = a_x;
	m[1] = b_x;
	m[2] = c_x;
	m[3] = d_x;
	m[4] = a_y;
	m[5] = b_y;
	m[6] = c_y;
	m[7] = d_y;
	m[8] = a_z;
	m[9] = b_z;
	m[10] = c_z;
	m[11] = d_z;
	m[12] = a_w;
	m[13] = b_w;
	m[14] = c_w;
	m[15] = d_w;
}

//Setting the axis's and the indexes to a constant type which will never change
//The axis's meaning the points of the matrix
Matrix4::Matrix4(const Matrix4 & other)
{
	m[0] = other.m[0];
	m[1] = other.m[1];
	m[2] = other.m[2];
	m[3] = other.m[3];
	m[4] = other.m[4];
	m[5] = other.m[5];
	m[6] = other.m[6];
	m[7] = other.m[7];
	m[8] = other.m[8];
	m[9] = other.m[9];
	m[10] = other.m[10];
	m[11] = other.m[11];
	m[12] = other.m[12];
	m[13] = other.m[13];
	m[14] = other.m[14];
	m[15] = other.m[15];
}

//Returns the matrix's index
Vector4& Matrix4::operator[](int index)
{
	return m4[index];
}

//Returns the matrix
Matrix4::operator float*()
{
	return m;
}

///////////////////////////////////////////////////////////////////////////// ROTATION ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Sets the rotate for the X axis
void Matrix4::setRotateX(float radians)
{
	//leave X axis and elements unchanged                        //============== VISUAL REPRESENTATION =============//
	*this = { 1,         0,           0,          0,
			  0,  cosf(radians),  sinf(radians),  0,               // | X  X  X  0 |<------- Translation/ Transform         //  Bottom numbers all represent the translation of the 4th index 
		      0, -sinf(radians),   cosf(radians), 0,               // | X  X  X  0 |<------- Translation/ Transform			// *The 'X' represents the values for Matrix 2 and 3*
		      0,         0,           0,          1 };             // | X  X  X  0 |<------- Translation/ Transform			// *The 4 numbers on the bottom and the right side are for matrix 4*
}	                                                               // | 0  0  0  1 |<------- Translation/ Transform   															                                                                               
																 
//Sets the rotatation for the Y axis                                 
void Matrix4::setRotateY(float radians)
{
	*this = { cosf(radians), 0, -sinf(radians), 0,               //EXAMPLE WITH THE VISUALISATION ABOVE APPLYS TO ALL 4 AXIS
		      0,             1,        0,       0,                                        
		      sinf(radians), 0, cosf(radians),  0, 
	          0,             0,        0,       1};
}
//Sets the rotatation for the Z axis
void Matrix4::setRotateZ(float radians)
{
	*this = { cosf(radians), sinf(radians),    0,   0,
		      -sinf(radians),  cosf(radians),  0,   0,            //EXAMPLE WITH THE VISUALISATION ABOVE APPLYS TO ALL 4 AXIS
		           0,              0,          1,   0,
	               0,              0,          0,   1};
}
//You add the value at which you would like to rotate the X axis in this function
void Matrix4::rotateX(float radians)
{
	Matrix4 m;
	m.setRotateX(radians);
	*this = *this * m;
}
//You add the value at which you would like to rotate the X axis in this function
void Matrix4::rotateY(float radians)
{
	Matrix4 m;
	m.setRotateY(radians);
	*this = *this * m;
}
//You add the value at which you would like to rotate the X axis in this function
void Matrix4::rotateZ(float radians)
{
	Matrix4 m;
	m.setRotateZ(radians);
	*this = *this * m;
}
/////////////////////////////////////////////////////////////////// ROTATION ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//sets up an unrotated scaled matrix
void Matrix4::setScaled(const Vector4& v)
{
	//set scale of the axis
	*this = { v.m_x, 0, 0, 0,
			  0, v.m_y, 0, 0,
			  0, 0, v.m_z, 0,
			  0, 0, 0, v.m_w };
}

//where to set the value of how big you want the object to be
void Matrix4::scale(const Vector4 & v)
{
	Matrix4 m;
	m.setScaled(v);
	*this = *this * m;
}

//Identity matrix is a square matrix with main diagonal elements as 1 and the rest is 0
//This is a 4x4 identity matrix
Matrix4 Matrix4::Identity()
{
	return Matrix4(1.0f, 0.0f, 0.0f, 0.0f,
		           0.0f, 1.0f, 0.0f, 0.0f,
		           0.0f, 0.0f, 1.0f, 0.0f,
	               0.0f, 0.0f, 0.0f, 1.0f);
}

//This is the columns and rows of a 4x4 matrix 
Matrix4 Matrix4::Transpose()
{
	return Matrix4(m[0], m[4], m[8], m[12],
		           m[1], m[5], m[9], m[13],
		           m[2], m[6], m[10], m[14],
		           m[3], m[7], m[11], m[15]);
}
//                                                                                                                                                                                                          *Refer to the multiplication table on the left and follow how the table below works*
//                                                                                                                                                                                                                        *Also refer to your exercise book with heaps of examples*
//============================== MATRIX MULTIPLICATION 4X4 =========================//
// *Row(right)*    | m[0]  m[4]  m[8]  m[12]  |      | a_m[0]  a_m[4]  a_m[8]  a_m[12] |            Step 1: Multiply the first matrix row by the whole second matrix on the right           // | 0x0 + 4x1 + 8x2 + 12x3 + 0x4 + 4x5 + 8x6 + 12x7 + 0x8 + 4x9 + 8x10 + 12x11 + 0x12 + 4x13 + 8x14 + 12x15       | <--- first row   
//                 | m[1]  m[5]  m[9]  m[13]  |  *   | a_m[1]  a_m[5]  a_m[9]  a_m[13] |            Step 2: Multiply the second matrix row by the whole second matrix on the right	        // | 1x0 + 5x1 + 9x2 + 13x3 + 1x4 + 5x5 + 9x6 + 13x7 + 1x8 + 5x9 + 9x10 + 13x11 + 1x12 + 5x13 + 9x14 + 13x15       | <--- second row        
// *Column(down)*  | m[2]  m[6]  m[10] m[14]  |      | a_m[2]  a_m[6]  a_m[10] a_m[14] |            Step 3: Multiply the third matrix row by the whole second matrix on the right           // | 2x0 + 6x1 + 10x2 + 14x3 + 2x4 + 6x5 + 10x6 + 14x7 + 2x8 + 6x9 + 10x10 + 14x11 + 2x12 + 6x13 + 10x14 + 14x15   | <--- third row
//                 | m[3]  m[7]  m[11] m[15]  |	     | a_m[3]  a_m[7]  a_m[11] a_m[15] |            Step 4: Multiply the fourth matrix row by the whole second matrix on the right          // | 3x0 + 7x1 + 11x2 + 15x3 + 3x4 + 7x5 + 11x6 + 15x7 + 3x8 + 7x9 + 11x10 + 15x11 + 3x12 + 7x13 + 11x14 + 15x15   | <--- fouth row
Matrix4 Matrix4::operator*(const Matrix4 & a_mat) const
{
	return Matrix4(m[0] * a_mat.m[0] + m[4] * a_mat.m[1] + m[8] * a_mat.m[2] + m[12] * a_mat.m[3],
	               m[1] * a_mat.m[0] + m[5] * a_mat.m[1] + m[9] * a_mat.m[2] + m[13] * a_mat.m[3],
	               m[2] * a_mat.m[0] + m[6] * a_mat.m[1] + m[10] * a_mat.m[2] + m[14] * a_mat.m[3],
	               m[3] * a_mat.m[0] + m[7] * a_mat.m[1] + m[11] * a_mat.m[2] + m[15] * a_mat.m[3],
	               
	               m[0] * a_mat.m[4] + m[4] * a_mat.m[5] + m[8] * a_mat.m[6] + m[12] * a_mat.m[7],
	               m[1] * a_mat.m[4] + m[5] * a_mat.m[5] + m[9] * a_mat.m[6] + m[13] * a_mat.m[7],
	               m[2] * a_mat.m[4] + m[6] * a_mat.m[5] + m[10] * a_mat.m[6] + m[14] * a_mat.m[7],
	               m[3] * a_mat.m[4] + m[7] * a_mat.m[5] + m[11] * a_mat.m[6] + m[15] * a_mat.m[7],
	               
	               m[0] * a_mat.m[8] + m[4] * a_mat.m[9] + m[8] * a_mat.m[10] + m[12] * a_mat.m[11],
	               m[1] * a_mat.m[8] + m[5] * a_mat.m[9] + m[9] * a_mat.m[10] + m[13] * a_mat.m[11],
	               m[2] * a_mat.m[8] + m[6] * a_mat.m[9] + m[10] * a_mat.m[10] + m[14] * a_mat.m[11],
	               m[3] * a_mat.m[8] + m[7] * a_mat.m[9] + m[11] * a_mat.m[10] + m[15] * a_mat.m[11],
	               
	               m[0] * a_mat.m[12] + m[4] * a_mat.m[13] + m[8] * a_mat.m[14] + m[12] * a_mat.m[15],
	               m[1] * a_mat.m[12] + m[5] * a_mat.m[13] + m[9] * a_mat.m[14] + m[13] * a_mat.m[15],
	               m[2] * a_mat.m[12] + m[6] * a_mat.m[13] + m[10] * a_mat.m[14] + m[14] * a_mat.m[15],
	               m[3] * a_mat.m[12] + m[7] * a_mat.m[13] + m[11] * a_mat.m[14] + m[15] * a_mat.m[15]);
}

//Multiplying a matrix with a vector
//Transformation/ Translation
Vector4 Matrix4::operator*(const Vector4 & a_vec)
{
	return Vector4(m[0] * a_vec.m_x + m[4] * a_vec.m_y + m[8] * a_vec.m_z + m[12] * a_vec.m_w,
		           m[1] * a_vec.m_x + m[5] * a_vec.m_y + m[9] * a_vec.m_z + m[13] * a_vec.m_w, 
		           m[2] * a_vec.m_x + m[6] * a_vec.m_y + m[10] * a_vec.m_z + m[14] * a_vec.m_w, 
		           m[3] * a_vec.m_x + m[7] * a_vec.m_y + m[11] * a_vec.m_z + m[15] * a_vec.m_w);
}

//Deconstructor
Matrix4::~Matrix4()
{

}