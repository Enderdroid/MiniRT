# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkleiner <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/10 09:56:09 by tkleiner          #+#    #+#              #
#    Updated: 2020/10/10 09:56:17 by tkleiner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = MiniRT
MAIN = main.c
MLX_FLAGS = -lmlx_Linux -lX11 -lXext -lmlx -lm
FLAGS = -Wall -Wextra -Werror
SRC_DIR = ./src
GNL_DIR = $(SRC_DIR)/get_next_line
LST_DIR = $(SRC_DIR)/list
VEC_DIR = $(SRC_DIR)/vectors
UTL_DIR = $(SRC_DIR)/utils
CAM_DIR = $(SRC_DIR)/cameras
RND_DIR = $(SRC_DIR)/render
OTH_DIR = $(SRC_DIR)/other
PFB_DIR = $(SRC_DIR)/prefabs
INC_DIR = ./include
OBJ_DIR = ./obj
HEADERS = $(INC_DIR)/*.h

RND_SRC	:=		color_utils.c	get_ratio.c	shadows.c	draw_scene.c	intersect.c		
CAM_SRC	:=		camera.c		create_bmp.c
OTH_SRC	:=		fill_list.c		parser.c	rt_validate.c	val_parse.c
PFB_SRC	:=		cylinder.c		plane.c		sphere.c		square.c	triangle.c
MRT_SRC	:=		$(RND_SRC)	$(CAM_SRC)	$(OTH_SRC)	$(PFB_SRC)
MRT_OBJ	:=		$(MRT_SRC:.c=.o)
RND_SRC	:=		$(addprefix $(RND_DIR)/, $(RND_SRC))
CAM_SRC	:=		$(addprefix $(CAM_DIR)/, $(CAM_SRC))
OTH_SRC	:=		$(addprefix $(OTH_DIR)/, $(OTH_SRC))
PFB_SRC	:=		$(addprefix $(PFB_DIR)/, $(PFB_SRC))
MRT_SRC	:=		$(RND_SRC)	$(CAM_SRC)	$(OTH_SRC)	$(PFB_SRC)

LST_SRC	:=		lst_utils.c		ft_lst_clear.c
LST_OBJ :=		$(LST_SRC:.c=.o)
LST_SRC	:=		$(addprefix $(LST_DIR)/, $(LST_SRC))

UTL_SRC	:=		ft_itoa.c		ft_split.c	ft_strjoin.c	ft_str_cpy.c \
				str_utils.c		utils.c		val_utils.c			mlx_utils.c \
				ft_exit.c	
UTL_OBJ :=		$(UTL_SRC:.c=.o)
UTL_SRC	:=		$(addprefix $(UTL_DIR)/, $(UTL_SRC))

VEC_SRC	:=		s_vec_math.c	vec_utils.c	vec_calc.c
VEC_OBJ :=		$(VEC_SRC:.c=.o)
VEC_SRC	:=		$(addprefix $(VEC_DIR)/, $(VEC_SRC))

GNL_SRC	:=		get_next_line.c \
				get_next_line_utils.c
GNL_OBJ	:=		$(GNL_SRC:.c=.o)
GNL_SRC :=		$(addprefix $(GNL_DIR)/, $(GNL_SRC))

M_SRC	:=		$(MRT_SRC)	$(LST_SRC)	$(UTL_SRC)	$(VEC_SRC)	$(GNL_SRC)
M_OBJ	:=		$(MRT_OBJ)	$(LST_OBJ)	$(UTL_OBJ)	$(VEC_OBJ)	$(GNL_OBJ)
M_OBJ	:=		$(addprefix $(OBJ_DIR)/, $(M_OBJ))


.PHONY: all clean fclean re

all: $(NAME)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(NAME): $(MAIN) $(M_OBJ)
	gcc $(FLAGS) $(MAIN) $(M_OBJ) -I./include -L. $(MLX_FLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/*/%.c $(HEADERS) | $(OBJ_DIR)
	gcc $(FLAGS) -I./include -L. -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)/*.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all
