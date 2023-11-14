//////////////// Name Nati Efraim
// ///////////// ID - 315552810
//////////////// Course - OPP EX4
#include "allShapes.h"
#include "Circle.h"
#include "Square.h"
//////////////////////Intitialization
////////////Class of All Shape - Contain Class
/////Constrctor and destrctor 
allShapes::allShapes():m_size(0),m_arr(nullptr)
{
	//constructor, zero elements
}
allShapes::allShapes(const allShapes& other):m_size(other.m_size),m_arr(nullptr)//copy c'tor - deep copy
{
	this->m_arr = new Shape * [this->m_size];
	for (int i = 0; i < this->m_size; i++)
	{
		/////divided for 3 cases
		if (typeid(*other.m_arr[i]) == typeid(Circle))
		{
			////it is a Circlre
			Circle* circlePtr = dynamic_cast<Circle*>(other.m_arr[i]);///converting
			this->m_arr[i] = new Circle(*circlePtr);///deep copy - copy constrctor of Circle
			
		}
		else if (typeid(*other.m_arr[i]) == typeid(Quad))
		{
			////it is a Quad 
			Quad* quadPtr = dynamic_cast<Quad*>(other.m_arr[i]);///converting
			this->m_arr[i] = new Quad(*quadPtr);///deep copy - copy constrctor of Quad
		}
		else if (typeid(*other.m_arr[i]) == typeid(Square))
		{
			////it is a Squar
			Square* sqaurePtr = dynamic_cast<Square*>(other.m_arr[i]);///converting
			this->m_arr[i] = new Square(*sqaurePtr);///deep copy - copy constrctor of Sqaure
		}
	}
}
allShapes::~allShapes()//destructor to all elements
{
	for (int i = 0; i < this->m_size; i++)
	{
		delete this->m_arr[i];////virtual destrctor
		this->m_arr[i] = nullptr;
	}
	delete[]this->m_arr;
	this->m_arr = nullptr;
}
int allShapes::getSize() const//returns the number of shapes;
{
	return this->m_size;
}
////////////Other function
void allShapes::addShape(Shape* newShape)//add a new shape (deep copy) to the end of array
{
	Shape** tempArr = new Shape * [this->m_size + 1];
	for (int i = 0; i < this->m_size; i++)
	{
		tempArr[i] = this->m_arr[i];///shallow copy.
	}
	if (this->m_arr!=nullptr)
	{
		delete[] this->m_arr;
		this->m_arr = nullptr;
	}
	this->m_arr = tempArr;///reback
	this->m_size += 1;///increase the size
	//////Divided for cases
	if (typeid(*newShape)==typeid(Circle))
	{
		///it is circle type
		Circle* circlePtr = dynamic_cast<Circle*>(newShape);////converting
		this->m_arr[this->m_size - 1] = new Circle(*circlePtr);////deep copy - copy constrctor of - circle
	}
	else if (typeid(*newShape)==typeid(Quad))
	{
		///it is quad type
		Quad* quadPtr = dynamic_cast<Quad*>(newShape);////converting
		this->m_arr[this->m_size - 1] = new Quad(*quadPtr);////deep copy - copy constrctor of - Quad
	}
	else if (typeid(*newShape) == typeid(Square))
	{
		///it is quad type
		Square* sqaurePtr = dynamic_cast<Square*>(newShape);////converting
		this->m_arr[this->m_size - 1] = new Square(*sqaurePtr);////deep copy - copy constrctor of - Square

	}
	return;
}
void allShapes::removeShape(int index)//remove shape by index
{
	if (index<0 || index>=this->m_size || this->m_arr==nullptr)
	{
		return;///out of the range
	}
	if (index==0 && this->m_size==1)
	{
		///delete all arr
		delete this->m_arr[0];///virtual destrctor
		this->m_arr[0] = nullptr;
		delete[] this->m_arr;
		this->m_arr = nullptr;
		return;
	}
	delete this->m_arr[index];////virtual destrctor
	this->m_arr[index] = this->m_arr[this->m_size - 1];
	Shape** tempArr = new Shape * [this->m_size - 1];
	for (int i = 0; i < this->m_size-1; i++)
	{
		tempArr[i] = this->m_arr[i];///shallow copy

	}
	delete[]this->m_arr;////delete the old arr.
	this->m_arr = nullptr;
	this->m_arr = tempArr;////reBack
	this->m_size -= 1;////decrease the size
	return;

}
int allShapes::totalArea() const//returns the total area of all the shapes (rounded to int)
{
	int sum = 0;
	for (int i = 0; i < this->m_size; i++)
	{
		sum +=this->m_arr[i]->calcArea();////virtual function!!!!!
	}
	return sum;
}
int allShapes::totalPerimeter() const//returns the total Perimeter of all the shapes (rounded to int)
{
	int sum = 0;
	for (int i = 0; i < this->m_size; i++)
	{
		sum += this->m_arr[i]->calcPerimeter();////virtual function!!!!!
	}
	return sum;
}
int allShapes::totalCircleArea() const//returns the total sum of circle areas (rounded to int)
{
	int sum = 0;
	for (int i = 0; i < this->m_size; i++)
	{
		if (typeid(*this->m_arr[i])==typeid(Circle))
		{
			sum += this->m_arr[i]->calcArea();///virtual function - go to the Circal area.
		}
	}
	return sum;
}
int allShapes::totalSquarePerimeter() const	//returns the total sum of squar Perimeter (rounded to int)
{
	int sum = 0;
	for (int i = 0; i < this->m_size; i++)
	{
		if (typeid(*this->m_arr[i]) == typeid(Square))
		{
			sum += this->m_arr[i]->calcPerimeter();///virtual function - go to the Square area.
		}
	}
	return sum;
}
//////////////Operatorim
const allShapes& allShapes::operator+=(Shape* newS)//adds a new shape
{
	this->addShape(newS);///call  the function of add new Shape
	return *this;
}
Shape* allShapes::operator[](int ind) const//returns the shape located at index ind
{
	if (ind<0 || ind>=this->m_size || this->m_arr==nullptr)
	{
		return nullptr;///nothing to return
	}
	return this->m_arr[ind];
}
allShapes allShapes::operator+(const allShapes& other) const//returns a new allShape with all elements located at this and other
{
	allShapes temp;///deffult constrctor
	////use the operatorim we all reade worte
	for (int i = 0; i < this->m_size; i++)
	{
		temp.operator+=(this->m_arr[i]);///add new shape
	}
	for (int i = 0; i < other.m_size; i++)
	{
		temp.operator+=(other.m_arr[i]);///add new shape
	}
	return temp;///by value
}
allShapes::operator int() const//returns the number of elements
{
	return this->m_size;
}