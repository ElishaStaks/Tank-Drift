#pragma once
#include <Vector2.h>
#include <vector>
#include <math.h>

// simple axis-aligned bounding box that stores min/max
class AABB
{
public:
	AABB() {}
	// copy constructor that takes in the min size and max size of the square hit box
	AABB(const Vector2& min, const Vector2& max);
	~AABB();
	// min and max values of vector2 type
	Vector2 minimum, maximum;
	// Center: works out the center of the box
	Vector2 center() const;
	// Extents: calculates the half extents
	Vector2 extents() const;
	// ClosestPoint: finds the closest point to an AABB
	Vector2 closestPoint(const Vector2& p) const;
	// Corners: returns all corners of the hit collision box
	std::vector<Vector2> corners() const;
	// Fit: fitting an AABB to a collection of points (fits the hit box around the objects scale)
	void fit(const Vector2* points, unsigned int count);
	// VecFit: Container points method (same as above)
	void vecFit(const std::vector<Vector2>& points);
	// OverLap: tests if the points are contained within the AABB
	bool firstOverLaps(const Vector2& p) const;
	bool secondOverLaps(const AABB& other) const;

	//===================== MATH LIB STUFF ==========================//

	// Min: Returns min value 
	float min(float a, float b) const { return a < b ? a : b; }
	// Max: Returns max value  
	float max(float a, float b) const { return a > b ? a : b; }
	// Returns a vector whose components are created from the minimum components of the two passed values in the parameter vector
	Vector2 m_min(const Vector2& a, const Vector2& b) const {
		return { min(a.m_x, b.m_x), min(a.m_y, b.m_y) };
	}
	// Returns a vector whose components are created from the maximum components of the two passed values in the parameter vector
	Vector2 m_max(const Vector2& a, const Vector2& b) const {
		return { max(a.m_x, b.m_x), max(a.m_y, b.m_y) };
	}

	// Clamp: a method that clamps a specified value t within the range specified by the min and max values
	float clamp(float t, float a, float b) const {
		return max(a, min(b, t));
	}
	// Clamp: a method that clamps a specified value t within the range specified by the min and max values
	//*Vector2 version*
	Vector2 clampVec(const Vector2& t, const Vector2& a, const Vector2& b) const {
		return m_max(a, m_min(b, t));
	}

	//===================== MATH LIB STUFF ==========================//

};