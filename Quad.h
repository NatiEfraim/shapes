//////////////// Name Nati Efraim
// ///////////// ID - 315552810
//////////////// Course - OPP EX4
#ifndef QUAD_H
#define QUAD_H

#include "Shape.h"

class Quad : public Shape
{
public:
	Quad( double up = 0, double down = 0, double right = 0, double left = 0, const char* sn = "noName" );	//constructor. center point = (0,0), name=sn
										
	Quad( const Quad& other );				//copy constructr
	virtual ~Quad();						//destructor

public:
	virtual int calcArea() const;			//returns the quad's area (right*up) (rounded to int)
	virtual int calcPerimeter() const;		//returns the quad's Perimeter (the sum of the four ribs) (rounded to int)
	/////////////////////////////////////My Addition of Acceses function
	////////////////double getUp()const;
	////////////////double getDown()const;
	////////////////double getRight()const;
	////////////////double getLeft()const;
	////////////////void setUp(double up);
	////////////////void setDown(double down);
	////////////////void setRight(double right);
	////////////////void setLeft(double left);
	
private:
	double m_up;
	double m_down;
	double m_right;
	double m_left;
};

#endif