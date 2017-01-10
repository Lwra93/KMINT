#pragma once
#include <math.h>
#include <windows.h>
#include <iosfwd>
#include <limits>
class Vector2D
{
public:
	Vector2D  Perps()const;
public:
	double x;
	double y;

	Vector2D() :x(0.0), y(0.0) {}
	Vector2D(double a, double b) :x(a), y(b) {}

	//sets x and y to zero
	void Zero() { x = 0.0; y = 0.0; }

	//returns true if both x and y are zero
	bool isZero()const { return (x*x + y*y) < (std::numeric_limits<double>::min)(); }

	//returns the length of the vector
	double    Length()const;

	//returns the squared length of the vector (thereby avoiding the sqrt)
	double    LengthSq()const;

	void      Normalize();

	double Vec2DDistanceSq(const Vector2D & v1, const Vector2D & v2);

	void WrapAround(int MaxX, int MaxY);

	double    Dot(const Vector2D& v2)const;

	//returns positive if v2 is clockwise of this vector,
	//negative if anticlockwise (assuming the Y axis is pointing down,
	//X axis to right like a Window app)
	int       Sign(const Vector2D& v2)const;

	//returns the vector that is perpendicular to this one.
	Vector2D  Perp()const;



	//adjusts x and y so that the length of the vector does not exceed max
	void      Truncate(double max);

	//returns the distance between this vector and th one passed as a parameter
	double    Distance(const Vector2D &v2)const;

	//squared version of above.
	double    DistanceSq(const Vector2D &v2)const;

	void      Reflect(const Vector2D& norm);

	//returns the vector that is the reverse of this vector
	Vector2D  GetReverse()const;


	//we need some overloaded operators
	const Vector2D& operator+=(const Vector2D &rhs)
	{
		x += rhs.x;
		y += rhs.y;

		return *this;
	}

	const Vector2D& operator-=(const Vector2D &rhs)
	{
		x -= rhs.x;
		y -= rhs.y;

		return *this;
	}

	const Vector2D& operator*=(const double& rhs)
	{
		x *= rhs;
		y *= rhs;

		return *this;
	}

	const Vector2D& operator/=(const double& rhs)
	{
		x /= rhs;
		y /= rhs;

		return *this;
	}

	bool operator==(const Vector2D& rhs)const
	{
		return ((x == rhs.x) && (y == rhs.y));
	}

	bool operator!=(const Vector2D& rhs)const
	{
		return (x != rhs.x) || (y != rhs.y);
	}

	Vector2D Vec2DNormalize(const Vector2D &v);
};

inline Vector2D operator*(const Vector2D &lhs, double rhs)
{
	Vector2D result(lhs);
	result *= rhs;
	return result;
}

inline Vector2D operator*(double lhs, const Vector2D &rhs)
{
	Vector2D result(rhs);
	result *= lhs;
	return result;
}

//overload the - operator
inline Vector2D operator-(const Vector2D &lhs, const Vector2D &rhs)
{
	Vector2D result(lhs);
	result.x -= rhs.x;
	result.y -= rhs.y;

	return result;
}

//overload the + operator
inline Vector2D operator+(const Vector2D &lhs, const Vector2D &rhs)
{
	Vector2D result(lhs);
	result.x += rhs.x;
	result.y += rhs.y;

	return result;
}

//overload the / operator
inline Vector2D operator/(const Vector2D &lhs, double val)
{
	Vector2D result(lhs);
	result.x /= val;
	result.y /= val;

	return result;
}
