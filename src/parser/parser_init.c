/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:19:00 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/29 16:23:02 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_player_direction(char c)
{
	if (c == 'E')
		return ((3 * M_PI) / 2.0 + 0.001);
	else if (c == 'N')
		return (M_PI);
	else if (c == 'W')
		return (M_PI / 2.0);
	else if (c == 'S')
		return (0);
	return (-1);
}

static int	is_valid_map_extension(char *map)
{
	int	len;

	len = ft_strlen(map);
	return (map[len - 1] == 'b' && map[len - 2] == 'u'
		&& map[len - 3] == 'c' && map[len - 4] == '.');
}

static void	parser_init_data(t_info *info)
{
	info->parser->map = ft_calloc(sizeof(char *), 1);
	if (!info->parser->map)
		unplanned_exit(info, E_MEMORY);
	info->parser->map[0] = NULL;
	info->parser->no_txt_loc = NULL;
	info->parser->so_txt_loc = NULL;
	info->parser->we_txt_loc = NULL;
	info->parser->ea_txt_loc = NULL;
	info->parser->f_color = -1;
	info->parser->c_color = -1;
	info->parser->player_x = -1;
	info->parser->player_y = -1;
	info->parser->player_angle = -1;
}

void	parser_init(t_info *info, char *argv)
{
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	line = NULL;
	parser_init_data(info);
	if (fd < 0 || !is_valid_map_extension(argv))
		unplanned_exit(info, E_INVALID_FILE);
	if (!check_map_oblig_data(info->parser, fd, line))
		unplanned_exit(info, E_OBLIG_DATA);
	if (!is_enough_parser_oblig_data(info->parser))
		unplanned_exit(info, E_OBLIG_DATA);
	if (!check_map_format(info, fd, line))
		unplanned_exit(info, E_INVALID_MAP);
}
