/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unplanned_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:24:49 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/16 12:35:57 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	unplanned_exit(t_info *info, int error_code)
{
	general_free(info);
	if (error_code)
		put_error(error_code, 0);
	exit(EXIT_FAILURE);
}
