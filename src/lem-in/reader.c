/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:07:11 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/29 11:35:11 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** int	ft_isinteger(char *str)
** Checks if str is a number and an integer
*/

void	read_rooms(t_map *map);

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

int		ft_islink(t_map **map, char *str, int *loop)
{
	char	**tab;

	tab = ft_strsplit(str, '-');
	if (!get_room_ptr(map, tab[0]) || !get_room_ptr(map, tab[1]))
		*loop = 0;
	ft_freetab_strsplit(tab);
	return (*loop);
}

void	ft_reader(t_map **map)
{
	int		fd;
	int		ret;
	int		loop;
	char	*line;

	fd = 0;
	loop = 1;
	while (loop && (ret = get_next_line(fd, &line)) > 0)
	{
		if (line[0] == '#')
		{
			if (ft_strcmp(line, "##start") == 0)
				command_start(map, fd, &ret, &loop);
			else if (ft_strcmp(line, "##end") == 0)
				command_end(map, fd, &ret, &loop);
			//else if (...)
				//comment
		}
		else if (ft_countwords(line, ' ') == 3 && ft_isroom(line, &loop))
			ft_add_room(map, ft_strsplit(line, ' '));
		else if (ft_countwords(line, '-') == 2 && ft_islink(map, line, &loop))
			ft_add_link(map, ft_strsplit(line, '-'));
		else
			loop = 0;
		ft_strdel(&line);
	}
	line ? ft_strdel(&line) : none();
	ret < 0 ? ft_error(map, "ft_reader: GNL Bad return", 0) : none();
}