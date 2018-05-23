/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:30:07 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/23 19:37:59 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_map_init(t_map **map)
{
	if (!(*map = (t_map*)malloc(sizeof(t_map))))
		ft_error(map, (char*)__FUNCTION__, EFAULT);
	(*map)->ants = 0;
	(*map)->head = NULL;
	(*map)->curr = NULL;
	(*map)->start = NULL;
	(*map)->end = NULL;
}

void	ft_create_room(t_map **map, t_room **current, char **room_info)
{
	t_room	*new;

	if (!(new = (t_room*)malloc(sizeof(t_room))))
		ft_error(map, (char*)__FUNCTION__, EFAULT);
	new->id = ft_strdup(room_info[0]);
	new->x = ft_atoi(room_info[1]);
	new->y = ft_atoi(room_info[2]);
	new->ants = 0;
	new->link = NULL;
	new->next = NULL;
	if (*current)
	{
		new->prev = *current;
		(*current)->next = new;
	}
	else
	{
		new->prev = NULL;
		*current = new;
	}
	ft_freetab_strsplit(room_info);
}

void	ft_add_room(t_map **map, char **room_info)
{
	t_room	**cpy;

	cpy = &(*map)->head;
	while (*cpy && (*cpy)->next)
		*cpy = (*cpy)->next;
	ft_create_room(map, cpy, room_info);
}

void	ft_rooms_del(t_room **rooms)
{
	t_room	*cpy;

	while (*rooms)
	{
		cpy = *rooms;
		*rooms = (*rooms)->next;
		ft_memdel((void**)&cpy);
	}
}

void	ft_map_del(t_map **map)
{
	ft_rooms_del(&(*map)->head);
	if (*map)
		ft_memdel((void**)map);
}