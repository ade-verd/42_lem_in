/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 11:55:32 by ade-verd          #+#    #+#             */
/*   Updated: 2018/07/29 17:39:13 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** int	ft_isinteger(char *str)
** Checks if str is a number and an integer
*/

static int	ft_isinteger(char *str)
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

/*
** int	ft_isant(char *str, int *loop)
** Checks ants validity
*/

int			ft_isant(char *str, int *loop)
{
	if (ft_isinteger(str))
		return (1);
	return (*loop = 0);
}

/*
** int	ft_isroom(char *str, int *loop)
** Checks validity of a room
*/

int			ft_isroom(char *str, int *loop)
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

/*
** int	ft_islink(t_map **map, char *str, int *loop)
** Checks validity of a link
*/

int			ft_islink(t_map **map, char *str, int *loop)
{
	char	**tab;

	tab = ft_strsplit(str, '-');
	if ((*map)->command)
		*loop = 0;
	if (ft_strcmp(tab[0], tab[1]) == 0)
		*loop = 0;
	if (!get_room_ptr(map, tab[0]) || !get_room_ptr(map, tab[1]))
		*loop = 0;
	ft_freetab_strsplit(tab);
	return (*loop);
}

/*
** void	ft_check_validity(t_map *map)
** Checks ants, rooms, start and end
*/

void		ft_check_validity(t_map *map)
{
	if (map->ants <= 0)
		ft_error(&map, "No ant", 0);
	if (!map->rooms)
		ft_error(&map, "No room", 0);
	if (!map->start)
		ft_error(&map, "No start", 0);
	if (!map->end)
		ft_error(&map, "No end", 0);
}
