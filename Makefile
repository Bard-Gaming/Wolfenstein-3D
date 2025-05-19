##
## EPITECH PROJECT, 2025
## Project - Carpet lib
## File description:
## Makefile used to build
## the Wolfenstein 3D game.
##

CC = gcc

CFLAGS =

NAME = wolf3d

CRPT_DIR = lib/carpet
CRPT_BIN = $(CRPT_DIR)/libcarpet.a
CRPT_RULE =

LIBS =	-L./$(CRPT_DIR) -lcarpet											\
		-lcsfml-audio -lcsfml-graphics -lcsfml-window -lcsfml-system		\
		-lm																	\

INCLUDE_DIRS = -I./include -I./$(CRPT_DIR)/include

SRC_FILES =	main.c															\

OBJ_FILES = $(SRC_FILES:.c=.o)

SUCCESS_MSG_FORMAT = "\033[92;1m   %s\033[0m\n"
ERROR_MSG_FORMAT = "\033[31;1m   %s\033[0m\n"

.PHONY: all debug sanitize clean fclean re

all: CFLAGS += -O3
all: $(NAME)

$(CRPT_BIN):
	@make -s -C $(CRPT_DIR) $(CRPT_RULE)
	@echo

%.o: %.c
	@$(CC) -c $< $(INCLUDE_DIRS) $(LIBS) $(CFLAGS) -o $@ || \
	(printf $(ERROR_MSG_FORMAT) "Error compiling $<"; false)
	@printf $(SUCCESS_MSG_FORMAT) "Successfully compiled $<"

$(NAME): $(CRPT_BIN) $(OBJ_FILES)
	@$(CC) -o $(NAME) $(OBJ_FILES) $(INCLUDE_DIRS) $(LIBS) || \
	(printf $(ERROR_MSG_FORMAT) "Error building $(NAME)"; false)
	@printf $(SUCCESS_MSG_FORMAT) "Successfully built $(NAME)"

debug: CFLAGS += -ggdb -Wall -Wextra
debug: CRPT_RULE = debug
debug: fclean $(NAME)

sanitize: CFLAGS += -g -lasan -fsanitize=address
sanitize: CRPT_RULE = sanitize
sanitize: fclean $(NAME)

clean:
	@make -s -C $(CRPT_DIR) clean
	@rm -f $(OBJ_FILES)

fclean: clean
	@make -s -C $(CRPT_DIR) fclean
	@rm -f $(NAME)

re: fclean all
