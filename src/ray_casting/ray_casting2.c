/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:25:03 by pvilchez          #+#    #+#             */
/*   Updated: 2024/01/30 12:03:17 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	calc_next_x(double x, t_info *info)
{
	if (x - info->player->player_x < 0)
	{
		if (x == floor(x))
			return (floor(x) - 1);
		else
			return (floor(x));
	}
	else
		return (floor(x));
}

int	calc_next_y(double y, t_info *info)
{
	if (y - info->player->player_y < 0)
	{
		if (y == floor(y))
			return (floor(y) - 1);
		else
			return (floor(y));
	}
	else
		return (floor(y));
}

bool	is_wall(double x, double y, t_info *info)
{
	int	next_x;
	int	next_y;

	if (x < 0)
		next_x = 0;
	else if (x > info->rows - 1)
		next_x = info->rows - 1;
	else
		next_x = calc_next_x(x, info);
	if (y < 0)
		next_y = 0;
	else if (y > info->columns - 1)
		next_y = info->columns - 1;
	else
		next_y = calc_next_y(y, info);
	if (info->map[next_x][next_y] != '0')
	{
		info->ray->coll_cell_x = next_x;
		info->ray->coll_cell_y = next_y;
		return (true);
	}
	return (false);
}
