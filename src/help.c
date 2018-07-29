/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 12:43:44 by ade-verd          #+#    #+#             */
/*   Updated: 2018/07/29 18:39:01 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** void	ft_help(void)
** lem-in help and flags debug
*/

void	ft_help(void)
{
	int			i;
	const t_hlp	tab[] = {{ "Usage", "./lem-in [-hdrwWscmgG] < map.txt" },
		{ "——————", "" },
		{ "-hH", "[Help] displays this help" },
		{ "-dD", "[Debug] displays flags details in binary" },
		{ "-rR", "[Rooms] displays rooms details" },
		{ "-w ", "[selected_Ways] displays selected ways" },
		{ "-W ", "[all_Ways] displays every possible ways" },
		{ "-sS", "[Status] displays ants status at the end" },
		{ "-cC", "[no_Context] do not display context" },
		{ "-mM", "[Mute] only status is displayed" },
		{ "-g", "[Graph_TB] creates a graph with left to right orientation" },
		{ "-G", "[Graph_LR] creates a graph with top to bottom orientation" },
		{ 0, 0}};

	i = 0;
	while (tab[i].option)
	{
		ft_printf("%s\t%s\n", tab[i].option, tab[i].details);
		i++;
	}
}

/*
** void	ft_flag_debug(t_map *map)
** Prints flags activated with binary display
*/

void	ft_flag_debug(t_map *map)
{
	ft_help();
	ft_putchar('\n');
	ft_printf("      \tGgMCSWwRDH\n");
	ft_printf("flags:\t%010b\n", map->flags);
	if ((map->flags & FLAG_HELP) != 0)
		ft_error(&map, "NO", 0);
	else
		ft_putchar('\n');
}

/*
** void	ft_deal_help_debug(t_map *map)
** Manage ft_help and ft_flag_debug (main function)
*/

void	ft_deal_help_debug(t_map *map)
{
	if ((map->flags & FLAG_DEBUG_FLAGS) != 0)
		ft_flag_debug(map);
	else if ((map->flags & FLAG_HELP) != 0)
	{
		ft_help();
		ft_error(&map, "NO", 0);
	}
}
