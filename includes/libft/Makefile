NAME = libft.a
CFALGS = -Wall -Wextra -Werror 
CC = cc
RM = rm -rf
AR = ar rcs

FILE = 	ft_bzero.c		\
		ft_calloc.c		\
		ft_isalnum.c	\
		ft_isalpha.c	\
		ft_isascii.c	\
		ft_isdigit.c	\
		ft_isprint.c	\
		ft_memcpy.c		\
		ft_memcmp.c		\
		ft_memset.c		\
		ft_memchr.c		\
		ft_memmove.c	\
		ft_strlen.c		\
		ft_tolower.c	\
		ft_toupper.c	\
		ft_strlcpy.c	\
		ft_strlcat.c	\
		ft_strchr.c		\
		ft_strrchr.c	\
		ft_strncmp.c	\
		ft_strnstr.c	\
		ft_substr.c		\
		ft_strdup.c		\
		ft_strjoin.c	\
		ft_strtrim.c	\
		ft_atoi.c		\
		ft_itoa.c		\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c	\
		ft_striteri.c	\
		ft_strmapi.c	\
		ft_split.c

OBJ = $(FILE:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	@echo "\033[32m✓ built completed\033[0m"
clean:
	@$(RM) $(OBJ)
	@echo "\033[1;33m✓ objects removed\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[31m✓ library removed\033[0m --> $(NAME)"

re: fclean all

.PHONY: all clean fclean re
