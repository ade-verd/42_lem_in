/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issues.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 12:02:59 by ade-verd          #+#    #+#             */
/*   Updated: 2018/06/22 12:20:17 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	inway(t_map *map, t_room *room)
{
	t_way	*ways;
	int		i;

	i = 0;
	ways = map->ways;
	while (ways && ways->next)
		ways = ways->next;
	while (ways->rooms && ways->rooms[i])
	{
		if (ways->rooms[i] == room)
			return (1);
		i++;
	}
	return (0);
}

int			find_issues(t_map *map, t_room *current, int hit)
{
	t_link	*link;

	if (hit == 0)
		ft_add_way(&map);
	ft_fill_lastway(&map, current, hit);
	if (current == map->end)
	{
		ft_fill_lastway(&map, 0, hit + 1);
		ft_add_way(&map);
		return (hit);
	}
	link = current->link;
	while (link)
	{
		if (!inway(map, link->to))
		{
			if ((current->way = find_issues(map, link->to, hit + 1)))
				ft_fill_lastway(&map, current, hit);
		}
		link = link->next;
	}
	ft_fill_lastway(&map, 0, hit);
	return (0);
}

int			ft_count_issues(t_map *map)
{
	int		count;
	t_way	*ways;

	count = 0;
	ways = map->ways;
	while (ways && ways->rooms[0])
	{
		ways = ways->next;
		count++;
	}
	return (count);
}

void		ft_sort_issues(t_map *map)
{
	t_way	*ways;

	ways = map->ways;
	while (ways && ways->next)
	{
		if (ways->next->par < ways->par)
		{
			ft_swap_ways(ways, ways->next);
			ways = map->ways;
		}
		else
			ways = ways->next;
	}
}
