/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 11:37:19 by ade-verd          #+#    #+#             */
/*   Updated: 2018/06/29 16:42:27 by ade-verd         ###   ########.fr       */
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
# define CMD_START	1
# define CMD_END	2

struct			s_link;

typedef struct	s_room
{
	char			*id;
	int				x;
	int				y;
	int				ant_id;
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
	int				select;
	t_room			**rooms;
	struct s_way	*next;
	struct s_way	*prev;

}				t_way;

typedef struct	s_line
{
	char			*line;
	struct s_line	*next;
}				t_line;

typedef struct	s_map
{
	int			ants;
	int			lap;
	int			lapsmove;
	int			nb_start;
	int			nb_end;
	int			rooms;
	t_room		*head;
	t_room		*start;
	t_room		*end;
	t_way		*ways;
	t_line		*lines;
	int			command;
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
void			ft_swap_ways(t_way *a, t_way *b);

/*
** Lines
*/
t_line			*ft_add_line(t_map *map, char *line);
void			ft_lines_del(t_line	*lines);
void			ft_read_lines(t_map *map);

/*
** Reader
*/
void			ft_read_args(t_map **map, int ac, char **av);
void			ft_read_fd(t_map **map);
int				ft_isroom(char *str, int *loop);
int				ft_islink(t_map **map, char *str, int *loop);
int				ft_isant(char *str, int *loop);
void			ft_check_validity(t_map *map);

/*
** Commands
*/
void			ft_command(t_map *map, t_room *new0);

/*
** Issues
*/
int				ft_count_issues(t_map *map);
int				find_issues(t_map *map, t_room *current, int hit);
void			ft_sort_issues(t_map *map);
void			ft_select_issues(t_map *map);

/*
** solve
*/
void			solve(t_map *map);
void			move_ant(t_map *map, t_room *from, t_room *to);
void			move_all(t_map *map);

/*
** Display
*/
void			ft_read_rooms(t_map *map);
void			ft_read_links(t_room *current);
void			ft_read_last_way(t_map *map);
void			ft_read_ways(t_map *map);

/*
** Errors
*/
void			ft_error(t_map **map, char *precision, int errnum);
void			ft_error_sdl(t_map **map, char *precision, char *precision2);
int				none(void);

#endif
