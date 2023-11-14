//////////////// Name Nati Efraim
// ///////////// ID - 315552810
//////////////// Course - OPP EX4
#include "Circle.h"
///////////////////////////Intitialization
///////constructor and destrctor
Circle::Circle(double r, const char* sn):Shape(sn),m_radius(r)//create a circle with radius=1, name=sn and center=(0,0)
{

}
Circle::Circle(const Circle& other):Shape(other),m_radius(other.m_radius)//copy constructor
{

}
Circle::~Circle()//destructor
{

}
/////////////////////Aceesess function
double Circle::getRadius() const//returns the circle's radius
{
	return this->m_radius;
}
void Circle::setRadius(double r)//set the radius
{
	this->m_radius = r;
}
//////////////////Operatorim
Circle operator+(int r, const Circle& other)//returns a new Circle with added radius
{
	Circle temp(r + other.m_radius, other.getName());
	temp.m_centerPoint.setPoint(other.m_centerPoint);///set the coordineate of the point
	return temp;
	////return Circle(r + other.m_radius);///thr rest of the data is null.
	
}
const Circle& Circle::operator=(const Circle& other)//operator= that copies all
{
	if (this==& other)
	{
		return *this;////do nothing
	}
	////////this->setShape(other.getName(), other.m_centerPoint);///set the rest of the shape data,
	this->m_centerPoint.setPoint(other.m_centerPoint);
	this->m_radius = other.m_radius;
	////if (other.getName()==nullptr)
	////{
	////	this->setName(nullptr);
	////	return *this;

	////}
	this->setName(other.getName());
	return *this;

}
const Circle& Circle::operator=(const char* name)//updates only the name of the shape and returns the updated shape
{
	this->setName(name);
	return *this;
}
// ///////////////////Overried Function
int Circle::calcArea() const//returns the circle's area (rounded to int)
{
	return (int)(PI * this->m_radius * this->m_radius);
}
int Circle::calcPerimeter() const//returns the circle's Perimeter (rounded to int)
{
	return (int)(2 * PI * this->m_radius);
}