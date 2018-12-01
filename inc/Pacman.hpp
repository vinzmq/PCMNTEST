#ifndef PACMAN_HPP
#define PACMAN_HPP

//#include "pac.hpp"

class Pacman 
{
	public:
	Pacman();
	Pacman(int x, int y, int mvCas, int score, int col, char* s);
	~Pacman();
	Pacman(Pacman &cpy);
	Pacman &operator=(Pacman & cpy);
	///////
	void	move(int , int, int, std::vector<char*> );
	void	act(WINDOW *win);

	
	int getScore(void);
	int getX();
	int getY();
	char *getSym();
	int getmvCas();

	void setX(int);
	void setY(int);
	void setScore(int);
	void setmvCas(int);
	void setSym(char *s);

	
	private:
		int _x;
		int _y;
		int _score;
		int mvCas;
		int _color;
		char * _sym;

};

#endif