/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_del_space.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:11:23 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/11 20:05:22 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_del_space(char *str)
{
	char	*temp;
	int		len;

	temp = str;
	len = ft_strlen(temp);
	while (len > 0 && (temp[len - 1] == ' ' || temp[len - 1] == '\n'))
		len--;
	while (*temp == ' ')
		temp++;
	return (ft_substr(temp, 0, len - (temp - str)));
}
