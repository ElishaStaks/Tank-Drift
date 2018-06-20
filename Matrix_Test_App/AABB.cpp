#include "AABB.h"

// copy constructor 
AABB::AABB(const Vector2 & min, const Vector2 & max) : minimum(min), maximum(max)
{
}

AABB::~AABB()
{
}

// Center: finds the center of the box by finding the point in between the min and max value
Vector2 AABB::center() const
{
	// add the min and max and times it by half or you can divide
	return (minimum + maximum) * 0.5f;
}
// Extents: calculate the half extents by subtracting the max point from the min point and then half the value for each vector component by multiplying by 0.5
Vector2 AABB::extents() const
{
	// subract max by min value then multiply it by half or you can divide
	return { abs(maximum.m_x - minimum.m_x) * 0.5f,
			abs(maximum.m_y - minimum.m_y) * 0.5f };
}
// ClosestPoint: its necessary to find the closest point on the surface of the AABB to an arbitrary point
// We do this by simply using the clamp function which then points to the min and max corners of the box
Vector2 AABB::closestPoint(const Vector2 & p) const
{
	return clampVec(p, minimum, maximum);
}
// Corners: returns the corner of the box using the min and max values, 2D we return 4 corners
std::vector<Vector2> AABB::corners() const
{
	// indicates 4 corners
	 std::vector<Vector2>corners(4);
	 // corner 1 = minimum value
	 corners[0] = minimum;
	 corners[1] = { minimum.m_x, maximum.m_y };
	 corners[2] = maximum;
	 corners[3] = { maximum.m_x, minimum.m_y };
	 // returns all 4 corners
	 return corners;
}
// Fit: given a set of points we can calculate a bounding region that encapulate them and fit an AABB around the points
// To do this we need to find the min and max components from all points
// First we invalidate our current min and max by setting min to the largest value and max to the smallest value possible
void AABB::fit(const Vector2* points, unsigned int count)
{
	// invalidate extents
	minimum = { FLT_MAX, FLT_MAX };
	maximum = { FLT_MIN, FLT_MIN };

	// find min and max of the points by looping through all the points and find the min() and max()
	for (unsigned int i = 0; i < count; ++i, ++points) {
		minimum = m_min(minimum, *points);
		maximum = m_max(maximum, *points);
	}
}
// VecFit: Same method from above can be implemented on a container points
void AABB::vecFit(const std::vector<Vector2>& points)
{
	// invalidate extents
	minimum = { FLT_MAX, FLT_MAX };
	maximum = { FLT_MIN, FLT_MIN };

	// find min and max points
	for (auto& p : points) {
		minimum = m_min(minimum, p);
		maximum = m_max(maximum, p);
	}
}
// OverLaps: tests if a point is contained within an AABB 
// This checks if the point is within the range of the min and max corners
// if any component of the point is outside of these ranges then there is no overlap and we can return straight away
bool AABB::firstOverLaps(const Vector2 & p) const
{
	// test for not overlapped as it exists faster
	return !(p.m_x < minimum.m_x || p.m_y < minimum.m_y || p.m_x > maximum.m_x ||
		     p.m_y > maximum.m_y);
}

bool AABB::secondOverLaps(const AABB & other) const
{
	// test for not overlapped as it exists faster
	return !(maximum.m_x < other.minimum.m_x || maximum.m_y < other.minimum.m_y ||
		     minimum.m_x > other.maximum.m_x || minimum.m_y > other.maximum.m_y);
}
