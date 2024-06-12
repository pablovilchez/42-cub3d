/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:27:11 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/30 12:01:28 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	calc_y_pixel(int w_start, int w_end, int y)
{
	double	relative_y;

	relative_y = (double)(y - w_start) / (w_end - w_start);
	return (relative_y);
}

int	get_texture_pixel_color(mlx_texture_t *texture, double tex_y, double tex_x)
{
	uint8_t	*pixel;
	int		lines_gap;
	int		columns_gap;
	int		bytes;

	lines_gap = (int)(tex_y * (texture->height - 1)) *texture->width;
	columns_gap = (int)(tex_x * texture->height);
	bytes = texture->bytes_per_pixel;
	pixel = texture->pixels + (int)(lines_gap + columns_gap) *bytes;
	return (ft_get_rgba(pixel[0], pixel[1], pixel[2], pixel[3]));
}

void	fill_floor_ceilings_else(t_info *info, int x, int w_start, int w_end)
{
	int		color;
	double	tex_y;
	int		y;

	y = 1;
	while (y < SCR_H)
	{
		if (y < w_start)
			mlx_put_pixel(info->img, x, y, info->c_color);
		else if (y > w_end)
			mlx_put_pixel(info->img, x, y, info->f_color);
		else
		{
			tex_y = calc_y_pixel(w_start, w_end, y);
			color = get_texture_pixel_color(info->ray->texture,
					tex_y, info->ray->tex_start);
			mlx_put_pixel(info->img, x, y, color);
		}
		y++;
	}
}

void	draw(t_info *info)
{
	double	x;
	int		w_height;
	int		w_start;
	int		w_end;
	double	angle_frac;

	x = 0;
	info->ray->angle = info->player->player_angle - ((M_PI / 3) / 2);
	angle_frac = ((M_PI / 3) / SCR_W);
	while (x < SCR_W)
	{
		info->ray->angle = info->ray->angle + angle_frac;
		ray_casting(info, x);
		w_height = SCR_H / info->ray->dist;
		w_start = (SCR_H / 2) - (w_height / 2);
		w_end = (SCR_H / 2) + (w_height / 2);
		fill_floor_ceilings_else(info, x, w_start, w_end);
		x++;
	}
}
