/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:20:47 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/30 11:33:15 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_is_surrounded_by_ones(char **map)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] == '0')
				if (!is_map_ages_ones(map, row, col)
					|| !is_map_point_by_ones(map, row, col))
					return (put_error(0, "Error: No surrounded by 1's\n"), 0);
			col++;
		}
		row++;
	}
	return (1);
}

static int	check_acceptable_map_values(t_info *info, char **m)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (m[row])
	{
		col = 0;
		while (m[row][col])
		{
			if (!is_acceptable_map_value(info->parser, m, row, col))
				return (0);
			col++;
		}
		row++;
	}
	info->columns = col;
	info->rows = row;
	if (info->parser->player_x == -1)
		return (put_error(0, "Error: The player was not found\n"), 0);
	return (1);
}

static char	*get_map_line(char *line)
{
	size_t	i;
	char	*map_line;
	size_t	len;

	len = ft_strlen(line);
	map_line = malloc(len * sizeof(char) + 1);
	if (!map_line)
		return (put_error(E_MEMORY, 0), NULL);
	i = 0;
	while (i < len)
	{
		map_line[i] = line[i];
		i++;
	}
	map_line[i] = '\0';
	return (map_line);
}

static char	**get_map(int fd, char *last_line)
{
	char	**map;
	char	*line;
	char	*temp_line;
	int		line_count;

	map = NULL;
	line = last_line;
	line_count = 0;
	while (line)
	{
		temp_line = get_next_line(fd, NULL);
		map = ft_realloc(map, (line_count + 2) * sizeof(char *));
		map[line_count] = get_map_line(line);
		line_count++;
		free(line);
		line = temp_line;
	}
	map[line_count] = NULL;
	return (map);
}

int	check_map_format(t_info *info, int fd, char *line)
{
	char	**map;

	map = NULL;
	while (get_next_line(fd, &line) && is_all_spaces(line))
		free(line);
	if (line == NULL)
		return (close(fd), put_error(0, "Error: No map\n"), 0);
	map = get_map(fd, line);
	if (!map)
		return (free(line), close(fd), 0);
	map_spaces_to_two(map);
	make_map_rectangular(map);
	if (!check_acceptable_map_values(info, map)
		|| !check_is_surrounded_by_ones(map))
		return (close(fd), ft_split_free(map), 0);
	free(info->parser->map);
	info->parser->map = map;
	return (1);
}
