/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:12:35 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/11 09:52:02 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	len;

	len = count * size;
	str = malloc(len);
	if (!str)
		return (put_error(E_MEMORY, 0), NULL);
	ft_bzero(str, len);
	return (str);
}
