/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:41:38 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/30 15:25:58 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_player(t_player *player)
{
	player->player_x = -1;
	player->player_y = -1;
	player->player_angle = -1;
}

void	init_ray(t_ray *ray)
{
	ray->angle = -1;
	ray->cx_x = -1;
	ray->cx_y = -1;
	ray->dist_x = -1;
	ray->cy_x = -1;
	ray->cy_y = -1;
	ray->dist_y = -1;
	ray->id = -1;
	ray->height = -1;
}

static void	init_structs(t_info *info)
{
	info->player = (t_player *)malloc(sizeof(t_player));
	if (!info->player)
		unplanned_exit(info, E_MEMORY);
	init_player(info->player);
	info->ray = (t_ray *)malloc(sizeof(t_ray));
	if (!info->ray)
		unplanned_exit(info, E_MEMORY);
	init_ray(info->ray);
	steal_parser_data(info);
	if (!info->no_txt || !info->so_txt || !info->we_txt || !info->ea_txt)
		unplanned_exit(info, E_INVALID_FILE);
}

static t_info	*initial_info(void)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		unplanned_exit(info, E_MEMORY);
	info->parser = (t_parser *)malloc(sizeof(t_parser));
	if (!info->parser)
		unplanned_exit(info, E_MEMORY);
	info->player = NULL;
	info->ray = NULL;
	info->mlx = NULL;
	info->img = NULL;
	info->no_txt = NULL;
	info->so_txt = NULL;
	info->we_txt = NULL;
	info->ea_txt = NULL;
	info->map = ft_calloc(1, sizeof(char *));
	info->map[0] = NULL;
	info->f_color = -1;
	info->c_color = -1;
	return (info);
}

void	init(char **argv)
{
	t_info	*info;

	info = initial_info();
	parser_init(info, argv[1]);
	init_structs(info);
	graphic_init(info);
	general_free(info);
}
