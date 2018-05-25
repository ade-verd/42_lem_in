/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:07:11 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/25 15:40:58 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** int	ft_isinteger(char *str)
** Checks if str is a number and an integer
*/

int		ft_isinteger(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (ft_atointmax(str) < INT_MIN || ft_atointmax(str) > INT_MAX)
		return (0);
	return (1);
}

int		ft_isroom(char *str, int *loop)
{
	char	**tab;

	tab = ft_strsplit(str, ' ');
	if (ft_strlen(tab[0]) == 0)
		*loop = 0;
	else if (tab[0][0] == 'L')
		*loop = 0;
	else if (!ft_isinteger(tab[1]) || !ft_isinteger(tab[2]))
		*loop = 0;
	ft_freetab_strsplit(tab);
	return (*loop);
}

void	ft_reader(t_map **map)
{
	int		ret;
	int		loop;
	char	*line;

	loop = 1;
	while (loop && (ret = get_next_line(0, &line)) > 0)
	{
		if (line[0] == '#')
		{
			//if (ft_strcmp(line, "##start") == 0)
				//do start
			//else if (ft_strcmp(line, "##end") == 0)
				//do end
			//else if (...)
				//comment
		}
		else if (ft_countwords(line, ' ') == 3 && ft_isroom(line, &loop))
			ft_add_room(map, ft_strsplit(line, ' '));
		ft_strdel(&line);
	}
	if (line)
		ft_strdel(&line);
	if (ret < 0)
		ft_error(map, "ft_reader: GNL Bad return", 0);
}