CC = cc

CCFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

INCLUDES = ft_printf.h

SRC = ft_printf.c put_things_1.c put_things_2.c

OBJ = $(SRC:.c=.o)

AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)
fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
