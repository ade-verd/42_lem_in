/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_rooms.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 18:36:13 by ade-verd          #+#    #+#             */
/*   Updated: 2018/06/25 12:40:44 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room	*get_room_ptr(t_map **map, char *id)
{
	t_room	*cpy;

	cpy = (*map)->head;
	while (cpy)
	{
		if (ft_strcmp(cpy->id, id) == 0)
			return (cpy);
		cpy = cpy->next;
	}
	return (NULL);
}

t_room	*ft_create_room(t_map **map, t_room **current, char **room_info)
{
	t_room	*new;

	if (!(new = (t_room*)malloc(sizeof(t_room))))
		ft_error(map, (char*)__FUNCTION__, EFAULT);
	new->id = ft_strdup(room_info[0]);
	new->x = ft_atoi(room_info[1]);
	new->y = ft_atoi(room_info[2]);
	new->ant_id = 0;
	new->way = -1;
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
		(*map)->head = new;
	}
	(*map)->rooms++;
	ft_freetab_strsplit(room_info);
	return (new);
}

t_room	*ft_add_room(t_map **map, char **room_info)
{
	t_room	*cpy;
	t_room	*new;

	if ((*map)->ant <= 0)
		ft_error(map, "No ant", 0);
	cpy = (*map)->head;
	while (cpy && cpy->next)
		cpy = cpy->next;
	new = ft_create_room(map, &cpy, room_info);
	if ((*map)->command)
		ft_command(*map, new);
	return (new);
}

void	ft_rooms_del(t_room **rooms)
{
	t_room	*cpy;

	while (*rooms)
	{
		cpy = *rooms;
		ft_links_del(&cpy->link);
		ft_strdel(&cpy->id);
		*rooms = (*rooms)->next;
		ft_memdel((void**)&cpy);
	}
}
