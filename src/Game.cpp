#include "../inc/pac.hpp"

class Pacman;
class Casper;

Game::Game() 
{
	initscr();
	noecho();
	curs_set(0);
	start_color();
	keypad(stdscr, true);
	this->_win = newwin(HEIGHT - 1, WIDTH - 1, 1, 2);
	keypad(this->_win, true);
	nodelay(this->_win, true);
	wrefresh(this->_win);
	this->height = HEIGHT;
	this->width = WIDTH;
	return;
}
Game::Game(std::vector<char*> map, int height, int width) 
{
	srand(time(0));
	for (int i = 0; i < CASPER; i++)
	{
		cas[i].setX(width - 2);
		cas[i].setY(height - 2);
		cas[i].setColor(1);
		cas[i].setmvCas(0);
	}
	this->height = height;
	this->width = width;
	this->map = map;
	scoreToWin = 0;
	initscr();
	noecho();
	curs_set(0);
	start_color();
	keypad(stdscr, true);
	this->_win = newwin(height , width , 1, 2);
	keypad(this->_win, true);
	nodelay(this->_win, true);
	wrefresh(this->_win);
	mvCas = 0;
	return;
}

Game::Game(Game const & src) 
{
	*this = src;
	return;
}

Game::~Game() 
{
	delwin(this->_win);
	endwin();
}

Game const &	Game::operator = (Game const & rhs) 
{
	return rhs;
}


void	Game::start() 
{
	std::cout<<"Game begin))"<<std::endl;
	start_color();

	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	wclear(this->_win);
	int i = 0;
	int flag = 0;
	this->getScore();
	while (1) 
	{
		i++;
		int key = std::tolower(wgetch(this->_win));
		if (key == KEY_UP || key == 'w')
			mv = 3;
			 
		else if (key == KEY_DOWN || key == 's')
			mv = 1;
			
		else if (key == KEY_LEFT || key == 'a')
			mv = 2;
			
		else if (key == KEY_RIGHT || key == 'd')
			mv = 0;
			
		else if (key == 27)
			break ;
		if ((i % SPEED == 0))
		{

			this->Pac.move(mv, this->width, this->height, this->map);
			if (this->map[Pac.getY()][Pac.getX()] == '.')
				scoreToWin--;
			map[Pac.getY()][Pac.getX()] = ' ';


		}
		if (i % SPEED == 0)
		{
			 flag = 0;
			for (int k = 0; k < CASPER; k++)
			{
				int *check = cas[k].checkWay(this->map, this->width, this->height);
				
				if (check[0] == 0)
					cas[k].setmvCas(rand() % 4);
				else if (check[1] == 1 || check[2] == 1)
				{
					if (i % 3 == 0)
						cas[k].itermvCas();
					else if (i % 3 == 1)
						cas[k].decrmvCas();
					;
				}
				delete []check;
				cas[k].move(cas[k].getmvCas(), this->width, this->height, this->map);
				if (Pac.getX() == cas[k].getX() && Pac.getY() == cas[k].getY())
				{
					flag = 1;
					break;
				}
			}
			if (flag == 1)
				break;
	
		}

		this->print_map();
		if (scoreToWin == 0)
		{
			wclear(this->_win);
			break;
		}
	}
	wrefresh(this->_win);
	wclear(this->_win);	
	while (1)
	{
		int key = std::tolower(wgetch(this->_win));
		if (flag == 1)
		{
			mvwprintw(this->_win, 0, 0, "You are DEAD!(((");
		}
		else 
			mvwprintw(this->_win, 0, 0, "You are hired!");

		if (key == 27)
			break;

	}
	return;
}

void Game::print_map()
{
	for (int i = 0; i < map.size();i++)
	{
	 	mvwprintw(this->_win, i, 0,  map[i]);
	}
	this->Pac.act(this->_win);
	for (int i = 0; i < CASPER; i++)
	{
		cas[i].act(this->_win);
	}

}
void Game::getScore()
{
	for (int i = 0; i < map.size(); i++)
	{
		int j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == '.')
				scoreToWin++;
			j++;
		}
	}
}




