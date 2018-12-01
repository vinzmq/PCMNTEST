
#include "../inc/pac.hpp"
//#include "../inc/Game.hpp"


int main(int argc, char **argv)
{
		std::string line;
    	char *text;
    	int i = 0;
    	int j = 0;
    	std::vector<char*> readed;
	if (argc  == 2 && argv[1])
	{
		
    	int count = 0;
    	std::ifstream map (argv[1]);
 
    	if (map.is_open())
    	{
        	while (! map.eof() )
        	{
           	    getline (map,line);
           	    char *cstr = new char[line.length() + 1];
				strcpy(cstr, line.c_str());
            	readed.push_back(cstr);
            	if (j == 0)
            		j = line.length();
                if (j != line.length())
                {
                    std::cout << "BAD MAP" << std::endl;
                    return -1;
                }
            	i++;
        	}
        	map.close();
        	Game game(readed, i, j);
			game.start();
            return 0;
    	}
    else std::cout << "Unable to open file"; 
	}
    else
        std::cout<< "usage: ./pac [filename](map)"<< std::endl;
	

	return 0;
}
