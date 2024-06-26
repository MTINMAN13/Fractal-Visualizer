NAME = fractol

RANDOM_DIGIT := $(shell echo $$((RANDOM % 10)))

DEF_COLOR = \033[0;39m
CLR2 = \033[0;32m  # Orangeish color with a random last digit
CLR1 = \033[0;48m  # Complementary orangeish color with a random last digit


CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

# Directories
SRC_DIR =
OBJ_DIR = obj
INCLUDE = include

# Sources
SRC_FILES = fractol \
			fractol_hooks_keys fractol_hooks_mouse fractol_hooks \
			fractol_hooks_keysII \
			fractol_julia fractol_mandelbrot fractol_mandeltri fractol_ship \
			\
			fractol_u_shift_color fractol_default_zoom_values \
			fractol_u_color fractol_u_colooor fractol_u_clrtools \
			fractol_utilities_errors fractol_utilities_runtime

SRC = $(addsuffix .c, $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC_FILES)))

LIBFT = libft.a
MINILIBX = minilibx/libmlx_Linux.a
LFLAGS = -Lminilibx -lmlx -lXext -lX11 -lm #okay this cost me .... fml lol

# Rule to compile .c files into .o files
$(OBJ_DIR)/%.o: %.c
	mkdir -p obj
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

# Rule to build the executable  and run
$(NAME): minlibx libft $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBFT) $(LFLAGS)
	# @clear
	@echo "$(CLR2)rdy$(DEF_COLOR)"

all:
	make $(NAME)

bonus:
	# todo

minlibx:
		@ make -C minilibx/

libft:
		@ make -C libft/

clean:
		@ $(RM) $(OBJ)
		@ $(RM) $(NAME)
		@echo "$(CLR1)               $(NAME) wiped! have a nice day ;-)$(DEF_COLOR)"
		@echo "$(CLR2)               please recompile to proceed.$(DEF_COLOR)"
		@sleep 1

fclean: clean
		@ $(RM) $(NAME)
		@ $(RM) libft.a
		@ $(RM) obj
		@ make -C libft/ clean
		@clear
		@echo "$(CLR1)               all wiped boss! have a nice day ;-)$(DEF_COLOR)"
		@sleep 1
		@clear

re:	fclean
	make $(NAME)
	@sleep 1

norm:
		@clear
		@norminette $(addsuffix .c, $(SRC_FILES)) $(NAME).h

julia:
		make $(NAME)
		@clear
		@echo "$(CLR2)--------- clean program run ---------$(DEF_COLOR)"
		./$(NAME) julia -1.26 0.05
		@echo
		@echo
		@echo "$(CLR2)--------- clean program run ---------$(DEF_COLOR)"

m:
		make $(NAME)
		@clear
		@echo "$(CLR2)--------- clean program run ---------$(DEF_COLOR)"
		./$(NAME) mandeltri
		@echo
		@echo
		@echo "$(CLR2)--------- clean program run ---------$(DEF_COLOR)"

run:
		make $(NAME)
		@clear
		@echo "$(CLR2)--------- clean program run ---------$(DEF_COLOR)"
		./$(NAME) mandelbrot
		@echo
		@echo
		@echo "$(CLR2)--------- clean program run ---------$(DEF_COLOR)"

valgrind:
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) mandelbrot


.PHONY: all libft clean fclean re norm $(NAME) run

