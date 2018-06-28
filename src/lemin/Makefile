# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/23 12:33:34 by ade-verd          #+#    #+#              #
#    Updated: 2018/06/28 20:28:44 by ade-verd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Binary
NAME = lem-in

# Compiler
CC = gcc

# Directories
PROJECT_PATH = ../../
SRC_PATH = ./
SRC_PATH_NAME = $(notdir $(CURDIR))
SRC_PATH_MUTUAL = ../mutual/
OBJ_PATH = ../../obj/$(SRC_PATH_NAME)/
SCRIPTS_PATH = $(PROJECT_PATH)scripts/
PRINTF_PATH = ../../libftprintf/
LIBFT_PATH = $(PRINTF_PATH)/libft/
LIB_PATH = $(LIBFT_PATH) $(PRINTF_PATH) 
INC_PATH = ../../includes/ \
		   $(addsuffix includes/, $(LIB_PATH))

# Includes & libraries
SDL2_CLAGS = $(shell sdl2-config --cflags)
SDL2_LIBS = $(shell sdl2-config --libs)
CPPFLAGS = $(addprefix -I ,$(INC_PATH)) $(SDL2_CLAGS) #`sdl2-config --cflags`
LDFLAGS = $(addprefix -L ,$(LIB_PATH)) $(SDL2_LIBS) #`sdl2-config --libs`
LDLIBS = -lft -lftprintf

# Prerequisites
PREREQUISITES_NAME = 	\
						setup_sdl2.sh\
						setup_graphviz.sh\

PREREQUISITES = $(addprefix $(SCRIPTS_PATH), $(PREREQUISITES_NAME))

# Sources
SRC_NAME = 	\
			main.c\
			\
			s_map.c\
			s_rooms.c\
			s_links.c\
			s_ways.c\
			s_lines.c\
			\
			options.c\
			reader.c\
			commands.c\
			validity.c\
			issues.c\
			select.c\
			display.c\
			\
			launch.c\
			move.c\

SRC_NAME_MUTUAL = \
			errors_manager.c\

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_NAME_MUTUAL = $(SRC_NAME_MUTUAL:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME)) \
	  $(addprefix $(SRC_PATH_MUTUAL),$(SRC_NAME_MUTUAL))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME)) \
	  $(addprefix $(OBJ_PATH)$(SRC_PATH_MUTUAL),$(OBJ_NAME_MUTUAL))

# Flags with OS Compatibiliy
OS = $(shell uname)
ifeq ($(OS), Darwin)
	FLAGS_DEFAULT = -Werror -Wall -Wextra
endif
ifeq ($(OS), Linux)
	FLAGS_DEFAULT = -Wno-unused-result
endif
ifdef FLAGS
	ifeq ($(FLAGS), no)
		CFLAGS := $(ADDFLAGS)
	endif
	ifeq ($(FLAGS), debug)
		CFLAGS := $(FLAGS_DEFAULT) -ansi -pedantic -g $(ADDFLAGS)
	endif
else
	CFLAGS := $(FLAGS_DEFAULT) $(ADDFLAGS)
endif

# MAKEFLAGS
MAKE = make --no-print-directory -C #$(MAKEFLAGS)

# Variables
COUNTER=0

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
.PHONY: all, clean, fclean, re, norme, norm, \
		setup_SDL2, SDL2_Darwin, SDL2_Linux \
		init_submodule update_submodule

all: $(NAME)

$(NAME): prerequisites $(OBJ_PATH) $(OBJ)
	@$(CC) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $(NAME)
	@if [ $(COUNTER) -ne 0 ]; then echo -e $(ASSEMBLING); fi;

prerequisites:
#	@$(foreach FILE, $(PREREQUISITES_NAME), echo $(SCRIPTS_PATH)$(PREREQUISITES_NAME))
	@make libftprintf.a

libftprintf.a:
	@$(MAKE) $(PRINTF_PATH) $@

$(OBJ_PATH):
	@echo -e "$(TITLE)build $(NAME)$(END_TITLE)"
	@echo -e "--$(LOG_CLEAR)Flags : $(CFLAGS)"
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(OBJ_PATH)/$(SRC_PATH_MUTUAL)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c 
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@echo -e $(LINKING)
	@$(eval COUNTER=$(shell echo $$(($(COUNTER)+1))))

clean:
	@echo -e "$(TITLE)clean $(NAME)$(END_TITLE)"
	@echo -e $(OBJECTS_DEL)
	@rm -Rf $(OBJ_PATH)
	@$(MAKE) $(PRINTF_PATH) clean_quiet

fclean:
	@echo -e "$(TITLE)fclean $(NAME)$(END_TITLE)"
	@echo -e $(OBJECTS_DEL)
	@rm -Rf $(OBJ_PATH)
	@echo -e $(BIN_DEL)
	@rm -f $(NAME)
	@$(MAKE) $(PRINTF_PATH) fclean_quiet

re: fclean all

# Norm
norme:
	norminette $(SRC)
	norminette $(addprefix $(INC_PATH), *.h)

norm: 
	norminette **/**.[ch] | grep -B 1 "Error\|Warning" || echo "norme OK"

# Submodules
init_submodule:
	git submodule update --init --recursive

update_submodule:
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
