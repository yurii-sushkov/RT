LIB = libft/libft.a
LIBX = libftx/libftx.a
HEADER = rt.h
NAME = RT
SRCS = 	main.c \
		pixel_to_point.c \
		vec3len.c \
		normalize.c \
		cast_rays.c \
		shadow_ray.c \
		shadow_ray_utils.c \
		intersect.c \
		sphere.c \
		plane.c \
		cylinder.c \
		cone.c \
		disk.c \
		new_object.c \
		get_normal.c \
		get_normal_2.c \
		transform.c \
		ft_atod.c \
		reader.c \
		assign.c \
		color.c \
		cam.c \
		cam_move.c \
		input.c \
		draw.c \
		reflection_ray.c \
		set_params_1.c \
		set_params_2.c \
		set_params_3.c \
		menu.c \
		menu_2.c \
		ui.c \
		box.c \
		light.c \
		transparency.c
OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror

all: libs $(NAME)

$(NAME): $(LIB) $(LIBX) $(OBJS)
	gcc $(FLAGS) $(OBJS) -L libft/ -lft -L . -lmlx -L libftx/ -lftx -I libftx/ -I libft/includes/ -I /opt/X11/include -framework CoreFoundation -framework OpenGL -framework AppKit -o $(NAME)

$(LIB):
	make -C libft/

$(LIBX):
	make -C libftx/

libs:
	make -C libft/ && make -C libftx/

%.o: %.c $(HEADER)
	gcc $(FLAGS) -c $< -I ./libft/includes/ -I /opt/X11/include -I libftx/ -I ..

clean:
	-rm $(OBJS) && make -C libft/ clean && make -C libftx/ clean

fclean: clean
	-rm $(NAME) && make -C libft/ fclean && make -C libftx/ fclean

re: fclean all

miniclean:
	-rm $(OBJS)

minifclean: miniclean
	-rm $(NAME)

minire: minifclean all
