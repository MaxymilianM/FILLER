NAME = visualizer

SRCS = main.c \
		drow.c \
		tools.c

MFLAGS = -lmlx -framework OpenGL -framework AppKit -lm

CFLAGS = -Wall -Wextra -Werror

LIBFT = ../libprintf/libftprintf.a

OBJECTS = $(SRCS:.c=.o)

.PHONY: all comp start clean fclean re 

all: $(NAME)

$(NAME): $(OBJECTS)
	gcc $(CFLAGS) -o $(NAME) $(SRCS) $(LIBFT) $(MFLAGS)

comp:
	gcc $(CFLAGS) -o $(NAME) $(SRCS) $(LIBFT) $(MFLAGS)

start:
	./$(NAME)

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME) $(LIBFT)

re: fclean all

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<