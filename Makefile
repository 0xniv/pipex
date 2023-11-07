# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 10:03:10 by vde-frei          #+#    #+#              #
#    Updated: 2023/11/06 16:51:58 by vde-frei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SHELL := /bin/bash
COUNT := 0
SLEEP := sleep 0.2

BLACK  		 = \033[0;30m
RED    		 = \033[0;31m
GREEN  		 = \033[0;32m
YELLOW 		 = \033[0;33m
BLUE   		 = \033[0;34m
MAGENTA		 = \033[0;35m
CYAN   		 = \033[0;36m
WHITE  		 = \033[0;37m
RESET  		 = \033[0m

MANDATORY = Program compiled
LBONUS = Bonus Program compiled
CLEAN = Objects delete
FCLEAN = Program delete
LIBNAME = pipex
BLIBNAME = pipex_bonus
COMP = Compiling

DFLAGS = -Wall -Wextra -Werror -g3 # TO DEBBUG
CFLAGS = -Wall -Werror -Wextra -O3 -g3 -fomit-frame-pointer -finline-functions # TO IMPROVE PERFORMANCE

SRC = src
BONUS = src/bonus
INC = includes
OBJ = obj

INCLUDES = -I$(INC)/ -Ilib/libft/includes/ -Ilib/ft_printf/includes/
LINCLUDES = -L$(LIBFT_PATH) -lft -L$(FTPF_PATH) -lft

LIBFT = lib/libft/libft.a
LIBFT_PATH = lib/libft

FTPF = lib/ft_printf/libftprintf.a
FTPF_PATH = lib/ft_printf

CFILES = $(addprefix $(SRC)/, main.c string.c errors.c check_access.c \
file_management.c)

BFILES = $(addprefix $(BONUS)/, main_bonus.c)

OBJECT =  $(patsubst %, $(OBJ)/%, $(notdir $(CFILES:.c=.o)))

ifdef WITH_BONUS
	CFILES = $(BFILES)
	MANDATORY = $(LBONUS)
	MAGENTA = $(YELLOW)
	LIBNAME = $(BLIBNAME)
endif

ifdef WITH_DEBBUG
	CFLAGS = $(DFLAGS)
endif

all: $(OBJ) $(NAME)

$(NAME): $(OBJECT)
	@$(MAKE) -sC $(LIBFT_PATH)
	@$(MAKE) bonus -sC $(FTPF_PATH)
	@$(CC) $(CFLAGS) $(INCLUDES) $(LINCLUDES) $(OBJECT) $(LIBFT) $(FTPF) -o $(NAME)
	@$(SLEEP)
	@printf "\n$(MAGENTA)$(MANDATORY)\n$(RESET)"

$(OBJ):
	@mkdir -p $(OBJ)

$(OBJ)/%.o: $(SRC)/%.c
	@$(eval COUNT=$(shell expr $(COUNT) + 1))
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "$(GREEN)$(LIBNAME) $(COMP) %d%%\r$(RESET)" $$(echo $$(($(COUNT) * 100 / $(words $(CFILES)))))

clean:
	@$(MAKE) fclean -sC $(LIBFT_PATH)
	@$(MAKE) fclean -sC $(FTPF_PATH)
	@$(RM) -rf $(OBJ)
	@$(SLEEP)
	@printf "$(RED)$(CLEAN)$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@$(SLEEP)
	@printf "$(RED)$(FCLEAN)$(RESET)\n"

re: fclean all

bonus:
	@make WITH_BONUS=TRUE --no-print-directory

debbug:
	@make WITH_DEBBUG=TRUE --no-print-directory

.PHONY: all bonus clean fclean re debbug
