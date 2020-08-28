SRCS_DIR = ./sources

SRCS += $(SRCS_DIR)/gnl/get_next_line_utils.c
SRCS += $(SRCS_DIR)/gnl/get_next_line.c

SRCS += $(SRCS_DIR)/char/ft_isdigit.c
SRCS += $(SRCS_DIR)/char/ft_isascii.c
SRCS += $(SRCS_DIR)/char/ft_isprint.c
SRCS += $(SRCS_DIR)/char/ft_toupper.c
SRCS += $(SRCS_DIR)/char/ft_isalpha.c
SRCS += $(SRCS_DIR)/char/ft_isalnum.c
SRCS += $(SRCS_DIR)/char/ft_tolower.c

SRCS += $(SRCS_DIR)/memory/ft_memcmp.c
SRCS += $(SRCS_DIR)/memory/ft_bzero.c
SRCS += $(SRCS_DIR)/memory/ft_memcpy.c
SRCS += $(SRCS_DIR)/memory/ft_memccpy.c
SRCS += $(SRCS_DIR)/memory/ft_memchr.c
SRCS += $(SRCS_DIR)/memory/ft_memset.c
SRCS += $(SRCS_DIR)/memory/ft_memmove.c
SRCS += $(SRCS_DIR)/memory/ft_calloc.c

SRCS += $(SRCS_DIR)/put/ft_putstr_fd.c
SRCS += $(SRCS_DIR)/put/ft_putnbr.c
SRCS += $(SRCS_DIR)/put/ft_putnbr_fd.c
SRCS += $(SRCS_DIR)/put/ft_putnbr_base.c
SRCS += $(SRCS_DIR)/put/ft_putendl_fd.c
SRCS += $(SRCS_DIR)/put/ft_putchar.c
SRCS += $(SRCS_DIR)/put/ft_putchar_fd.c
SRCS += $(SRCS_DIR)/put/ft_putstr.c
SRCS += $(SRCS_DIR)/put/ft_putmem.c

SRCS += $(SRCS_DIR)/bits/ft_reversebits.c

SRCS += $(SRCS_DIR)/list/ft_lstadd_back.c
SRCS += $(SRCS_DIR)/list/ft_lstnew.c
SRCS += $(SRCS_DIR)/list/ft_lstlast.c
SRCS += $(SRCS_DIR)/list/ft_lstclear.c
SRCS += $(SRCS_DIR)/list/ft_lstiter.c
SRCS += $(SRCS_DIR)/list/ft_lstmap.c
SRCS += $(SRCS_DIR)/list/ft_lstsize.c
SRCS += $(SRCS_DIR)/list/ft_lstadd_front.c
SRCS += $(SRCS_DIR)/list/ft_lstdelone.c

SRCS += $(SRCS_DIR)/conversion/ft_itoa_base.c
SRCS += $(SRCS_DIR)/conversion/ft_convert_base.c
SRCS += $(SRCS_DIR)/conversion/ft_atoi_base.c
SRCS += $(SRCS_DIR)/conversion/ft_atoi.c
SRCS += $(SRCS_DIR)/conversion/ft_itoa.c

SRCS += $(SRCS_DIR)/str/ft_strnstr.c
SRCS += $(SRCS_DIR)/str/ft_strlcpy.c
SRCS += $(SRCS_DIR)/str/ft_strlen.c
SRCS += $(SRCS_DIR)/str/ft_strchr.c
SRCS += $(SRCS_DIR)/str/ft_strjoin.c
SRCS += $(SRCS_DIR)/str/ft_split.c
SRCS += $(SRCS_DIR)/str/ft_strrchr.c
SRCS += $(SRCS_DIR)/str/ft_substr.c
SRCS += $(SRCS_DIR)/str/ft_strncmp.c
SRCS += $(SRCS_DIR)/str/ft_strmapi.c
SRCS += $(SRCS_DIR)/str/ft_strtrim.c
SRCS += $(SRCS_DIR)/str/ft_strlcat.c
SRCS += $(SRCS_DIR)/str/ft_strdup.c

SRCS += $(SRCS_DIR)/math/ft_pow.c

SRCS += $(SRCS_DIR)/binary_tree/btree_apply_by_level.c
SRCS += $(SRCS_DIR)/binary_tree/btree_apply_infix.c
SRCS += $(SRCS_DIR)/binary_tree/btree_apply_prefix.c
SRCS += $(SRCS_DIR)/binary_tree/btree_apply_suffix.c
SRCS += $(SRCS_DIR)/binary_tree/btree_create_node.c
SRCS += $(SRCS_DIR)/binary_tree/btree_free_suffix.c
SRCS += $(SRCS_DIR)/binary_tree/btree_insert_data.c
SRCS += $(SRCS_DIR)/binary_tree/btree_level_count.c
SRCS += $(SRCS_DIR)/binary_tree/btree_nodes_count.c
SRCS += $(SRCS_DIR)/binary_tree/btree_search_item.c

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
