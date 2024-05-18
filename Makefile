NAME = push_swap

CFILES = ft_atoi.c ft_split.c ft_strjoin.c push_swap.c small_sort.c sorting_utils.c sorting.c swap_funs.c

all : $(NAME)

$(NAME) : $(CFILES)
	cc  $(CFILES) -o $(NAME)

fclean :
	rm -rf $(NAME)

re : fclean all
	