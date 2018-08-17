NAME = libftx.a
HEADERS = libftx.h
FLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes -I /opt/X11/include -I .. -I ../libft/includes

SRCS = \
	new_img.c \
	putpixel.c \
	vec2.c \
	vec2len.c \
	tcol.c

OBJS = $(SRCS:.c=.o)

all: $(NAME) $(HEADERS)

$(NAME): $(OBJS)
	ar -r $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c
	gcc -c $(FLAGS) $< $(INCLUDES) -o $@

clean:
	-rm -f $(OBJS)

fclean: clean
	-rm -f $(NAME)

re: fclean all
