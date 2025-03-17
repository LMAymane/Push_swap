CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
LIBFT_FL = libft
LIBFT = $(LIBFT_FL)/libft.a

SRCS = checks_fun/ft_check_rep.c checks_fun/ft_check_sorted.c checks_fun/ft_check_valid.c \
				push_swap.c \
				lst_functions/ft_lstadd_back.c lst_functions/ft_lstadd_front.c lst_functions/ft_lstlast.c \
				lst_functions/ft_lstnew.c lst_functions/ft_lstsize.c \
				operations/operation1.c operations/operation2.c operations/operation3.c operations/operation4.c \
				sort/init_node.c sort/sort_three.c sort/sort.c sort/utils.c \
				utils/error_and_free.c utils/ft_atol.c utils/utils2.c

OBJS = $(SRCS:.c=.o)

PUSH_SWAP_A = push_swap.a

all : $(LIBFT) $(PUSH_SWAP_A) $(NAME)

$(PUSH_SWAP_A): $(OBJS)
	@ar rcs $@ $(OBJS)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(PUSH_SWAP_A) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_FL)

%.o: %.c push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@make clean -C $(LIBFT_FL)

fclean: clean
	@rm -f $(NAME) $(PUSH_SWAP_A)
	@make fclean -C $(LIBFT_FL)


re: fclean all

.PHONY: all clean fclean re