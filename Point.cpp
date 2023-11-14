//////////////// Name Nati Efraim
// ///////////// ID - 315552810
//////////////// Course - OPP EX4
#include "Point.h"
///////////initilaziation - class of point
// ////////////////////////////Constrctor and destrctor
Point::Point(int x , int y):m_x(x),m_y(y)
{

}
Point::Point(const Point& other):m_x(other.m_x),m_y(other.m_y)
{

}
Point::~Point()
{

}
// ////////////////////////////////Accesess function.
int Point::getX() const
{
	return this->m_x;
}
int Point::getY() const
{
	return this->m_y;
}
void Point::setX(int x)
{
	this->m_x = x;
}
void Point::setY(int y)
{
	this->m_y = y;
}
void Point::setPoint(int x, int y)
{
	this->setX(x);
	this->setY(y);
}
void Point::setPoint(const Point& other)
{
	this->setPoint(other.getX(), other.getY());
}
/////////////////////////////Operatorim 
bool Point::operator==(const Point& other) const//returns true if and only if the two points are equal
{
	return (this->m_x == other.m_x) && (this->m_y == other.m_y);
}
bool Point::operator!=(const Point& other) const//returns true if and only if the two points are not equal
{
	return !this->operator==(other);
}
Point Point::operator+(int num) const//returns a new point with updated x(x+num) and y(y+num)
{
	return Point(this->m_x + num, this->m_y + num);
}
const Point& Point::operator+=(int num)//updates the point with x(x+num) and y(y+num) and returns the updated point
{
	this->setX(this->m_x + num);//set the x
	this->setY(this->m_y + num);//set the y.
	return *this;
}
Point::operator int() const	//returns the sum of x and y
{
	return this->m_x + this->m_y;
}
Point Point::operator+(const Point& other) const//adds coordinates (x,y) and returns a new point
{
	return Point(this->m_x + other.m_x, this->m_y + other.m_y);
}
Point Point::operator++(int)//adds 1 to x and y and returns the updated point - postfix
{
	Point temp(*this);///save the old coordinate
	++(*this);///increase 
	return temp;
}
const Point& Point::operator++()//adds 1 to x and y and returns the updated point - prefix
{
	this->m_x++;
	this->m_y++;
	return *this;
}
Point operator*(int num, const Point& other)//returns a new point with (x,y)*num
{
	return Point(other.m_x * num, other.m_y * num);
}