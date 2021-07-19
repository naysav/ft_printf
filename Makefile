.PHONY: all clean fclean re
SRCS    =   ft_printf.c					\
			parsing_flags.c				\
			treatment_specificer.c		\
			print_c.c					\
			print_s.c					\
			print_i.c					\
			print_p.c					\
			print_u_10.c				\
			print_u_16.c				\
			utils.c
LIBFT   =   libft
OBJS    =   ${SRCS:.c=.o}
NAME    =   libftprintf.a
PR_HEAD =   ft_printf.h
LB_HEAD =   libft/libft.h
RM      =   rm -f
CC      =   gcc
CFLAGS  =   -Wall -Wextra -Werror
.c.o:
			${CC} ${CFLAGS} -c $< -I ${LB_HEAD} -I ${PR_HEAD} -o $@
${NAME}:	${OBJS}
			make -C ${LIBFT}
			cp libft/libft.a ${NAME}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}
all:		${NAME}
clean:
			${RM} ${OBJS}
			make clean -C ${LIBFT}
fclean:		clean
			${RM} ${NAME}
			make fclean -C ${LIBFT}
re:			fclean all