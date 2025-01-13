# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgouraud <mgouraud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 17:27:03 by mgouraud          #+#    #+#              #
#    Updated: 2025/01/13 13:55:07 by mgouraud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#! Variables

NAME		= push_swap
AR_NAME		= push_swap.a
INCLUDE		= include/
LIBFT_DIR	= libft/
OBJ_DIR		= obj/
SRC_DIR		= src/
AR		= ar rcs
CC		= gcc
CFLAGS	= -g -Wall -Wextra -Werror -I

#! Sources

MAIN 		=	main

INSTR_DIR	=	instructions/
INSTR		=	push reverse_rotate rotate swap

PRMTR_DIR	=	param_treat/
PRMTR		=	check_param

SORT_DIR	=	sorting/
SORT		=

UTILS_DIR	=	utils/
UTILS		=	utils

SRC_FILES	=	$(addprefix $(PRMTR_DIR),$(PRMTR)) \
				$(addprefix $(INSTR_DIR),$(INSTR)) \
				$(addprefix $(UTILS_DIR),$(UTILS)) \
				$(MAIN) \
				# $(addprefix $(SORT_DIR),$(SORT))

SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

#! Make

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a .
	@mv libft.a $(OBJ_DIR)$(AR_NAME)
	@echo "Compiling Push_swap..."
	@$(AR) $(OBJ_DIR)$(AR_NAME) $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDE) $(OBJ_DIR)$(AR_NAME) -o $(NAME)
	@echo "Push_swap compiled!"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | obj_mkdir
	@echo "Compiling: $<"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all: $(NAME)

bonus:

clean:
	@make clean -C $(LIBFT_DIR)
	@rm -rf $(OBJ_DIR)
	@echo "Push_swap objects files cleaned!"

fclean: clean
	@rm -f $(LIBFT_DIR)libft.a
	@rm -f $(NAME)
	@echo "Push_swap removed!"

libft:
	make -C $(LIBFT_DIR)

obj_mkdir:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)$(INSTR_DIR)
	@mkdir -p $(OBJ_DIR)$(PRMTR_DIR)
	@mkdir -p $(OBJ_DIR)$(SORT_DIR)
	@mkdir -p $(OBJ_DIR)$(UTILS_DIR)

re: fclean all
	@echo "Cleaned and rebuild Push_swap from zero!"

.PHONY: all bonus clean fclean libft re
