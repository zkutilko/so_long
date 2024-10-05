/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkutilko <zkutilko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 20:08:07 by zkutilko          #+#    #+#             */
/*   Updated: 2024/10/01 19:50:08 by zkutilko         ###   ########.fr       */
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

# define WALL_XPM				"../images/wall.xpm"
# define FLOOR_XPM				"../images/floor.xpm"
# define COLL_XPM				"../images/coll.xpm"
# define PLAYER_XPM				"../images/player.xpm"
# define EXIT_XPM				"../images/exit.xpm"

#endif
