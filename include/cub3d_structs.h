/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:55:58 by pvilchez          #+#    #+#             */
/*   Updated: 2024/01/30 12:02:44 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCTS_H
# define CUB3D_STRUCTS_H

# include "cub3d.h"

typedef struct s_ray
{
	int				id;
	double			dist;
	mlx_texture_t	*texture;
	double			tex_start;
	double			angle;
	double			cx_x;
	double			cx_y;
	double			dist_x;
	double			cy_x;
	double			cy_y;
	double			dist_y;
	double			height;
	int				coll_cell_x;
	int				coll_cell_y;
}				t_ray;

typedef struct s_parser
{
	char		*no_txt_loc;
	char		*so_txt_loc;
	char		*we_txt_loc;
	char		*ea_txt_loc;
	int			f_color;
	int			c_color;
	char		**map;
	double		player_x;
	double		player_y;
	double		player_angle;
}				t_parser;

typedef struct s_player
{
	double		player_x;
	double		player_y;
	double		player_angle;
}		t_player;

typedef struct s_info
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_texture_t	*no_txt;
	mlx_texture_t	*so_txt;
	mlx_texture_t	*we_txt;
	mlx_texture_t	*ea_txt;
	int				columns;
	int				rows;
	int				f_color;
	int				c_color;
	struct s_player	*player;
	struct s_parser	*parser;
	struct s_ray	*ray;
	char			**map;
}				t_info;

#endif
