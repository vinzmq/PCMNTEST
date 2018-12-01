
#include "../inc/pac.hpp"

Pacman::Pacman()
{
	this->_x = 1;
	this->_y = 1;
	this->_sym = strdup("O");
	this->_score = 0;
	this->mvCas  = 0; 
	this->_color = 4;

	return;
}
Pacman::Pacman(int x, int y, int mvCas, int score, int col, char* s)
{
	this->_x = x;
	this->_y = y;
	this->_sym = s;
	this->_score = score;
	this->mvCas  = mvCas;
	this->_color = col;
}

Pacman::~Pacman() 
{
	free (this->_sym);
	return;
}

Pacman::Pacman(Pacman &cpy) 
{
	*this = cpy;
	return;
}

Pacman& Pacman::operator=(Pacman &cpy) 
{
	this->_x = cpy._x;
	this->_y = cpy._y;
	return *this;
}

void	Pacman::move(int mv, int w, int h, std::vector<char*> map) 
{
	mvCas = mv;
	if (mv == 3) 
	{
		if (this->_y - 1 && map[_y - 1][_x] != 'x')
		{
			this->_y--;
		}
	} 
	else if (mv == 1) 
	{
		if (this->_y + 1 < h - 1 && map[_y + 1][_x] != 'x')
		{
			this->_y++;
		
		}
	} 
	else if (mv == 2) 
	{
		if (this->_x - 1 > 0 && map[_y][_x - 1] != 'x')
		{
			this->_x -= 1;
			
     	}
	} else 
	{
		if (this->_x + 1 < w - 1 && map[_y][_x + 1] != 'x')
		{
			this->_x += 1;
			
	    }
	}
	return;
}

void	Pacman::act(WINDOW *win) 
{
	wattron(win, COLOR_PAIR(_color));
	mvwprintw(win, this->_y, this->_x, this->_sym);
	wattroff(win, COLOR_PAIR(_color));

}


	void Pacman::setSym(char *s)
	{
		this->_sym = s;
	}
	void Pacman::setX(int x)
	{
		this->_x = x;
	}
		void Pacman::setY(int y)
	{
		this->_y = y;
	}
		void Pacman::setScore(int score)
	{
		this->_score = score;
	}
	void Pacman::setmvCas(int mvCas)
	{
		this->mvCas = mvCas;
	}



	
	int Pacman::getScore(void)
	{
		return this->_score;
	}
	int Pacman::getX()
	{
		return this->_x;
	}
	int Pacman::getY()
	{
		return this->_y;
	}
	int Pacman::getmvCas()
	{
		return this->mvCas;
	}
	char *Pacman::getSym()
	{
		return this->_sym;
	}


