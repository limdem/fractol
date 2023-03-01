RM	= rm -rf
CC	= gcc 
CFLAGS=-Wall -Wextra -Werror
NAME	= fractol
INCLUDES = -I ./includes
LIB = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
SRCS_DIR = srcs/
SRCS	=	main.c\
			zoom.c\
			fractal.c\
			mouse_hooks.c\
			key_hook.c\
			initialisation.c\
			initialisation2.c\
			utils.c\
			utils2.c
SRCS_PATH = $(addprefix $(SRCS_DIR), $(SRCS))	
OBJS	= $(SRCS:.c=.o)

%.o: %.c
	${CC} -c ${SRCS_PATH} ${CFLAGS} ${INCLUDES} $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) ${LIB}

	
$(OBJS): $(SRCS_PATH)
	${CC} -c  ${SRCS_PATH}${CFLAGS} ${INCLUDES}

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re