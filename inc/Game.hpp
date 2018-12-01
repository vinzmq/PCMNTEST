#ifndef GAME_HPP
#define GAME_HPP

#define CASPER 2
#define SPEED 5000

//#include "pac.hpp"

class Game 
{

	public:

	Game(void);
	Game(std::vector<char*>, int, int);
	Game(Game const &);
	~Game(void);
	Game const &operator=(Game const &);

	void	start(void);
	void print_map();
	void getScore();
	//////getters


	private:

	WINDOW * _win;
	std::vector<char*> map;
	int height;
	int width;
	Casper	cas[CASPER];
	Pacman	Pac;
	int mv;
	int mvCas;
	int scoreToWin;
	
};

#endif
