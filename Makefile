# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/03 12:31:07 by lubaujar          #+#    #+#              #
#    Updated: 2015/05/26 21:00:41 by lubaujar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_minishell
RM = rm -rf
FLAGS = -g -Wall -Wextra -Werror
LDFLAGS = -I./include/ -I./libft/include/

SRC = main.c\
		parse_cmd.c\
		lst.c\
		env.c\
		display.c\
		misc.c

OBJ = $(SRC:.c=.o)
	SRCDIR	= ./srcs/
	OBJDIR	= ./obj/
	INCDIR	= ./include/
	SRCS	= $(addprefix $(SRCDIR), $(SRC))
	OBJS	= $(addprefix $(OBJDIR), $(OBJ))
	INCS	= $(addprefix $(INCDIR), $(INC))

all: $(NAME)

$(NAME): $(OBJS) $(INCS)
	@gcc $(FLAGS) -o $@ $^ -L./libft/ -lft
	@echo "\t \033[32m[All's Fine]\033[0m"

$(OBJS): $(SRCS)
	make -C libft/
	@gcc $(FLAGS) -c $(SRCS) $(LDFLAGS)
	@echo "\\033[1;34mShell in progress ..\n\tShell in progress ..."
	@echo "\\033[1;34m\t\tShell in progress ...\\033[0;39m"
	@mkdir -p $(OBJDIR)
	@mv $(OBJ) $(OBJDIR)

clean:
	@echo "\nRM *.o.. \t      \033[32mDELETE!\033[0m"
	@$(RM) $(OBJS)
	@$(RM) *.o

fclean: clean
	make fclean -C libft/
	@echo "RM ./ft_minishell..   \033[32mDELETE!\033[0m"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
