/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steal_parser_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:50:18 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/30 11:26:31 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	steal_parser_data(t_info *info)
{
	info->no_txt = mlx_load_png(info->parser->no_txt_loc);
	info->so_txt = mlx_load_png(info->parser->so_txt_loc);
	info->we_txt = mlx_load_png(info->parser->we_txt_loc);
	info->ea_txt = mlx_load_png(info->parser->ea_txt_loc);
	free(info->map);
	info->map = info->parser->map;
	info->player->player_x = info->parser->player_x;
	info->player->player_y = info->parser->player_y;
	info->player->player_angle = info->parser->player_angle;
	info->f_color = info->parser->f_color;
	info->c_color = info->parser->c_color;
	free(info->parser->no_txt_loc);
	free(info->parser->so_txt_loc);
	free(info->parser->we_txt_loc);
	free(info->parser->ea_txt_loc);
	free(info->parser);
	info->parser = NULL;
}
