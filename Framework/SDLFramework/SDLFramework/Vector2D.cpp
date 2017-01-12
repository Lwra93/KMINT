#include "Vector2D.h"
#include <math.h>

//------------------------------------------------------------------------member functions

//------------------------- Length ---------------------------------------
//
//  returns the length of a 2D vector
//------------------------------------------------------------------------
double Vector2D::Length()const
{
	return sqrt(x * x + y * y);
}

Vector2D Vector2D::Perp()const
{
	return Vector2D(-y, x);
}

Vector2D Vector2D::Perps()const
{
	return Vector2D(-y, x);
}

//------------------------- LengthSq -------------------------------------
//
//  returns the squared length of a 2D vector
//------------------------------------------------------------------------
double Vector2D::LengthSq()const
{
	return (x * x + y * y);
}


//------------------------- Vec2DDot -------------------------------------
//
//  calculates the dot product
//------------------------------------------------------------------------
double Vector2D::Dot(const Vector2D &v2)const
{
	return x*v2.x + y*v2.y;
}

//------------------------ Sign ------------------------------------------
//
//  returns positive if v2 is clockwise of this vector,
//  minus if anticlockwise (Y axis pointing down, X axis to right)
//------------------------------------------------------------------------
enum { clockwise = 1, anticlockwise = -1 };

int Vector2D::Sign(const Vector2D& v2)const
{
	if (y*v2.x > x*v2.y)
	{
		return anticlockwise;
	}
	else
	{
		return clockwise;
	}
}

//------------------------------ Perp ------------------------------------
//
//  Returns a vector perpendicular to this vector
//------------------------------------------------------------------------


//------------------------------ Distance --------------------------------
//
//  calculates the euclidean distance between two vectors
//------------------------------------------------------------------------
double Vector2D::Distance(const Vector2D &v2)const
{
	double ySeparation = v2.y - y;
	double xSeparation = v2.x - x;

	return sqrt(ySeparation*ySeparation + xSeparation*xSeparation);
}


//------------------------------ DistanceSq ------------------------------
//
//  calculates the euclidean distance squared between two vectors 
//------------------------------------------------------------------------
double Vector2D::DistanceSq(const Vector2D &v2)const
{
	double ySeparation = v2.y - y;
	double xSeparation = v2.x - x;

	return ySeparation*ySeparation + xSeparation*xSeparation;
}

//----------------------------- Truncate ---------------------------------
//
//  truncates a vector so that its length does not exceed max
//------------------------------------------------------------------------
void Vector2D::Truncate(double max)
{
	if (this->Length() > max)
	{
		this->Normalize();

		*this *= max;
	}
}

//--------------------------- Reflect ------------------------------------
//
//  given a normalized vector this method reflects the vector it
//  is operating upon. (like the path of a ball bouncing off a wall)
//------------------------------------------------------------------------
void Vector2D::Reflect(const Vector2D& norm)
{
	*this += 2.0 * this->Dot(norm) * norm.GetReverse();
}

//----------------------- GetReverse ----------------------------------------
//
//  returns the vector that is the reverse of this vector
//------------------------------------------------------------------------
Vector2D Vector2D::GetReverse()const
{
	return Vector2D(-this->x, -this->y);
}

Vector2D Vector2D::Vec2DNormalize(const Vector2D & v)
{
	Vector2D vec = v;

	double vector_length = vec.Length();

	if (vector_length > std::numeric_limits<double>::epsilon())
	{
		vec.x /= vector_length;
		vec.y /= vector_length;
	}

	return vec;
}


//------------------------- Normalize ------------------------------------
//
//  normalizes a 2D Vector
//------------------------------------------------------------------------
void Vector2D::Normalize()
{
	double vector_length = this->Length();

	if (vector_length > std::numeric_limits<double>::epsilon())
	{
		this->x /= vector_length;
		this->y /= vector_length;
	}
}

void Vector2D::Normalize(const int speed)
{
	double vector_length = this->Length();

	if (vector_length > std::numeric_limits<double>::epsilon())
	{
		this->x /= speed;
		this->y /= speed;
	}
}


//------------------------------------------------------------------------non member functions


double Vec2DDistance(const Vector2D &v1, const Vector2D &v2)
{

	double ySeparation = v2.y - v1.y;
	double xSeparation = v2.x - v1.x;

	return sqrt(ySeparation*ySeparation + xSeparation*xSeparation);
}

double Vector2D::Vec2DDistanceSq(const Vector2D &v1, const Vector2D &v2)
{

	double ySeparation = v2.y - v1.y;
	double xSeparation = v2.x - v1.x;

	return ySeparation*ySeparation + xSeparation*xSeparation;
}

double Vec2DLength(const Vector2D& v)
{
	return sqrt(v.x*v.x + v.y*v.y);
}

double Vec2DLengthSq(const Vector2D& v)
{
	return (v.x*v.x + v.y*v.y);
}


///////////////////////////////////////////////////////////////////////////////


//treats a window as a toroid
void WrapAround(Vector2D &pos, int MaxX, int MaxY)
{
	if (pos.x > MaxX) { pos.x = 0.0; }

	if (pos.x < 0) { pos.x = (double)MaxX; }

	if (pos.y < 0) { pos.y = (double)MaxY; }

	if (pos.y > MaxY) { pos.y = 0.0; }
}

void Vector2D::WrapAround(int MaxX, int MaxY)
{
	if (x > MaxX) { x = 0.0; }

	if (x < 0) { x = (double)MaxX; }

	if (y < 0) { y = (double)MaxY; }

	if (y > MaxY) { y = 0.0; }
}

//returns true if the point p is not inside the region defined by top_left
//and bot_rgt
bool NotInsideRegion(Vector2D p,
	Vector2D top_left,
	Vector2D bot_rgt)
{
	return (p.x < top_left.x) || (p.x > bot_rgt.x) ||
		(p.y < top_left.y) || (p.y > bot_rgt.y);
}

bool InsideRegion(Vector2D p,
	Vector2D top_left,
	Vector2D bot_rgt)
{
	return !((p.x < top_left.x) || (p.x > bot_rgt.x) ||
		(p.y < top_left.y) || (p.y > bot_rgt.y));
}

bool InsideRegion(Vector2D p, int left, int top, int right, int bottom)
{
	return !((p.x < left) || (p.x > right) || (p.y < top) || (p.y > bottom));
}

//------------------ isSecondInFOVOfFirst -------------------------------------
//
//  returns true if the target position is in the field of view of the entity
//  positioned at posFirst facing in facingFirst
//-----------------------------------------------------------------------------
bool isSecondInFOVOfFirst(Vector2D posFirst,
	Vector2D facingFirst,
	Vector2D posSecond,
	double    fov)
{

	Vector2D toTarget = posFirst.Vec2DNormalize(posSecond - posFirst);

	return facingFirst.Dot(toTarget) >= cos(fov / 2.0);
}