/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_lines.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 18:37:16 by ade-verd          #+#    #+#             */
/*   Updated: 2018/06/25 18:20:46 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_line	*ft_add_line(t_map *map, char *line)
{
	t_line	*new;
	t_line	*last;

	if (!(new = (t_line*)malloc(sizeof(t_line))))
		ft_error(&map, (char*)__FUNCTION__, EFAULT);
	new->next = NULL;
	new->line = line;
	last = map->lines;
	while (last && last->next)
		last = last->next;
	if (last)
		last->next = new;
	else
		map->lines = new;
	return (new);
}

void	ft_read_lines(t_map *map)
{
	t_line	*line;

	line = map->lines;
	while (line)
	{
		ft_printf("%s\n", line->line);
		line = line->next;
	}
	ft_putchar('\n');
}

void	ft_lines_del(t_line	*lines)
{
	t_line	*cpy;

	while (lines)
	{
		cpy = lines;
		lines = lines->next;
		ft_memdel((void**)&cpy);
	}
}
