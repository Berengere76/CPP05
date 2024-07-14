NAME = form

SRC = 		main.cpp \
			Bureaucrat.cpp \
			Form.cpp 

OBJ = $(SRC:.cpp=.o)
CC = c++
RM = rm -f
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re