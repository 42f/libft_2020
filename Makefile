
SRCS += ft_atoi.c
SRCS += ft_atoi_base.c
SRCS += ft_convert_base.c
SRCS += ft_bzero.c
SRCS += ft_calloc.c
SRCS += ft_isalnum.c
SRCS += ft_isalpha.c
SRCS += ft_isascii.c
SRCS += ft_isdigit.c
SRCS += ft_isprint.c
SRCS += ft_itoa.c
SRCS += ft_itoa_base.c
SRCS += ft_memccpy.c
SRCS += ft_memchr.c
SRCS += ft_memcmp.c
SRCS += ft_memcpy.c
SRCS += ft_memmove.c
SRCS += ft_memset.c
SRCS += ft_putmem.c
SRCS += ft_putendl_fd.c
SRCS += ft_putchar.c
SRCS += ft_putnbr.c
SRCS += ft_putstr.c
SRCS += ft_putchar_fd.c
SRCS += ft_putnbr_fd.c
SRCS += ft_putstr_fd.c
SRCS += ft_split.c
SRCS += ft_strchr.c
SRCS += ft_strdup.c
SRCS += ft_strjoin.c
SRCS += ft_strlcat.c
SRCS += ft_strlcpy.c
SRCS += ft_strlen.c
SRCS += ft_strmapi.c
SRCS += ft_strncmp.c
SRCS += ft_strnstr.c
SRCS += ft_strrchr.c
SRCS += ft_strtrim.c
SRCS += ft_substr.c
SRCS += ft_tolower.c
SRCS += ft_toupper.c
SRCS += ft_lstadd_back.c
SRCS += ft_lstadd_front.c
SRCS += ft_lstclear.c
SRCS += ft_lstdelone.c
SRCS += ft_lstiter.c
SRCS += ft_lstlast.c
SRCS += ft_lstmap.c
SRCS += ft_lstnew.c
SRCS += ft_lstsize.c
SRCS += ft_putnbr_base.c
SRCS += get_next_line.c
SRCS += get_next_line_utils.c
SRCS += ft_reversebits.c

OBJS	 =	$(SRCS:.c=.o)

CC		 =	clang

CFLAGS 	+= -Wall
CFLAGS	+= -Wextra
CFLAGS	+= -Werror
CFLAGS	+= -g


NAME	 =	libft.a

INC = ./includes/

HEAD = $(INC)libft.h

all:	$(NAME)
	@echo > /dev/null

$(NAME): $(OBJS) 
	@echo "\n		🔗 Linking $@'s objects files...\n"
	ar rcs $@ $^
	@echo "\n		🥳  Yay  !  $@ done.\n"

$(OBJS): %.o: %.c $(HEAD)
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

clean:
	@echo "\n		🚧 cleaning objects...\n"
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean:	clean
	@echo "\n		🚧 forced cleaning...\n"
	$(RM) $(NAME)

install: $(NAME)
	cp libft.a /usr/local/lib/
	cp includes/libft.h /usr/local/include/

re:	fclean all

.PHONY:	clean all fclean re bonus install
