//////////////// Name Nati Efraim
// ///////////// ID - 315552810
//////////////// Course - OPP EX4
#include"Quad.h"
/////////////////////////Intialization - Class of Quad
///////// Constrctor dna destrctor
Quad::Quad(double up, double down, double right, double left, const char* sn):Shape(sn),m_up(up),m_down(down),m_right(right),m_left(left)
{
	//constructor. center point = (0,0), name=sn

}
Quad::Quad(const Quad& other):Shape(other), m_up(other.m_up), m_down(other.m_down), m_right(other.m_right), m_left(other.m_left)
{
	//copy constructr
}
Quad::~Quad()//destructor
{
	
}
////////////////////Overried function
int Quad::calcArea() const//returns the quad's area (right*up) (rounded to int)
{
	return (int)(this->m_right * this->m_up);
}
int Quad::calcPerimeter() const//returns the quad's Perimeter (the sum of the four ribs) (rounded to int)
{
	return (int)(this->m_down + this->m_up + this->m_left + this->m_right);
}