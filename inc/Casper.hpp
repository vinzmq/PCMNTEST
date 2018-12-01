#ifndef CASPER_HPP
#define CASPER_HPP

#include "pac.hpp"

class Pacman;

class Casper : public Pacman
{
	public:
	Casper();
	~Casper();
	Casper(Casper &cpy);
	Casper &operator=(Casper & cpy);


	void setColor(int);
	void itermvCas();
	void decrmvCas();
	int* checkWay(std::vector<char*>, int , int);
	

	private:
		// int _x;
		// int _y;
		// int _score;
		int _color;
		//int mvCas;

};

#endif