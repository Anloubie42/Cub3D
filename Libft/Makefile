NAME	=		libft.a

# Sources

LIB_SRCS_NAME	=	ft_toupper.c			\
					ft_strlen.c				\
					ft_tolower.c			\
					ft_atoi.c				\
					ft_bzero.c				\
					ft_isalnum.c			\
					ft_isalpha.c			\
					ft_isascii.c			\
					ft_isdigit.c			\
					ft_isprint.c			\
					ft_memset.c				\
					ft_strchr.c				\
					ft_strncmp.c			\
					ft_strnstr.c			\
					ft_strrchr.c			\
					ft_memcpy.c				\
					ft_memccpy.c			\
					ft_memmove.c			\
					ft_memchr.c				\
					ft_memcmp.c				\
					ft_strlcpy.c			\
					ft_strlcat.c			\
					ft_strtrim.c			\
					ft_calloc.c				\
					ft_strdup.c				\
					ft_substr.c				\
					ft_strjoin.c			\
					ft_split.c				\
					ft_itoa.c				\
					ft_strmapi.c			\
					ft_putchar_fd.c			\
					ft_putstr_fd.c			\
					ft_putendl_fd.c			\
					ft_putnbr_fd.c			\
					get_next_line.c			\
					ft_clear.c				\

INCS_NAME		=	libft.h

# Directories

LIB_SRCS_DIR	=	./srcs/
LIB_OBJS_DIR	=	./objs/
INCS_DIR		=	./includes/

# Files

LIB_SRCS		=	$(addprefix $(LIB_SRCS_DIR), $(LIB_SRCS_NAME))
LIB_OBJS		=	$(patsubst $(LIB_SRCS_DIR)%.c, $(LIB_OBJS_DIR)%.o, $(LIB_SRCS))
INCS			=	$(addprefix $(INCS_DIR), $(INCS_NAME))

# Compilation

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -I $(INCS_DIR)

all: $(NAME)

$(NAME): $(LIB_OBJS)
	@ar rc $(NAME) $(LIB_OBJS)
	@ranlib $(NAME)
	@echo "\033[32;01m[libft OK]\033[00m"

$(LIB_OBJS_DIR)%.o:  $(LIB_SRCS_DIR)%.c $(INCS)
	@mkdir -p ./objs/
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -rf $(LIB_OBJS_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
