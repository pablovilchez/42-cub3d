/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_oblig_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:33:06 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/30 20:01:55 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	*str_get_color(char *line)
{
	char	**color;
	char	*c_line;
	int		*c_arr;
	int		i;

	i = 0;
	c_arr = (int *)malloc(sizeof(int) * 4);
	if (!c_arr)
		return (put_error(E_MEMORY, 0), NULL);
	c_line = ft_str_del_space(line + 1);
	color = ft_split(c_line, ',');
	while (i < 3)
	{
		if (!color[i])
			return (free(c_line), ft_split_free(color), free(c_arr), NULL);
		c_arr[i] = ft_atoi(color[i]);
		if (!ft_aredigits(color[i]) || c_arr[i] > 255 || c_arr[i] < 0)
			return (free(c_line), free(c_arr), ft_split_free(color), NULL);
		i++;
	}
	c_arr[i] = '\0';
	return (free(c_line), ft_split_free(color), c_arr);
}

static int	check_map_color(char *line, t_parser *parser)
{
	int	*c_arr;

	c_arr = str_get_color(line);
	if (!c_arr)
		return (0);
	if (line[0] == 'F')
		parser->f_color = ft_get_rgba(c_arr[0], c_arr[1], c_arr[2], 254);
	else if (line[0] == 'C')
		parser->c_color = ft_get_rgba(c_arr[0], c_arr[1], c_arr[2], 254);
	return (free(c_arr), 1);
}

static int	check_map_textures(char *line, t_parser *parser)
{
	int		fd;
	char	*texture_loc;

	texture_loc = ft_str_del_space(line + 2);
	fd = open(texture_loc, O_RDONLY);
	if (fd < 0)
		return (free(texture_loc), 0);
	if (!is_valid_ext_png(texture_loc))
		return (free(texture_loc), close(fd), 0);
	if (line[0] == 'N' && line[1] == 'O' && !parser->no_txt_loc)
		parser->no_txt_loc = ft_strdup(texture_loc);
	else if (line[0] == 'S' && line[1] == 'O' && !parser->so_txt_loc)
		parser->so_txt_loc = ft_strdup(texture_loc);
	else if (line[0] == 'W' && line[1] == 'E' && !parser->we_txt_loc)
		parser->we_txt_loc = ft_strdup(texture_loc);
	else if (line[0] == 'E' && line[1] == 'A' && !parser->ea_txt_loc)
		parser->ea_txt_loc = ft_strdup(texture_loc);
	return (close(fd), free(texture_loc), 1);
}

int	check_map_oblig_data(t_parser *parser, int fd, char *line)
{
	char	*no_space_line;

	no_space_line = NULL;
	while (!is_enough_parser_oblig_data(parser) && get_next_line(fd, &line))
	{
		no_space_line = ft_strtrim(line, " ");
		free(line);
		if (is_texture_or_color(no_space_line, false))
		{
			if (!check_map_textures(no_space_line, parser))
				return (free(no_space_line), close(fd), 0);
		}
		else if (is_texture_or_color(no_space_line, true))
		{
			if (!check_map_color(no_space_line, parser))
				return (free(no_space_line), close(fd), 0);
		}
		free(no_space_line);
	}
	return (1);
}
