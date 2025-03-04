NAME_CLIENT = client
NAME_SERVER = server

SRC_CLIENT = src/client.c
SRC_SERVER = src/server.c

SRC_COMMON = src/ft_printf_utils.c src/ft_printf.c

OBJ_CLIENT = $(SRC_CLIENT:.c=.o) $(SRC_COMMON:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o) $(SRC_COMMON:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) -no-pie -o $(NAME_CLIENT) $(OBJ_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) -no-pie -o $(NAME_SERVER) $(OBJ_SERVER)

clean:
	$(RM) $(OBJ_CLIENT) $(OBJ_SERVER)

fclean: clean
	$(RM) $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

.PHONY: all clean fclean re
