/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 15:20:35 by ade-verd          #+#    #+#             */
/*   Updated: 2018/06/20 19:12:14 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	arecrossing(t_map *map, t_room **way_rooms, t_room *checkroom)
{
	int		i;

	i = 0;
	while (way_rooms[i])
	{
		if (way_rooms[i] != map->start && way_rooms[i] != map->end)
		{
			if (way_rooms[i] == checkroom)
				return(1);
		}
		i++;
	}
	return (0);
}

static int	iscompatible_with_selected(t_map *map, t_room **rooms)
{
	int		i;
	t_way	*ways;

	ways = map->ways;
	while (ways && ways->rooms)
	{
		i = 0;
		while (ways->select > 0 && rooms[i])
		{
			if (arecrossing(map, ways->rooms, rooms[i]))
				return (0);
			i++;
		}
		ways = ways->next;
	}
	return (1);
}

void		ft_select_issues(t_map *map)
{
	t_way	*ways;

	ways = map->ways;
	while (ways)
	{
		if (iscompatible_with_selected(map, ways->rooms))
			ways->select = 1;
		ways = ways->next;
	}
}
