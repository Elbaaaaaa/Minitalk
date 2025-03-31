CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = minitalk
SRCS = src/server.c \
		src/client.c \
		src/ft_printf.c \
		src/ft_printf_utils.c \

SRCS_BONUS = src_bonus/server_bonus.c \
				src_bonus/client_bonus.c \
				src_bonus/ft_printf_bonus \
				src_bonus/ft_printf_utils_bonus.c \

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

bonus: $(OBJS_BONUS)
	$(CC) $(CFLAGS) -o $(OBJS_BONUS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(OBJS_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
