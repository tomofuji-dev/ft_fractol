NAME		= 	fractol

SRC_DIR		= 	src
OBJ_DIR		= 	obj
INCLUDE_DIR	= 	include

LIBFT_DIR	=	libft
LIBFT		=	$(LIBFT_DIR)/libft.a
MLX_DIR		=	minilibx
MLX			=	$(MLX_DIR)/libmlx.a

LIBRARY		=	-L $(LIBFT_DIR) -L $(MLX_DIR)
INCLUDE_DIR	=	include
INCLUDES	=	-I $(INCLUDE_DIR)
SRCDIRS		=	$(shell find $(SRC_DIR) -type d)
INCLUDES 	+=	$(addprefix -I,$(SRCDIRS))

CC			=	cc
RM			=	rm
CFLAGS		=	-Wall -Wextra -Werror

SRCS		=	$(SRC_DIR)/test.c
OBJS		=	$(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all:			$(NAME)

$(NAME):		$(MLX) $(LIBFT) $(OBJS)
				$(CC) $(OBJS) $(CFLAGS) $(LIBRARY) -o $(NAME)

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