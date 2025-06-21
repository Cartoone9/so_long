NAME = so_long

CC = cc

CFLAGS = -Wall -Werror -Wextra -I minilibx-linux

LIBS = minilibx-linux/libmlx_Linux.a -lX11 -lXext -lm

O_DIR = .objs

S_DIR = srcs

SRCS = libft/ft_split.c  libft/ft_split_utils.c libft/ft_strjoin.c libft/ft_strncmp.c libft/ft_strdup.c \
	   libft/ft_strlen.c libft/ft_itoa.c \
		\
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		\
		srcs/main.c srcs/utils_1.c srcs/utils_2.c\
		srcs/parsing_1.c srcs/parsing_2.c srcs/parsing_3.c srcs/parsing_infection.c \
		srcs/game_1.c srcs/game_2.c srcs/game_3.c srcs/game_4.c \
		srcs/game_loop_1.c srcs/game_loop_2.c srcs/hud.c srcs/events.c \
		srcs/free_1.c srcs/free_2.c srcs/error.c \
		srcs/load_sprites_1.c srcs/load_sprites_2.c srcs/load_sprites_3.c \
		srcs/tester.c \

OBJS = $(SRCS:%.c=$(O_DIR)/%.o)

RESET = \033[0m
GREEN = \033[0;32m
RED	= \033[0;31m

$(O_DIR)/%.o : %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I./hdrs/ -Iminilibx_Linux -c $< -o $@

all : $(NAME)

bonus : $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)
	@echo "$(NAME): $(GREEN)$(NAME)$(RESET) has been compiled."

clean : 
	@rm -rf $(O_DIR)
	@echo "$(NAME): ${RED}${O_DIR}${RESET} has been deleted"

fclean : 
	@rm -rf $(O_DIR) $(NAME)
	@echo "$(NAME): ${RED}${O_DIR}${RESET} and ${RED}${NAME}${RESET} have been deleted"

re : fclean all

.PHONY : all bonus clean fclean re
