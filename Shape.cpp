//////////////// Name Nati Efraim
// ///////////// ID - 315552810
//////////////// Course - OPP EX4
#include "Shape.h"
///////////////////////Initialization of class Shape - Base Class
/////////constrctor and destrctor
int Shape::s_totalNumOfShapes = 0;
Shape::Shape(const char* sn ):m_shapeName(nullptr),m_centerPoint(0,0)
{
	this->m_shapeName = _strdup(sn);
	Shape::s_totalNumOfShapes += 1;//////increase the num of shape
}
Shape::Shape(const Shape& other):m_shapeName(nullptr),m_centerPoint(other.m_centerPoint)
{
	this->m_shapeName = _strdup(other.m_shapeName);
	Shape::s_totalNumOfShapes += 1;//////increase the num of shape
}
Shape::~Shape()
{
	if (this->m_shapeName!=nullptr)
	{
		delete this->m_shapeName;
	}
	this->m_shapeName = nullptr;
	Shape::s_totalNumOfShapes -= 1;///decrese the num of shape
}
//////////////////////Accesess function
void Shape::setName(const char* name)
{
	if (this->m_shapeName!=nullptr)
	{
		delete this->m_shapeName;
		this->m_shapeName = nullptr;
	}
	if (name==nullptr)
	{
		this->m_shapeName = nullptr;
		return;
	}
	this->m_shapeName = _strdup(name);
	return;
}
void Shape::setCenter(const Point& p)
{
	this->m_centerPoint.setPoint(p);/////set point
}
const char* Shape::getName() const
{
	return this->m_shapeName;
}
Point Shape::getCenter() const
{
	return this->m_centerPoint;
}
void Shape::setShape(const char* sn, const Point& other)
{
	this->setName(sn);///set the name
	this->setCenter(other);////set new senter point.
}
int Shape::numOfShapes()
{
	return Shape::s_totalNumOfShapes;
}
const Shape& Shape::operator=(const Shape& other)//operator=
{
	if (this==&other)
	{
		return *this;///do nothing
	}
	if (this->m_shapeName!=nullptr)
	{
		delete this->m_shapeName;
		this->m_shapeName = nullptr;
	}
	this->m_centerPoint.setPoint(other.m_centerPoint);///up-date the point
	s_totalNumOfShapes = other.s_totalNumOfShapes;
	if (other.m_shapeName==nullptr)
	{
		this->m_shapeName = nullptr;
		return *this;
	}
	this->m_shapeName = _strdup(other.m_shapeName);
	return *this;

}
