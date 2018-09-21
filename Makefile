NAME = atyumre.filler
INCLUDES = ./includes
SRC = ./put_token.c	\
	  ./numbers.c	\
	  ./algo.c		\
	  ./map_manip.c	\
	  ./utility.c	\
	  ./main.c		\

all: $(NAME)

$(NAME): $(SRC)
	@make -C ./srcs re
	gcc -Wall -Werror -Wextra -c $(SRC) -I ./srcs/includes/ -I $(INCLUDES)
	gcc -Wall -Werror -Wextra $(SRC:.c=.o) -L ./srcs -lft -o $(NAME)

clean:
	make -C ./srcs clean
	rm -f $(SRC:.c=.o)

fclean: clean
	make -C ./srcs fclean
	rm -rf $(NAME)

re: fclean all
