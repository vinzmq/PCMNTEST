NAME = pac
INC  = ./inc/
SRC = ./src/main.cpp ./src/Game.cpp  ./src/Pacman.cpp  ./src/Casper.cpp
CLANG = clang++ 
OBJ = $(SRC:.cpp=.o) 

all: $(NAME)

$(NAME): $(OBJ)
	$(CLANG) $(OBJ) -o $(NAME) -lncurses
%.o : %.cpp 
	 $(CLANG) -c $< -o $@ 
clean:
	rm -f ./src/*.o
fclean: clean
	rm -f $(NAME)
re: fclean all
