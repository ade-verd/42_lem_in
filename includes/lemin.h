/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 11:37:19 by ade-verd          #+#    #+#             */
/*   Updated: 2018/06/19 16:30:19 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <limits.h>
# include "ft_printf.h"

# define REVERSE	-1

struct			s_link;

typedef struct	s_room
{
	char			*id;
	int				x;
	int				y;
	int				ants;
	int				way;
	struct s_link	*link;
	struct s_room	*next;
	struct s_room	*prev;
}				t_room;

typedef struct	s_link
{
	t_room			*from;
	t_room			*to;
	struct s_link	*next;
	struct s_link	*prev;
}				t_link;

typedef struct	s_way
{
	int				par;
	t_room			**rooms;
	struct s_way	*next;
	struct s_way	*prev;

}				t_way;

typedef struct	s_map
{
	int			ants;
	int			rooms;
	t_room		*head;
	t_room		*start;
	t_room		*end;
	t_way		*ways;
	int			option_f;
	int			fd;
	char		*path;
}				t_map;

/*
** Options
*/
void			ft_deal_options(t_map **map);
void			ft_deal_options_quit(t_map **map);

/*
** Map
*/
void			ft_map_init(t_map **map);
void			ft_map_del(t_map **map);

/*
** Rooms
*/
t_room			*ft_add_room(t_map **map, char **room_info);
void			ft_rooms_del(t_room **rooms);
t_room			*get_room_ptr(t_map **map, char *id);

/*
** Links
*/
void			ft_add_link(t_map **map, char **link_info);
void			ft_links_del(t_link **links);

/*
** Ways
*/
t_way			*ft_add_way(t_map **map);
void			ft_ways_del(t_way **ways);
void			ft_fill_lastway(t_map **map, t_room *current, int index);
void			read_ways(t_map *map);
void			read_last_way(t_map *map);

/*
** Reader
*/
void			ft_read_args(t_map **map, int ac, char **av);
void			ft_read_fd(t_map **map);
int				ft_isroom(char *str, int *loop);
int				ft_islink(t_map **map, char *str, int *loop);
int				find_issues(t_map *map, t_room *current, int hit);

/*
** Commands
*/
void			command_start(t_map **map, int fd, int *ret, int *loop);
void			command_end(t_map **map, int fd, int *ret, int *loop);

/*
** Errors
*/
void			ft_error(t_map **map, char *precision, int errnum);
void			ft_error_sdl(t_map **map, char *precision, char *precision2);
int				none(void);

#endif
