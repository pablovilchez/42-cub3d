/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_defines.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:55:58 by pvilchez          #+#    #+#             */
/*   Updated: 2024/01/30 12:01:06 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_DEFINES_H
# define CUB3D_DEFINES_H

# include "cub3d.h"

# define SCR_H 720
# define SCR_W 1280
# define MOVE_SPEED 0.045
# define ROT_SPEED 0.045
# define DBGRAYPERCENT 10

enum	e_ErrorCode
{
	E_MEMORY = 1,
	E_OBLIG_DATA = 2,
	E_INVALID_FILE = 3,
	E_INVALID_MAP = 4,
	E_MLX = 5,
};

#endif
