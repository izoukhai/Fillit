
NAME= fillit

OBJ_PATH= ./obj/
SRC_PATH=./

SRC_NAME  =  fillit.c main.c parser.c tetriominos.c
OBJ_NAME= $(SRC_NAME:.c=.o)
OBJ= $(addprefix $(OBJ_PATH), $(OBJ_NAME))
SRC= $(addprefix $(SRC_PATH), $(SRC_NAME))

INCLUDES= fillit.h libft/libft.h

ifndef FLAGS
FLAGS= -Wall -Werror -Wextra
endif

CC = gcc

all : $(NAME)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(NAME): $(OBJ_PATH) $(OBJ) $(INCLUDES)
		@ar -rc $(NAME) $(SRCO)
		@make -C libft/
		@echo "\033[32m[Your Fillit is ready]\033[0m"

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
		@echo  "\033[0;32m [OK] \033[0m       \033[0;33m Compiling:\033[0m" $<
		@gcc $(FLAGS) -o $@ -c $^
clean :
		@rm -rf $(SRCO)
		@make clean -C libft/ 
		@echo "\033[0;32m [OK] \033[0m       \033[0;33m File.o deleted:\033[0m" $<

fclean : clean
		@rm -rf $(NAME)
		@make fclean -C libft/
		@echo  "\033[0;32m [OK] \033[0m       \033[0;33m Fillit deleted:\033[0m" $<

re : fclean all

.PHONY: clean re all fclean