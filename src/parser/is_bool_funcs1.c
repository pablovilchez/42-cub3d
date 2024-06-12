/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_bool_funcs1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:03:08 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/30 11:59:05 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_acceptable_map_value(t_parser *p, char **m, int r, int c)
{
	if (is_valid_map_char(m[r][c]) || m[r][c] == '2')
	{
		if (m[r][c] == 'N' || m[r][c] == 'S'
			|| m[r][c] == 'W' || m[r][c] == 'E')
		{
			if (p->player_x == -1 && p->player_y == -1)
			{
				p->player_angle = get_player_direction(m[r][c]);
				p->player_x = r + 0.5;
				p->player_y = c + 0.5;
				m[r][c] = '0';
			}
			else
				return (put_error(0, "Error: more than 1 player\n"), false);
		}
		return (true);
	}
	return (put_error(0, "Error: Found unacceptable value\n"), false);
}

bool	is_texture_or_color(char *s, bool color_check_bool)
{
	if (color_check_bool && (s[0] == 'F' || s[0] == 'C'))
		return (1);
	else if ((s[0] == 'N' && s[1] == 'O')
		|| (s[0] == 'S' && s[1] == 'O')
		|| (s[0] == 'W' && s[1] == 'E')
		|| (s[0] == 'E' && s[1] == 'A'))
		return (1);
	return (0);
}

bool	is_all_spaces(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (false);
	while (str[i] != '\0')
	{
		if (!ft_isspace(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	is_valid_map_char(char c)
{
	if (c == '0'
		|| c == '1'
		|| c == 'N'
		|| c == 'S'
		|| c == 'W'
		|| c == 'E')
		return (true);
	return (false);
}

bool	is_enough_parser_oblig_data(t_parser *parser)
{
	if (parser->no_txt_loc == NULL
		|| parser->so_txt_loc == NULL
		|| parser->we_txt_loc == NULL
		|| parser->ea_txt_loc == NULL
		|| parser->f_color == -1
		|| parser->c_color == -1)
		return (false);
	return (true);
}
