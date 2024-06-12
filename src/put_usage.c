/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_usage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:53:29 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/11 09:57:42 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*ft_remove_first_and_last_line(char *str)
{
	char	*start;
	char	*end;
	int		len;

	if (!str)
		return (NULL);
	start = ft_strchr(str, '*');
	if (!start)
		return (NULL);
	start++;
	end = ft_strrchr(str, '*');
	if (!end)
		return (NULL);
	len = end - start;
	return (ft_substr(start, 0, len));
}

static char	*ft_read_all(int fd)
{
	char	*res;
	char	*temp;
	char	*line;
	char	*processed_res;

	res = ft_calloc(1, sizeof(char));
	if (!res)
		return (put_error(E_MEMORY, 0), NULL);
	line = get_next_line(fd, NULL);
	while (line)
	{
		temp = ft_strjoin(res, line);
		free(res);
		free(line);
		res = temp;
		line = get_next_line(fd, NULL);
	}
	processed_res = ft_remove_first_and_last_line(res);
	free(res);
	return (processed_res);
}

void	put_usage(void)
{
	char	*res;
	int		fd;

	fd = open("assets/to_read_files/usage.h", O_RDONLY);
	if (fd < 0)
		put_error(E_INVALID_FILE, 0);
	res = ft_read_all(fd);
	printf("%s", res);
	free(res);
	close(fd);
}
