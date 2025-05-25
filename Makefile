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

SRC_FILES =	src/main.c														\
			src/enemy/soldier/create_soldier.c								\
			src/enemy/soldier/hurt_soldier.c								\
			src/enemy/soldier/kill_soldier.c								\
			src/enemy/soldier/load_soldier_assets.c							\
			src/enemy/soldier/set_soldier_state.c							\
			src/enemy/soldier/unload_soldier_assets.c						\
			src/enemy/soldier/update_soldier.c								\
			src/enemy/soldier/update_soldier_texture.c						\
			src/enemy/create_enemy.c										\
			src/enemy/hurt_enemy.c											\
			src/enemy/kill_enemy.c											\
			src/enemy/set_enemy_max_health.c								\
			src/player/draw_player.c										\
			src/player/get_player.c											\
			src/player/hurt_player.c										\
			src/player/init_player.c										\
			src/player/load_player_assets.c									\
			src/player/player_press_key.c									\
			src/player/player_use_weapon.c									\
			src/player/player_weapons.c										\
			src/player/set_player_weapon.c									\
			src/player/unload_player_assets.c								\
			src/player/update_player.c										\
			src/player/update_player_fixed.c								\
			src/scene/level/draw_level_scene_ui.c							\
			src/scene/level/level_scene_release_key.c						\
			src/scene/level/load_level_scene.c								\
			src/scene/level/set_level_scene.c								\
			src/scene/level/unload_level_scene.c							\
			src/scene/level/update_level_scene.c							\
			src/scene/level/update_level_scene_fixed.c						\
			src/scene/start/draw_start_scene_ui.c							\
			src/scene/start/load_start_scene.c								\
			src/scene/start/set_start_scene.c								\
			src/scene/start/start_scene_mouse_move.c						\
			src/scene/start/start_scene_onclick.c							\
			src/scene/start/unload_start_scene.c							\
			src/settings/get_input_vec.c									\
			src/settings/get_settings.c										\
			src/settings/is_key_pressed.c									\

OBJ_FILES = $(SRC_FILES:.c=.o)

SUCCESS_MSG_FORMAT = "\033[92;1m   %s\033[0m\n"
ERROR_MSG_FORMAT = "\033[31;1m   %s\033[0m\n"

.PHONY: all debug perf sanitize clean fclean re

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

perf: LIBS := -pg $(LIBS)
perf: CFLAGS += -g
perf: CRPT_RULE = perf
perf: fclean $(NAME)
	@./$(NAME)
	@gprof -bp $(NAME)

sanitize: LIBS := -lasan $(LIBS)
sanitize: CFLAGS += -g -fsanitize=address
sanitize: CRPT_RULE = sanitize
sanitize: fclean $(NAME)

clean:
	@make -s -C $(CRPT_DIR) clean
	@rm -f $(OBJ_FILES)

fclean: clean
	@make -s -C $(CRPT_DIR) fclean
	@rm -f $(NAME)

re: fclean all
