/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:20:54 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/30 11:26:56 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_parser(t_parser *parser)
{
	if (parser->no_txt_loc)
		free(parser->no_txt_loc);
	parser->no_txt_loc = NULL;
	if (parser->so_txt_loc)
		free(parser->so_txt_loc);
	parser->so_txt_loc = NULL;
	if (parser->we_txt_loc)
		free(parser->we_txt_loc);
	parser->we_txt_loc = NULL;
	if (parser->ea_txt_loc)
		free(parser->ea_txt_loc);
	parser->ea_txt_loc = NULL;
	ft_split_free(parser->map);
	free(parser);
}

void	free_info(t_info *info)
{
	if (info->no_txt)
		mlx_delete_texture(info->no_txt);
	info->no_txt = NULL;
	if (info->so_txt)
		mlx_delete_texture(info->so_txt);
	info->so_txt = NULL;
	if (info->we_txt)
		mlx_delete_texture(info->we_txt);
	info->we_txt = NULL;
	if (info->ea_txt)
		mlx_delete_texture(info->ea_txt);
	info->ea_txt = NULL;
	if (info->img)
		mlx_delete_image(info->mlx, info->img);
	if (info->map)
		ft_split_free(info->map);
	free(info);
}

void	general_free(t_info *info)
{
	if (info->parser)
		free_parser(info->parser);
	if (info->player)
		free(info->player);
	if (info->ray)
		free(info->ray);
	if (info)
		free_info(info);
}
