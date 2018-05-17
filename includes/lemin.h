/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 11:37:19 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/17 18:46:50 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include "ft_printf.h"

typedef struct	s_link;

typedef struct	s_room
{
	char			*id;
	int				x;
	int				y;
	int				ants;
	struct s_link	*link;
	struct s_room	next;
	struct s_room	prev;
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
	t_room		*start;
	t_room		*end;
}				t_map;

#endif
