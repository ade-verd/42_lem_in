# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 13:46:57 by ade-verd          #+#    #+#              #
#    Updated: 2018/07/26 18:42:17 by ade-verd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Binary
NAME = lem_in_and_visu
NAME_LEM = lem-in
NAME_VWR = visu-hex

# Directories
SRC_PATH = src
LEM_PATH = $(SRC_PATH)/lemin
VWR_PATH = $(SRC_PATH)/visuhex
LIB_PATH = libftprintf/libft
OBJ_PATH = obj

# MAKEFLAGS
MAKE = make --no-print-directory -C #$(MAKEFLAGS)

# **************************************************************************** #
# SPECIALS CHARS                                                               #
# **************************************************************************** #
LOG_CLEAR = \033[2K
LOG_UP = \033[A
LOG_NOCOLOR = \033[0m
LOG_BOLD = \033[1m
LOG_UNDERLINE = \033[4m
LOG_BLINKING = \033[5m
LOG_BLACK = \033[1;30m
LOG_RED = \033[1;31m
LOG_GREEN = \033[1;32m
LOG_YELLOW = \033[1;33m
LOG_BLUE = \033[1;34m
LOG_VIOLET = \033[1;35m
LOG_CYAN = \033[1;36m
LOG_WHITE = \033[1;37m

TITLE = $(LOG_CLEAR)$(LOG_BLUE)
END_TITLE = $(LOG_NOCOLOR)
LINKING = "--$(LOG_CLEAR)$(LOG_GREEN)✓$(LOG_NOCOLOR)\tlinking " \
				".................. $(LOG_VIOLET)$<$(LOG_NOCOLOR)"
ASSEMBLING = "--$(LOG_CLEAR)$(LOG_GREEN)✓$(LOG_NOCOLOR)\tassembling " \
			 	"............... $(LOG_YELLOW)$(NAME)$(LOG_NOCOLOR)"
OBJECTS_DEL = "--$(LOG_CLEAR)$(LOG_YELLOW)Objects$(LOG_NOCOLOR) deletion " \
				"............ $(LOG_RED)×$(LOG_NOCOLOR)"
BIN_DEL = "--$(LOG_CLEAR)$(LOG_YELLOW)Binary$(LOG_NOCOLOR) deletion " \
				"............. $(LOG_RED)×$(LOG_NOCOLOR)"

# **************************************************************************** #
# RULES                                                                        #
# **************************************************************************** #
.PHONY: all, clean, fclean, re, norme, norm, lem-in, visu-hex\
		init_submodules, update_submodules

all: $(NAME)

$(NAME): $(NAME_LEM) $(NAME_VWR)

$(NAME_LEM): force
	@$(MAKE) $(LEM_PATH) $@
	@if [ -h $@ ]; then rm -f $@; fi;
	@ln -s $(LEM_PATH)/$@ .

$(NAME_VWR): force
	@$(MAKE) $(VWR_PATH) $@
	@if [ -h $@ ]; then rm -f $@; fi;
	@ln -s $(VWR_PATH)/$@ .

force:
	@true

clean:
	@$(MAKE) $(LEM_PATH) clean
	@$(MAKE) $(VWR_PATH) clean
	@rm -Rf $(OBJ_PATH)

fclean:
	@$(MAKE) $(LEM_PATH) fclean
	@$(MAKE) $(VWR_PATH) fclean
	@rm -Rf $(OBJ_PATH)
	@if [ -h $(NAME_LEM) ]; then rm -f $(NAME_LEM); fi;
	@if [ -h $(NAME_VWR) ]; then rm -f $(NAME_VWR); fi;

re: fclean all

norme:
	@echo -e "$(TITLE)Norminette: $(NAME_LEM)$(END_TITLE)"
	@$(MAKE) $(LEM_PATH) norme
	@echo -e "$(TITLE)Norminette: $(NAME_VWR)$(END_TITLE)"
	@$(MAKE) $(VWR_PATH) norme

norm:
	norminette **/**.[ch] | grep -B 1 "Error\|Warning" || echo "norme OK"

init_submodules:
	git submodule update --init --recursive

update_submodules:
	git submodule update --recursive --remote

# **************************************************************************** #
# Personal notes :                                                             #
#                                                                              #
# $@ : rule's name                                                             #
# $^ : all dependencies after ':'                                              #
# $< : corresponding dependency                                                #
# || : of there is an error, execute the command after the double pipe         #
#                                                                              #
# **************************************************************************** #
