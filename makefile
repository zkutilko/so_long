# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zkutilko <zkutilko@student.42prague.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 19:39:06 by zkutilko          #+#    #+#              #
#    Updated: 2024/10/01 19:47:38 by zkutilko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MNLBX_FLAGS = -L./minilibx-linux -lmlx -lXext -lX11
VALGRIND = @valgrind --leak-check=full --show-leak-kinds=all \
           --track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes
LIBFT = ./libft/libft.a
REMOVE = rm -f
SRCS_DIR = src/
SRCS = $(addprefix $(SRCS_DIR), open_image.c)
OBJS = $(SRCS:.c=.o)
INCLUDES = -I ./libft -I ./minilibx-linux

# Rule for building object files
$(SRCS_DIR)%.o: $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

# Rule for building the executable
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MNLBX_FLAGS)
	@echo "$(NAME) compiled successfully."

# Build all targets
all: $(LIBFT) $(NAME)

# Rule for building libft
$(LIBFT):
	make -C ./libft

# Clean up object files and other build artifacts
clean:
	make clean -C ./libft
	$(REMOVE) $(OBJS)
	@echo "Object files removed."

# Fully clean the project
fclean: clean
	$(REMOVE) $(NAME)
	@echo "$(NAME) removed."

# Rebuild everything
re: fclean all

# Run the project with Valgrind
run: $(NAME)
	$(VALGRIND) ./${NAME} assets/maps/valid/map4.ber

.PHONY: all clean fclean re run
# NAME =		so_long
# CC =		gcc
# CFLAGS =	-Wall -Wextra -Werror
# MNLBX_FLAGS = -L./minilibx-linux -lmlx -lXext -lX11
# VALGRIND =	@valgrind --leak-check=full --show-leak-kinds=all \
#             --track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes
# LIBFT =		./libft/libft.a
# REMOVE =	rm -f
# SRCS_DIR =	src/
# SRCS =		$(addprefix $(SRCS_DIR), open_image.c)  # Opraveno
# OBJS =		$(SRCS:.c=.o)
# INCLUDES =	-I ./libft -I ./minilibx-linux

# NAME =		so_long
# CC =		gcc
# CFLAGS =	-Wall -Wextra -Werror
# MNLBX_FLAGS = -L./minilibx-linux -lmlx -lXext -lX11
# VALGRIND =	@valgrind --leak-check=full --show-leak-kinds=all \
#             --track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes
# LIBFT =		.//libft/libft.a
# REMOVE =	rm -f
# SRCS_DIR =	src/
# SRCS =		$(addprefix $(SRCS_DIR), open_image.c)
# OBJS =		$(SRCS:.c=.o)
# INCLUDES =	-I ./libft -I ./minilibx-linux

# .c.o:
# 	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

# $(NAME): $(OBJS) $(LIBFT)
# 	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MNLBX_FLAGS)
# 	@echo "$(NAME) compiled successfully."

# all:			${LIBFT} ${NAME}

# $(LIBFT):
# 	make -C libraries/Libft

# clean:
# 	make clean -C libraries/Libft
# 	$(REMOVE) $(OBJS)
# 	@echo "Object files removed."

# fclean:
# 	$(REMOVE) $(NAME)
# 	@echo "$(NAME) removed."

# re:				fclean all

# run:			${NAME}
# 	${VALGRIND} ./${NAME} assets/maps/valid/map4.ber

# .PHONY:			all clean fclean re valgrind run
