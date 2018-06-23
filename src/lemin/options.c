/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 12:43:44 by ade-verd          #+#    #+#             */
/*   Updated: 2018/06/21 13:57:18 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** void	ft_option_f_open(t_heaps **ab)
** Checks if -f is activated and if a *.txt file is specified. Then open *.txt
*/

static void	ft_option_f_open(t_map **map)
{
	if (!(*map)->path)
		ft_error(map, "-f: no [file].txt specified", 0);
	if ((*map)->option_f == 0 && (*map)->path)
		ft_error(map, "[file].txt detected. Please specify option: \"-f\"", 0);
	if (((*map)->fd = ft_open_fd((*map)->path, O_RDONLY, S_IRUSR)) == -1)
		ft_error(map, (char*)__FUNCTION__, 0);
}

void		ft_deal_options(t_map **map)
{
	if ((*map)->option_f != 0 || (*map)->path)
		ft_option_f_open(map);
}
void		ft_deal_options_quit(t_map **map)
{
	if ((*map)->fd > 2 && ft_close_fd((*map)->fd) == -1)
		ft_error(map, (char*)__FUNCTION__, 0);
}
