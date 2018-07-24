/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 18:29:03 by ade-verd          #+#    #+#             */
/*   Updated: 2018/07/24 14:54:41 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_read_all_ways(t_map *map)
{
	t_way	*ways;
	int		i;

	ways = map->ways;
	while (ways && ways->rooms)
	{
		i = 0;
		ways->select == 0 ? ft_putstr(F_BLACK) : none();
		ways->rooms[i] ? ft_printf("Par: %d\t", ways->par) : none();
		while (ways->rooms[i])
		{
			ft_putstr(ways->rooms[i]->id);
			ways->rooms[i + 1] ? ft_putchar('-') : none();
			i++;
		}
		ways->rooms[0] ? ft_printf("%s\n", F_NO) : ft_putstr(F_NO);
		ways = ways->next;
	}
	ft_putchar('\n');
}

void	ft_read_selected_ways(t_map *map)
{
	t_way	*ways;
	int		i;

	ways = map->ways;
	while (ways && ways->rooms && ways->select)
	{
		i = 0;
		ways->rooms[i] ? ft_printf("Par: %d\t", ways->par) : none();
		while (ways->rooms[i])
		{
			ft_putstr(ways->rooms[i]->id);
			ways->rooms[i + 1] ? ft_putchar('-') : none();
			i++;
		}
		ways->rooms[0] ? ft_printf("%s\n", F_NO) : ft_putstr(F_NO);
		ways = ways->next;
	}
	ft_putchar('\n');
}

void	ft_read_links(t_room *current)
{
	t_link	*link;

	link = current->link;
	link ? ft_printf("  links:\t") : ft_printf("  links:\t(null)");
	while (link)
	{
		ft_printf("%s", link->to->id);
		if (link->next)
			ft_putstr(", ");	
		link = link->next;
	}
	ft_putchar('\n');
}

void	ft_read_rooms(t_map *map)
{
	t_room	*cpy;

	cpy = map->head;
	while (cpy)
	{
		if (cpy == map->start)
			ft_putstr(F_GREEN);
		if (cpy == map->end)
			ft_putstr(F_RED);
		ft_printf("☐ id (x, y):\t%s (%d, %d)\n", cpy->id, cpy->x, cpy->y);
		ft_read_links(cpy);
		ft_putstr(F_NO);
		cpy = cpy->next;
	}
	ft_putchar('\n');
}

void	ft_display_context(t_map *map)
{
	if (map->flags & FLAG_MUTE)
		return ;
	if (!(map->flags & FLAG_CONTEXT_NO))
		ft_read_lines(map);
	if (map->flags & FLAG_ROOMS)
		ft_read_rooms(map);
	if ((map->flags & FLAG_WAYS_SEL) && !(map->flags & FLAG_WAYS_ALL))
		ft_read_selected_ways(map);
	else if (map->flags & FLAG_WAYS_ALL)
		ft_read_all_ways(map);
}
