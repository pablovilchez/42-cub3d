/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:04:36 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/28 13:01:50 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rot_player(t_info *info, int angle)
{
	double	new_angle;

	new_angle = info->player->player_angle + (ROT_SPEED * angle);
	if (new_angle > 2 * M_PI)
		new_angle -= 2 * M_PI;
	else if (new_angle < 0)
		new_angle += 2 * M_PI;
	info->player->player_angle = new_angle;
}

void	move(t_info *info, int direction)
{
	double	dis_x;
	double	new_x;
	double	dis_y;
	double	new_y;
	double	ref_angle;

	if (direction == 1)
		ref_angle = info->player->player_angle + M_PI_2;
	else if (direction == 2)
		ref_angle = info->player->player_angle - M_PI_2;
	else if (direction == 3)
		ref_angle = info->player->player_angle;
	else
		ref_angle = info->player->player_angle + M_PI;
	dis_x = MOVE_SPEED * sin(ref_angle);
	new_x = info->player->player_x + dis_x;
	dis_y = MOVE_SPEED * cos(ref_angle);
	new_y = info->player->player_y + dis_y;
	if (!is_wall(new_x, new_y, info))
	{
		info->player->player_x = new_x;
		info->player->player_y = new_y;
	}
}

void	ft_hook(void *param)
{
	t_info	*info;

	info = (t_info *)param;
	if (mlx_is_key_down(info->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(info->mlx);
	if (mlx_is_key_down(info->mlx, MLX_KEY_RIGHT))
		rot_player(info, 1);
	if (mlx_is_key_down(info->mlx, MLX_KEY_LEFT))
		rot_player(info, -1);
	if (mlx_is_key_down(info->mlx, MLX_KEY_W))
		move(info, 1);
	if (mlx_is_key_down(info->mlx, MLX_KEY_S))
		move(info, 2);
	if (mlx_is_key_down(info->mlx, MLX_KEY_A))
		move(info, 3);
	if (mlx_is_key_down(info->mlx, MLX_KEY_D))
		move(info, 4);
	draw(info);
}
