##
## EPITECH PROJECT, 2025
## Project - Carpet lib
## File description:
## Makefile used to build
## carpet-lib
##

CC = gcc

CFLAGS =

NAME = libcarpet.a

INCLUDE_DIRS = -I./include
LIBS = -lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio -lm

SRC_FILES =	src/assets/fonts/crpt_fetch_font.c								\
			src/assets/fonts/crpt_load_font.c								\
			src/assets/fonts/crpt_load_font_src.c							\
			src/assets/textures/crpt_fetch_texture.c						\
			src/assets/textures/crpt_load_texture.c							\
			src/assets/textures/crpt_load_texture_src.c						\
			src/assets/crpt_asset_manager_get.c								\
			src/assets/crpt_asset_manager_load.c							\
			src/assets/crpt_assets_init.c									\
			src/assets/crpt_assets_term.c									\
			src/camera/crpt_camera_get_fov.c								\
			src/camera/crpt_camera_get_position.c							\
			src/camera/crpt_camera_get_rotation.c							\
			src/camera/crpt_camera_interpolate_fov.c						\
			src/camera/crpt_camera_set_fov.c								\
			src/camera/crpt_camera_set_rotation.c							\
			src/errno/crpt_errno.c											\
			src/errno/crpt_perror.c											\
			src/errno/crpt_strerror.c										\
			src/event/crpt_event_close.c									\
			src/event/crpt_event_init.c										\
			src/event/crpt_event_poll.c										\
			src/game/crpt_game_get.c										\
			src/game/crpt_game_init.c										\
			src/game/crpt_game_mainloop.c									\
			src/game/crpt_game_stop.c										\
			src/game/crpt_game_term.c										\
			src/map/crpt_map_add.c											\
			src/map/crpt_map_create.c										\
			src/map/crpt_map_create_border.c								\
			src/map/crpt_map_delete.c										\
			src/map/crpt_map_draw3.c										\
			src/map/crpt_map_fill_empty.c									\
			src/map/crpt_map_get.c											\
			src/map/crpt_map_is_solid.c										\
			src/map/crpt_map_randomize.c									\
			src/map/crpt_map_remove.c										\
			src/memory/ccalloc.c											\
			src/memory/cmalloc.c											\
			src/memory/crealloc.c											\
			src/object/internal/crpt_object_create_in_map.c					\
			src/object/internal/crpt_object_dup_in_map.c					\
			src/object/crpt_object_create.c									\
			src/object/crpt_object_delete.c									\
			src/object/crpt_object_dup.c									\
			src/ray/crpt_ray_draw3.c										\
			src/ray/crpt_raycast.c											\
			src/scene/default/crpt_scene_default_get.c						\
			src/scene/default/crpt_scene_default_load.c						\
			src/scene/default/crpt_scene_default_unload.c					\
			src/scene/default/crpt_scene_default_update.c					\
			src/scene/crpt_scene_draw.c										\
			src/scene/crpt_scene_set.c										\
			src/scene/crpt_scene_update.c									\
			src/utils/array/crpt_array_append.c								\
			src/utils/array/crpt_array_delete.c								\
			src/utils/array/crpt_array_reserve.c							\
			src/utils/graphics/crpt_draw_line.c								\
			src/utils/hashtable/crpt_hash.c									\
			src/utils/hashtable/crpt_hashtable_delete.c						\
			src/utils/hashtable/crpt_hashtable_get.c						\
			src/utils/hashtable/crpt_hashtable_set.c						\
			src/utils/vector/crpt_vec_add.c									\
			src/utils/vector/crpt_vec_distance.c							\
			src/utils/vector/crpt_vec_dot.c									\
			src/utils/vector/crpt_vec_magnitude.c							\
			src/utils/vector/crpt_vec_normalized.c							\
			src/utils/vector/crpt_vec_scale.c								\
			src/utils/vector/crpt_vec_sub.c									\

OBJ_FILES = $(SRC_FILES:.c=.o)

CAF_FILES =	src/assets/default/crpt_asset_arial.caf							\

ASS_FILES =	$(CAF_FILES:.caf=.o)

SUCCESS_MSG_FORMAT = "\033[92;1m   %s\033[0m\n"
ERROR_MSG_FORMAT = "\033[31;1m   %s\033[0m\n"
SUCCESS_MISC_FORMAT = "\033[94;1m   %s\033[0m\n"

.PHONY: all debug sanitize clean fclean re

all: CFLAGS += -O3
all: $(NAME)

%.o: %.caf
	@$(CC) -x c -c $< $(INCLUDE_DIRS) $(LIBS) $(CFLAGS) -o $@ || \
	(printf $(ERROR_MSG_FORMAT) "Error loading $<"; false)
	@printf $(SUCCESS_MISC_FORMAT) "Successfully loaded $<"

%.o: %.c
	@$(CC) -c $< $(INCLUDE_DIRS) $(LIBS) $(CFLAGS) -o $@ || \
	(printf $(ERROR_MSG_FORMAT) "Error compiling $<"; false)
	@printf $(SUCCESS_MSG_FORMAT) "Successfully compiled $<"

$(NAME): $(ASS_FILES) $(OBJ_FILES)
	@ar rc $(NAME) $(OBJ_FILES) $(ASS_FILES) || \
	(printf $(ERROR_MSG_FORMAT) "Error creating $(NAME) archive"; false)
	@printf $(SUCCESS_MSG_FORMAT) "Successfully created $(NAME) archive"

debug: CFLAGS += -ggdb -Wall -Wextra
debug: fclean $(NAME)

sanitize: CFLAGS += -g -lasan -fsanitize=address
sanitize: fclean $(NAME)

clean:
	@rm -f $(OBJ_FILES)
	@rm -f $(ASS_FILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all
