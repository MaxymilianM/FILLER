NAME = mminenko.filler

SRCS = main.c \
		ft_map.c \
		ft_piece.c \
		ft_algo_start.c \
		ft_algo_result.c

CFLAGS = -Wall -Wextra -Werror

LIBFT = ./libprintf/libftprintf.a

OBJECTS = $(SRCS:.c=.o)

.PHONY: all comp ncomp start clean fclean visl re 

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C ./libprintf
	make -C ./visual
	gcc $(CFLAGS) -o $(NAME) $(SRCS) $(LIBFT)

comp:
	gcc $(CFLAGS) -o $(NAME) $(SRCS) $(LIBFT)

visl:
	make comp -C ./visual

start:
	@./$(NAME)

clean:
	/bin/rm -f $(OBJECTS)
	make clean -C ./libprintf
	make clean -C ./visual

fclean: clean
	/bin/rm -f $(NAME) $(LIBFT) 
	make fclean -C ./libprintf
	make fclean -C ./visual

re: fclean all

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<