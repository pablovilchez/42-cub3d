/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map_rectangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:45:49 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/30 11:54:54 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_spaces_to_two(char **map)
{
	int	row;
	int	col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (ft_isspace(map[row][col]))
				map[row][col] = '2';
			col++;
		}
		row++;
	}
}

static int	get_max_len_map(char **map)
{
	int	max_len;
	int	row;
	int	len;

	row = 0;
	max_len = 0;
	len = 0;
	while (map[row])
	{
		len = strlen(map[row]);
		if (len > max_len)
			max_len = len;
		row++;
	}
	return (max_len);
}

char	*get_new_line(int max_len, int len, char *map_row)
{
	int		i;
	char	*new_line;

	i = 0;
	new_line = malloc((len + (max_len - len) + 1) * sizeof(char));
	if (!new_line)
		return (NULL);
	while (map_row[i])
	{
		new_line[i] = map_row[i];
		i++;
	}
	i = len;
	while (i < len + (max_len - len))
		new_line[i++] = '2';
	new_line[len + (max_len - len)] = '\0';
	return (new_line);
}

void	make_map_rectangular(char **map)
{
	int		max_len;
	int		row;
	int		len;
	char	*new_line;

	max_len = get_max_len_map(map);
	row = 0;
	len = 0;
	while (map[row])
	{
		len = ft_strlen(map[row]);
		if (len < max_len)
		{
			new_line = get_new_line(max_len, len, map[row]);
			if (!new_line)
				exit (1);
			free(map[row]);
			map[row] = new_line;
		}
		row++;
	}
}
