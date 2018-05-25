/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 11:37:19 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/25 18:41:06 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <limits.h>
# include "ft_printf.h"

struct			s_link;

typedef struct	s_room
{
	char			*id;
	int				x;
	int				y;
	int				ants;
	struct s_link	*link;
	struct s_room	*next;
	struct s_room	*prev;
}				t_room;

typedef struct	s_link
{
	t_room		*from;
	t_room		*to;
	t_room		*next;
	t_room		*prev;
}				t_link;

typedef struct	s_map
{
	int			ants;
	t_room		*head;
	t_room		*curr;
	t_room		*start;
	t_room		*end;
}				t_map;


void			ft_reader(t_map **map);

/*
** Map, rooms and links
*/
void			ft_map_init(t_map **map);
void			ft_map_del(t_map **map);
t_room			*ft_add_room(t_map **map, char **room_info);
void			ft_rooms_del(t_room **rooms);

/*
** Commands
*/
void			command_start(t_map **map, int fd, int *ret, int *loop);
void			command_end(t_map **map, int fd, int *ret, int *loop);

void			ft_error(t_map **map, char *precision, int errnum);
void			ft_error_sdl(t_map **map, char *precision, char *precision2);
int				none(void);
#endif
