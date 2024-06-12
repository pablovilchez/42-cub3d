/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:51:36 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/11 09:53:43 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_error(int error_num, char *custom_message)
{
	if (custom_message)
		ft_putstr_fd(custom_message, 2);
	else
		ft_putstr_fd(get_error_message(error_num), 2);
}
