
#include "../inc/pac.hpp"

Casper::Casper() : Pacman(1, 1, 0, 0, 1, strdup("A"))
{
	return;
}


Casper::~Casper() 
{
	
	return;
}

Casper::Casper(Casper &cpy) : Pacman(cpy)
{
	*this = cpy;
	return;
}

Casper& Casper::operator=(Casper &cpy) 
{
	setX(cpy.getX());
	setY(cpy.getY());
	return *this;
}



	void Casper::setColor(int color)
	{
		this->_color = color;
	}

	
	// void Casper::setmvCas(int mvCas)
	// {
	// 	this->mvCas = mvCas;
	// }
	//////////////////setters

	int *Casper::checkWay(std::vector<char*> map, int w, int h)
	{
		int *ret = new int[3];
		ret[0] = 0;
		ret[1] = 0;
		ret [2] = 0;

		if (getmvCas() == 3) 
		{
			if (getY() - 1 && map[getY() - 1][getX()] != 'x')
				ret[0] = 1;
			if (getX() - 1 > 0 && map[getY()][getX() - 1] != 'x')
			 	ret[1] = 1;
			if (getX() + 1 < w - 1 && map[getY()][getX() + 1] != 'x')
				ret[2] = 1;
			return ret;
		} 
		else if (getmvCas() == 1) 
		{
			if (getY() + 1 < h - 1 && map[getY() + 1][getX()] != 'x')
				ret[0] = 1;
			if (getX() + 1 < w - 1 && map[getY()][getX() + 1] != 'x')
				ret[1] = 1;
			if (getX() - 1 > 0 && map[getY()][getX() - 1] != 'x')
			 	ret[2] = 1;
			
			return ret;
		} 
		else if (getmvCas() == 2) 
		{
			if (getX() - 1 > 0 && map[getY()][getX() - 1] != 'x')
				ret[0] = 1;
			if (getY() + 1 < h - 1 && map[getY() + 1][getX()] != 'x')
				ret[1] = 1;
			if (getY() - 1 && map[getY() - 1][getX()] != 'x')
				ret[2] = 1;
			return ret;

		} else 
		{
			if (getX() + 1 < w - 1 && map[getY()][getX() + 1] != 'x')
				ret[0] = 1;
			if (getY() - 1 && map[getY() - 1][getX()] != 'x')
				ret[1] = 1;
			if (getY() + 1 < h - 1 && map[getY() + 1][getX()] != 'x')
				ret[2] = 1;
			return ret;
			
		}
			return ret; 
		}

		void Casper::itermvCas()
		{
			setmvCas(getmvCas() + 1);
			return;
		}
	void Casper::decrmvCas()
		{
			setmvCas(getmvCas() - 1);
			return;
		}