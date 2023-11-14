//////////////// Name Nati Efraim
// ///////////// ID - 315552810
//////////////// Course - OPP EX4
#include "Square.h"
//////////////////////////////Intitialziation - Class Aquare
////////Constrctor and destrctor
Square::Square(double up, double down, double right, double left , const char* sn):Quad(up,down,right,left,sn)
{
	//constructor. center point = (0,0), name=sn
}
Square::~Square()//destructor
{

}
/////////////////////////Other Function
void Square::shiftX(int x)//shifts the center of the square by x (right and left)
{
	this->m_centerPoint.setX(this->m_centerPoint.getX() + x);///shift the x.
}
void Square::shiftY(int y)//shifts the center of the square by y (up and down)
{
	this->m_centerPoint.setY(this->m_centerPoint.getY() + y);///shift the x.
}
