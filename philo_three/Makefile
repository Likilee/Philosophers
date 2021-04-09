NAME = philo_three
CFLAG = -Wall -Wextra -Werror#-g3 -fsanitize=address
SRC_NAME = main \
			parse \
			error \
			test \
			time \
			utils \
			do \
			print_status \
			print_current_job \
			experiment \
			clear \
			prepare_experiment \
			is_valid_arguments \
			manage_process

SRCDIR = ./src
SRC = $(addprefix $(SRCDIR)/,$(addsuffix .c, $(SRC_NAME)))
INCLUDE = -I ./include
MAKE = make

all : $(NAME)

clean :

fclean : clean
	rm -rf $(NAME)
	rm -rf $(NAME).dSYM
re : fclean all

bonus : all

run : all
	./$(NAME)
$(NAME) : $(SRC)
	cd HEADING_42 && ./heading42.sh
	gcc $(CFLAG) -o $@ $(SRC) $(INCLUDE)

.PONY : all clean fclean re bonus run
