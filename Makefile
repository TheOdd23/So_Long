NAME			=	so_long
LIB				=	libft/libft.a
HEAD			=	so_long.h
CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra -g
SRCS			=	srcs/main.c srcs/check_map_errors.c srcs/read_map.c srcs/game_init.c srcs/do_moves.c \
					srcs/check_moves.c srcs/del_content.c srcs/sprites_init.c srcs/enemy_moves.c
OBJS			=	${SRCS:.c=.o}
RM				=	rm -f

.c.o		:
				$(CC) $(CFLAGS) -Imlx -c $< -o $(<:.c=.o)

$(NAME)		:	${OBJS}
				make -s -C libft
				$(CC) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME} ${OBJS} $(LIB)
				echo Pret!

all			:	$(NAME)

clean		:	
				${RM} ${OBJS}
				make clean -s -C libft

fclean		:	clean
				$(RM) $(NAME)
				make fclean -s -C libft
				echo Tout propre

re			:	fclean all

.PHONY		:	all clean fclean re
.SILENT		:	all clean fclean .c.o $(NAME) $(OBJS) $(CC) $(FLAGS)
