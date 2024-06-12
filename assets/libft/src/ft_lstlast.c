/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:03:36 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/08 12:48:55 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	if (!lst)
		return (0);
	temp = (t_list *)lst;
	while (temp->next)
		temp = temp->next;
	return (temp);
}
