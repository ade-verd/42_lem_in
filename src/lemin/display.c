/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 18:29:03 by ade-verd          #+#    #+#             */
/*   Updated: 2018/07/23 12:14:07 by ade-verd         ###   ########.fr       */
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
}

void	ft_read_links(t_room *current)
{
	t_link	*link;

	link = current->link;
	link ? ft_printf("links:\t") : ft_printf("links:\t(null)");
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
		ft_printf("id:\t%s\n", cpy->id);
		ft_printf("x:\t%d\n", cpy->x);
		ft_printf("y:\t%d\n", cpy->y);
		ft_read_links(cpy);
		if (cpy->next)
			ft_printf("%s___\n", F_NO);
		cpy = cpy->next;
	}
	ft_putstr(F_NO);
}

void	ft_display_context(t_map *map)
{
	if ((map->flags | FLAG_M) == 1 || (map->flags | FLAG_C) == 1)
		return ;
	ft_read_lines(map);
	if ((map->flags | FLAG_R) == 1)
		ft_read_rooms(map);
	if ((map->flags | FLAG_W) == 1 && (map->flags | FLAG_WW) == 0)
		ft_read_selected_ways(map);
	else if ((map->flags | FLAG_WW) == 1)
		ft_read_all_ways(map);
}
