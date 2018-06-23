/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_ways.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 18:10:20 by ade-verd          #+#    #+#             */
/*   Updated: 2018/06/20 19:11:20 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_room	**ft_create_tabrooms(t_map **map, t_room **copy)
{
	t_room	**tab;
	int		rooms;

	rooms = (*map)->rooms;
	if (!(tab = (t_room**)malloc(sizeof(t_room*) * (rooms + 1))))
		ft_error(map, (char*)__FUNCTION__, EFAULT);
	while (rooms >= 0)
	{
		tab[rooms] = copy && copy[rooms] ? copy[rooms] : 0;
		rooms--;
	}
	return (tab);
}

t_way			*ft_add_way(t_map **map)
{
	t_way	*new;
	t_way	*last;

	if (!(new = (t_way*)malloc(sizeof(t_way))))
		ft_error(map, (char*)__FUNCTION__, EFAULT);
	new->par = 0;
	new->select = 0;
	new->next = NULL;
	last = (*map)->ways;
	while (last && last->next)
		last = last->next;
	if (last)
	{
		new->rooms = ft_create_tabrooms(map, last->rooms);
		new->prev = last;
		last->next = new;
	}
	else
	{
		new->rooms = ft_create_tabrooms(map, 0);
		new->prev = NULL;
		(*map)->ways = new;
	}
	return (new);
}

void			ft_fill_lastway(t_map **map, t_room *current, int index)
{
	t_way	*last;
	int		i;

	last = (*map)->ways;
	while (last && last->next)
		last = last->next;
	if (last && last->rooms)
	{
		last->rooms[index] = current;
		i = 0;
		while (last->rooms[i++])
			last->par = i - 1;
	}
	else
		ft_error(map, (char*)__FUNCTION__, EFAULT);
}

void			ft_swap_ways(t_way *a, t_way *b)
{
	int		tmp_par;
	int		tmp_select;
	t_room	**tmp_rooms;

	tmp_par = a->par;
	tmp_select = a->select;
	tmp_rooms = a->rooms;
	a->par = b->par;
	a->select = b->select;
	a->rooms = b->rooms;
	b->par = tmp_par;
	b->select = tmp_select;
	b->rooms = tmp_rooms;
}

void			ft_ways_del(t_way **ways)
{
	t_way	*cpy;

	while (*ways)
	{
		cpy = *ways;
		*ways = (*ways)->next;
		if (cpy->rooms)
			ft_memdel((void**)&cpy->rooms);
		ft_memdel((void**)&cpy);
	}
}
