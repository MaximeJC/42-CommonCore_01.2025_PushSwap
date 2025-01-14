# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgouraud <mgouraud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 17:27:03 by mgouraud          #+#    #+#              #
#    Updated: 2025/01/14 18:18:56 by mgouraud         ###   ########.fr        #
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
SORT		=	cost exec_sort sort

UTILS_DIR	=	utils/
UTILS		=	utils

SRC_FILES	=	$(addprefix $(INSTR_DIR),$(INSTR)) \
				$(addprefix $(PRMTR_DIR),$(PRMTR)) \
				$(addprefix $(SORT_DIR),$(SORT)) \
				$(addprefix $(UTILS_DIR),$(UTILS)) \
				$(MAIN) \

SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

#! Bonus Variables

CHKER_NAME		= checker
CHKER_AR_NAME	= checker.a
CHKER_INCLUDE	= include/checker.h
CHK_OBJ_DIR		= obj/
CHK_SRC_DIR		= src/

#! Bonus Sources

CHKER_DIR	=	checker/
CHKER		=	checker

CHK_SRC_FILES	=	$(addprefix $(CHKER_DIR),$(CHKER)) \
					$(addprefix $(INSTR_DIR),$(INSTR)) \
					$(addprefix $(PRMTR_DIR),$(PRMTR)) \
					$(addprefix $(UTILS_DIR),$(UTILS)) \

CHK_SRCS = $(addprefix $(CHK_SRC_DIR), $(addsuffix .c, $(CHK_SRC_FILES)))
CHK_OBJS = $(addprefix $(CHK_OBJ_DIR), $(addsuffix .o, $(CHK_SRC_FILES)))

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

bonus: $(CHK_OBJS)
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a .
	@mv libft.a $(CHK_OBJ_DIR)$(CHKER_AR_NAME)
	@echo "Compiling Checker..."
	@$(AR) $(CHK_OBJ_DIR)$(CHKER_AR_NAME) $(CHK_OBJS)
	@$(CC) $(CFLAGS) $(INCLUDE) $(CHK_OBJ_DIR)$(CHKER_AR_NAME) -o $(CHKER_NAME)
	@echo "Checker compiled!"

$(CHK_OBJ_DIR)%.o : $(CHK_SRC_DIR)%.c | obj_mkdir
	@echo "Compiling: $<"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	@rm -rf $(OBJ_DIR)
	@echo "Push_swap and checker objects files cleaned!"

fclean: clean
	@rm -f $(LIBFT_DIR)libft.a
	@rm -f $(NAME)
	@rm -f $(CHKER_NAME)
	@echo "Push_swap and checker removed!"

libft:
	make -C $(LIBFT_DIR)

obj_mkdir:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)$(CHKER_DIR)
	@mkdir -p $(OBJ_DIR)$(INSTR_DIR)
	@mkdir -p $(OBJ_DIR)$(PRMTR_DIR)
	@mkdir -p $(OBJ_DIR)$(SORT_DIR)
	@mkdir -p $(OBJ_DIR)$(UTILS_DIR)

re: fclean all
	@echo "Cleaned and rebuild Push_swap from zero!"

.PHONY: all bonus clean fclean libft re
