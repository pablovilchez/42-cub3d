/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:59:52 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/30 14:55:39 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../assets/MLX42/include/MLX42/MLX42.h"
# include "../assets/libft/include/libft.h"
# include "cub3d_defines.h"
# include "cub3d_structs.h"
# include <math.h>
# include <memory.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// ----------------- INIT ----------------- //
void		init(char **argv);
void		init_ray(t_ray *ray);
void		steal_parser_data(t_info *info);

// ----------------- PREVENT LEEKS ----------------- //
void		free_parser(t_parser *parser);
void		free_info(t_info *info);
void		general_free(t_info *info);

// ----------------- PARSER ----------------- //
// additional functions
void		put_usage(void);
const char	*get_error_message(enum e_ErrorCode code);
void		put_error(int error_num, char *custom_message);
void		unplanned_exit(t_info *info, int error_code);
void		make_map_rectangular(char **map);
void		map_spaces_to_two(char **map);

// map_parsing.c
void		parser_init(t_info *info, char *argv);
int			check_map_oblig_data(t_parser *parser, int fd, char *line);
int			check_map_format(t_info *info, int fd, char *line);
double		get_player_direction(char c);

// is_bool_functions.c
bool		is_acceptable_map_value(t_parser *p, char **m, int r, int c);
bool		is_texture_or_color(char *s, bool color_check_bool);
bool		is_all_spaces(const char *str);
bool		is_valid_map_char(char c);
bool		is_enough_parser_oblig_data(t_parser *parser);
bool		is_map_point_by_ones(char **map, int r, int c);
bool		is_map_ages_ones(char **map, int r, int c);
bool		is_valid_ext_png(char *texture);

// ray_casting.c
void		ray_casting(t_info *info, int x);

// ray_casting2.c
bool		is_wall(double x, double y, t_info *info);

// ----------------- GRAPHIC ----------------- //
// draw.c
void		draw(t_info *info);
void		graphic_init(t_info *info);
// hook.c
void		ft_hook(void *param);
// move.c
void		move_up(t_info *info);
void		move_down(t_info *info);
void		move_left(t_info *info);
void		move_right(t_info *info);
// rotate.c
void		rot_player(t_info *info, int angle);
#endif
