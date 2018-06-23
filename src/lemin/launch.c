/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 14:28:17 by ade-verd          #+#    #+#             */
/*   Updated: 2018/06/23 12:44:19 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		launch_ants(t_map *map)
{
	t_way	*ways;

	ways = map->ways;
	while (ways && ways->rooms && map->nb_start)
	{
		if (ways->rooms[0] && ways->select)
		{
			if (ways->rooms[1] && ways->rooms[1]->ant_id == 0)
			{
				ways->rooms[0]->ant_id = map->ants - map->nb_start + 1;
				move_ant(map, ways->rooms[0], ways->rooms[1]);
				map->nb_start--;
			}
		}
		ways = ways->next;
	}
}

void		solve(t_map *map)
{
	map->nb_start = map->ants;
	while (map->nb_end < map->ants)
	{
		map->lap++;
		map->lapsmove = 0;
		move_all(map);
		if (map->nb_start)
			launch_ants(map);
		ft_putchar('\n');
	}
}
