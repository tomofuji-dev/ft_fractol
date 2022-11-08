NAME		= 	fractol

SRC_DIR		= 	src
OBJ_DIR		= 	obj
INCLUDE_DIR	= 	include

LIBFT_DIR	=	libft
LIBFT		=	$(LIBFT_DIR)/libft.a
MLX_DIR		=	minilibx
MLX			=	$(MLX_DIR)/libmlx.a

LIB_DIR		=	-L $(LIBFT_DIR) -L $(MLX_DIR) -L /usr/X11/lib
LIBRARY		=	-lmlx -lXext -lX11 -lm -lft
INCLUDE_DIR	=	include
INCLUDES	=	-I $(INCLUDE_DIR) -I $(MLX_DIR) -I /usr/X11/include
SRCDIRS		=	$(shell find $(SRC_DIR) -type d)
INCLUDES 	+=	$(addprefix -I,$(SRCDIRS))

CC			=	cc
RM			=	rm
CFLAGS		=	-Wall -Wextra -Werror

SRCS		=	$(SRC_DIR)/test.c \
				$(SRC_DIR)/hook/setup_hook.c \
				$(SRC_DIR)/hook/handle_key.c \
				$(SRC_DIR)/hook/handle_loop.c \
				$(SRC_DIR)/init/init_env.c \
				$(SRC_DIR)/init/arg_parse.c
OBJS		=	$(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEPS		=	$(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.d)
.PHONY: $(DEPS)

# LINUX | OSX | ARM
UNAME_S := $(shell uname -s)
UNAME_P := $(shell uname -p)

# Linux
ifeq ($(UNAME_S),Linux)
endif

# macos x86
ifeq ($(UNAME_S),Darwin)
	FRAMEWORK = -framework OpenGL -framework AppKit
endif

# macos ARM (m1/m2...)
ifneq ($(filter arm%, $(UNAME_P)),)
	FRAMEWORK = -framework OpenGL -framework AppKit
endif

all:			$(NAME)

$(NAME):		$(MLX) $(LIBFT) $(OBJS)
				$(CC) $(OBJS) $(CFLAGS) $(LIB_DIR) $(LIBRARY) $(FRAMEWORK) -o $(NAME)

$(MLX):
				$(MAKE) -C $(MLX_DIR)

$(LIBFT):
				$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
				@mkdir -p $$(dirname $@)
				$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

clean:
				$(RM) -rf $(OBJS) $(OBJ_DIR)
				$(MAKE) -C $(LIBFT_DIR) clean
				$(MAKE) -C $(MLX_DIR) clean

fclean:			clean
				$(RM) -f $(NAME)
				$(MAKE) -C $(LIBFT_DIR) fclean

re:				fclean all

.PHONY:			all clean fclean re
-include $(DEPS)