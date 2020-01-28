NAME =		libasm.a

SRC_PATH =	srcs/
SRC_NAME =	ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s
SRC_MAIN = main.c

HEAD_PATH =	includes

OBJS_PATH =	objs/

GCC =		gcc
NASM =		nasm

AR = ar -rc

GCCFLAGS =	-Werror -Wall -Wextra -g3 -fsanitize=address
NASM_FLAGS =	-f macho64

SRC =		$(SRC_NAME)
OBJS =		$(SRC:%.s=$(OBJS_PATH)%.o)
OBJS_TEST = $(SRC_MAIN:%.s=$(OBJS_PATH)%.o)

all:	$(OBJS)
		$(AR) $(NAME) $(OBJS)

$(NAME):	all

$(OBJS_PATH)%.o: $(SRC_PATH)%.s
		$(NASM) $(NASM_FLAGS) -I $(HEAD_PATH) -s $< -o $@

$(OBJS):	$(OBJS_PATH)

$(OBJS_PATH):
		mkdir $(OBJS_PATH)

test:		$(NAME) $(OBJS_TEST)
			$(GCC) $(GCCFLAGS) -I $(HEAD_PATH) $(NAME) $(OBJS_TEST) -o test

fclean:	
			rm -rf $(OBJS_PATH) $(NAME) test

clean:
			rm -rf $(OBJS_PATH)
re: fclean all

.PHONY: all clean fclean re