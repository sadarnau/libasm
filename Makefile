NAME =			libasm.a

# SOURCES
SRC =			$(SRC_NAME)
SRC_PATH =		srcs/
SRC_NAME =		ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s \
				ft_list_size_bonus.s ft_list_push_front_bonus.s
SRC_MAIN = 		main.c

# HEADER
HEAD_PATH =		includes

# All .o (object file)
OBJS_PATH =		objs/
OBJS =			$(SRC:%.s=$(OBJS_PATH)%.o)
OBJS_TEST = 	$(SRC_MAIN:%.s=$(OBJS_PATH)%.o)

# Compilation
GCC =			gcc
NASM =			nasm
AR = 			ar -rcs

# Compilation flags
GCCFLAGS =		-Werror -Wall -Wextra
NASM_FLAGS =	-f elf64



all:			$(OBJS)
				$(AR) $(NAME) $(OBJS)

$(NAME):	all


# Getting .o from .s rule
$(OBJS_PATH)%.o: $(SRC_PATH)%.s
				$(NASM) $(NASM_FLAGS) -I $(HEAD_PATH) -s $< -o $@

$(OBJS):		$(OBJS_PATH)

$(OBJS_PATH):
				mkdir $(OBJS_PATH)


# Creating a testFile
test:			all $(OBJS_TEST)
				# $(GCC) -I $(HEAD_PATH) $(SRC_MAIN) $(NAME) -o test
				gcc -no-pie -I includes main.c libasm.a -o test

fclean:	
				rm -rf $(OBJS_PATH) $(NAME) test

clean:
				rm -rf $(OBJS_PATH)

re:				fclean all

.PHONY:			all clean fclean re
