/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:27:33 by ade-verd          #+#    #+#             */
/*   Updated: 2018/06/19 19:27:33 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	read_ways(t_map *map)
{
	t_way	*ways;
	int		i;

	ways = map->ways;
	while (ways && ways->rooms)
	{
		i = 0;
		ways->rooms[i] ? ft_printf("Par: %d\t", ways->par) : none();
		while (ways->rooms[i])
		{
			ft_putstr(ways->rooms[i]->id);
			ways->rooms[i + 1] ? ft_putchar('-') : none();
			i++;
		}
		ways->rooms[0] ? ft_putchar('\n') : none();
		ways = ways->next;
	}
}

void	read_last_way(t_map *map)
{
	t_way	*ways;
	int		i;

	ways = map->ways;
	while (ways && ways->next)
		ways = ways->next;
	if (!ways->rooms)
		return ;
	i = 0;
	while (i < map->rooms)
	{
		if (!ways->rooms[i])
			ft_putstr(" ");
		else
			ft_putstr(ways->rooms[i]->id);
		ways->rooms[i + 1] ? ft_putchar('-') : none();
		i++;
	}
	ft_putchar('\n');
}

void	read_links(t_room *current)
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

void	read_rooms(t_map *map)
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
		read_links(cpy);
		if (cpy->next)
			ft_printf("%s___\n", F_NO);
		cpy = cpy->next;
	}
}

int		main(int ac, char **av)
{
	t_map	*map;

	ft_map_init(&map);
	if (ac > 1)
		ft_read_args(&map, ac, av);
	ft_deal_options(&map);
	ft_read_fd(&map);
	//read_rooms(map);
	find_issues(map, map->head, 0);
	ft_printf("%s___\n", F_NO);
	read_ways(map);
	ft_deal_options_quit(&map);
	ft_map_del(&map);
	return (EXIT_SUCCESS);
}
