/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 14:34:57 by ade-verd          #+#    #+#             */
/*   Updated: 2018/07/29 18:35:20 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** static void	display_antmove(t_map *map, t_room *to)
** Displays moves
*/

static void	display_antmove(t_map *map, t_room *to)
{
	if (map->lapsmove > 1)
		ft_putchar(' ');
	ft_printf("L%d-%s", to->ant_id, to->id);
}

/*
** void		move_ant(t_map *map, t_room *from, t_room *to)
** Moves one ant
*/

void		move_ant(t_map *map, t_room *from, t_room *to)
{
	if (to == map->end)
		map->nb_end++;
	if (to->ant_id != 0)
		return ;
	to->ant_id = from->ant_id;
	from->ant_id = 0;
	map->lapsmove++;
	if (!(map->flags & FLAG_MUTE))
		display_antmove(map, to);
	if (to == map->end)
		to->ant_id = 0;
}

/*
** void		move_all(t_map *map)
** Moves every ants
*/

void		move_all(t_map *map)
{
	t_way	*ways;
	int		i;

	ways = map->ways;
	while (ways)
	{
		i = 0;
		while (ways->select && ways->rooms[i] && ways->rooms[i + 1])
			i++;
		while (i)
		{
			if (ways->rooms[i]->ant_id > 0 && ways->rooms[i + 1]->ant_id == 0)
				move_ant(map, ways->rooms[i], ways->rooms[i + 1]);
			i--;
		}
		ways = ways->next;
	}
}
