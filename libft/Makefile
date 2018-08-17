NAME = libft.a
FLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes -I /opt/X11/include

HEADERS = includes/get_next_line.h includes/libft.h

OWN_FUNCTIONS = \
		ft_endl.c \
		ft_isupper.c \
		ft_islower.c \
		ft_iswhitespace.c \
		ft_skip_whitespaces.c \
		ft_rskip_whitespaces.c \
		ft_skip.c \
		ft_count_words.c \
		ft_strlen_delim.c \
		ft_strndup.c \
		ft_nbrlen.c \
		ft_strrev.c \
		ft_abs.c \
		ft_fabs.c \
		ft_fsign.c
 
PART1 = \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_strlen.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c

PART2 = \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c

LISTS = ft_lstnew.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstpush.c \
		ft_lstget.c \
		ft_lstcount.c

GNL = get_next_line.c

SRCS = $(OWN_FUNCTIONS) $(PART1) $(PART2) $(LISTS) $(GNL)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -r $(NAME) $(OBJS)
	ranlib	$(NAME)

%.o: %.c $(HEADERS)
	gcc -c $(FLAGS) $< $(INCLUDES) -o $@

clean:
	-rm -f $(OBJS)

fclean: clean
	-rm -f $(NAME)

re: fclean all
