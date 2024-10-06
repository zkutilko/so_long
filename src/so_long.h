/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkutilko <zkutilko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 20:08:07 by zkutilko          #+#    #+#             */
/*   Updated: 2024/10/06 13:40:26 by zkutilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../libft/libft.h"

# define IMG_HEIGHT				32
# define IMG_WIDTH				32

# define WALL					"1"
# define FLOOR					"0"
# define COLL					"C"
# define EXIT					"E"
# define PLAYER					"P"

# define KEY_W					119
# define KEY_A					97
# define KEY_S					115
# define KEy_D					100

# define KEY_UP					65362
# define KEY_LEFT				65361
# define KEY_RIGHT				65363
# define KEY_DOWN				65364

# define KEY_ESC				65307

# define FRONT					1
# define LEFT					2
# define RIGHT					3
# define DOWN					4

# define WALL_XPM				"../images/wall.xpm"
# define FLOOR_XPM				"../images/floor.xpm"
# define COLL_XPM				"../images/coll.xpm"
# define P_UP_XPM				"../images/up.xpm"
# define P_LEFT_XPM				"../images/left.xpm"
# define P_RIGHT_XPM			"../images/right.xpm"
# define P_DOWN_XPM				"../images/down.xpm"
# define EXIT_XPM				"../images/exit.xpm"

# define GREEN					"\033[0;32m"
# define RED					"\033[1;31m"
# define GREY					"\033[0;90m"
# define RESET					"\033[0m"



typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		movements;
	int		player;
} t_game;

#endif
