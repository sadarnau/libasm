NAME =			libasm.a

# SOURCES
SRC =				$(SRC_NAME)
SRC_MAC =			$(SRC_NAME)
SRC_PATH =			srcs/
SRC_PATH_MAC =		srcs_macOS/
SRC_NAME =			ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s \
					ft_list_size_bonus.s ft_list_push_front_bonus.s
SRC_MAIN = 			testing/main.c

# HEADER
HEAD_PATH =			includes

# All .o (object file)
OBJS_PATH =			objs/
OBJS_PATH_MAC =		objs_mac/
OBJS =				$(SRC:%.s=$(OBJS_PATH)%.o)
OBJS_MAC =			$(SRC_MAC:%.s=$(OBJS_PATH_MAC)%.o)

# Compilation
GCC =				gcc
NASM =				nasm
AR = 				ar -rcs

# Compilation flags
GCCFLAGS =			-Werror -Wall -Wextra
NASM_FLAGS =		-f elf64
NASM_FLAGS_MAC =	-f macho64



all:				$(OBJS)
					@echo "wait plz...\n.\n.\n.\n"
					@$(AR) $(NAME) $(OBJS)
					@echo "libasm created for linux (64_x86) !\n"

$(NAME):			all

mac:				$(OBJS_MAC)
					@echo "wait plz...\n.\n.\n.\n"
					@$(AR) $(NAME) $(OBJS_MAC)
					@echo "libasm created for mac !\n"

# Getting .o from .s rule
$(OBJS_PATH)%.o:$(SRC_PATH)%.s
					@$(NASM) $(NASM_FLAGS) -I $(HEAD_PATH) -s $< -o $@

$(OBJS_PATH_MAC)%.o:$(SRC_PATH_MAC)%.s
					@$(NASM) $(NASM_FLAGS_MAC) -I $(HEAD_PATH) -s $< -o $@

$(OBJS):			$(OBJS_PATH)

$(OBJS_MAC):		$(OBJS_PATH_MAC)

$(OBJS_PATH_MAC):
					@mkdir $(OBJS_PATH_MAC)

$(OBJS_PATH):
					@mkdir $(OBJS_PATH)


# Creating a testFile
test:				all
					@$(GCC) -I $(HEAD_PATH) $(SRC_MAIN) $(NAME) -o test
					@echo "\n\ntest file created, just run ./test ;)\n"

test_mac:			mac
					@$(GCC) -I $(HEAD_PATH) $(SRC_MAIN) $(NAME) -o test
					@echo "\n\ntest file created, just run ./test ;)\n"

fclean:	
					@rm -rf $(OBJS_PATH_MAC) $(OBJS_PATH) $(NAME) test
					@echo "\nDeleting everything...\n"
clean:
					@rm -rf $(OBJS_PATH) $(OBJS_PATH_MAC)
					@echo "\nDeleting objs...\n"

re:					fclean all

re_mac:				fclean mac

.PHONY:				all clean fclean re
