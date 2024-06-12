/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_bool_funcs2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:32:05 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/30 14:55:16 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_valid_ext_png(char *texture)
{
	int	len;

	len = ft_strlen(texture);
	if (len >= 4 && texture[len - 1] == 'g' && texture[len - 2] == 'n'
		&& texture[len - 3] == 'p' && texture[len - 4] == '.')
		return (true);
	return (false);
}

bool	is_map_point_by_ones(char **map, int r, int c)
{
	if (map[r - 1][c] == '2' || map[r + 1][c] == '2'
		|| map[r][c - 1] == '2' || map[r][c + 1] == '2')
		return (false);
	return (true);
}

bool	is_map_ages_ones(char **map, int r, int c)
{
	if (r == 0 || r == ft_matrxlen(map) - 1
		|| c == 0 || (size_t)c == ft_strlen(map[r]) - 1)
		return (false);
	return (true);
}
