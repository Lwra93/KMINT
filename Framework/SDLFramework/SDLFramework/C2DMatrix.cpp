#include "C2DMatrix.h"

void C2DMatrix::MatrixMultiply(Matrix &mIn)
{
	C2DMatrix::Matrix mat_temp;

	//first row
	mat_temp._11 = (m_Matrix._11*mIn._11) + (m_Matrix._12*mIn._21) + (m_Matrix._13*mIn._31);
	mat_temp._12 = (m_Matrix._11*mIn._12) + (m_Matrix._12*mIn._22) + (m_Matrix._13*mIn._32);
	mat_temp._13 = (m_Matrix._11*mIn._13) + (m_Matrix._12*mIn._23) + (m_Matrix._13*mIn._33);

	//second
	mat_temp._21 = (m_Matrix._21*mIn._11) + (m_Matrix._22*mIn._21) + (m_Matrix._23*mIn._31);
	mat_temp._22 = (m_Matrix._21*mIn._12) + (m_Matrix._22*mIn._22) + (m_Matrix._23*mIn._32);
	mat_temp._23 = (m_Matrix._21*mIn._13) + (m_Matrix._22*mIn._23) + (m_Matrix._23*mIn._33);

	//third
	mat_temp._31 = (m_Matrix._31*mIn._11) + (m_Matrix._32*mIn._21) + (m_Matrix._33*mIn._31);
	mat_temp._32 = (m_Matrix._31*mIn._12) + (m_Matrix._32*mIn._22) + (m_Matrix._33*mIn._32);
	mat_temp._33 = (m_Matrix._31*mIn._13) + (m_Matrix._32*mIn._23) + (m_Matrix._33*mIn._33);

	m_Matrix = mat_temp;
}

//applies a 2D transformation matrix to a std::vector of Vector2Ds
void C2DMatrix::TransformVector2Ds(std::vector<Vector2D> &vPoint)
{
	for (unsigned int i = 0; i<vPoint.size(); ++i)
	{
		double tempX = (m_Matrix._11*vPoint[i].x) + (m_Matrix._21*vPoint[i].y) + (m_Matrix._31);

		double tempY = (m_Matrix._12*vPoint[i].x) + (m_Matrix._22*vPoint[i].y) + (m_Matrix._32);

		vPoint[i].x = tempX;

		vPoint[i].y = tempY;

	}
}

//applies a 2D transformation matrix to a single Vector2D
void C2DMatrix::TransformVector2Ds(Vector2D &vPoint)
{

	double tempX = (m_Matrix._11*vPoint.x) + (m_Matrix._21*vPoint.y) + (m_Matrix._31);

	double tempY = (m_Matrix._12*vPoint.x) + (m_Matrix._22*vPoint.y) + (m_Matrix._32);

	vPoint.x = tempX;

	vPoint.y = tempY;
}



//create an identity matrix
void C2DMatrix::Identity()
{
	m_Matrix._11 = 1; m_Matrix._12 = 0; m_Matrix._13 = 0;

	m_Matrix._21 = 0; m_Matrix._22 = 1; m_Matrix._23 = 0;

	m_Matrix._31 = 0; m_Matrix._32 = 0; m_Matrix._33 = 1;

}

//create a transformation matrix
void C2DMatrix::Translate(double x, double y)
{
	Matrix mat;

	mat._11 = 1; mat._12 = 0; mat._13 = 0;

	mat._21 = 0; mat._22 = 1; mat._23 = 0;

	mat._31 = x;    mat._32 = y;    mat._33 = 1;

	//and multiply
	MatrixMultiply(mat);
}

//create a scale matrix
void C2DMatrix::Scale(double xScale, double yScale)
{
	C2DMatrix::Matrix mat;

	mat._11 = xScale; mat._12 = 0; mat._13 = 0;

	mat._21 = 0; mat._22 = yScale; mat._23 = 0;

	mat._31 = 0; mat._32 = 0; mat._33 = 1;

	//and multiply
	MatrixMultiply(mat);
}


//create a rotation matrix
void C2DMatrix::Rotate(double rot)
{
	C2DMatrix::Matrix mat;

	double Sin = sin(rot);
	double Cos = cos(rot);

	mat._11 = Cos;  mat._12 = Sin; mat._13 = 0;

	mat._21 = -Sin; mat._22 = Cos; mat._23 = 0;

	mat._31 = 0; mat._32 = 0; mat._33 = 1;

	//and multiply
	MatrixMultiply(mat);
}


//create a rotation matrix from a 2D vector
void C2DMatrix::Rotate(const Vector2D &fwd, const Vector2D &side)
{
	C2DMatrix::Matrix mat;

	mat._11 = fwd.x;  mat._12 = fwd.y; mat._13 = 0;

	mat._21 = side.x; mat._22 = side.y; mat._23 = 0;

	mat._31 = 0; mat._32 = 0; mat._33 = 1;

	//and multiply
	MatrixMultiply(mat);
}