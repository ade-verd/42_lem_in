/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:27:33 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/17 16:57:29 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(int ac, char **av)
{
	int		i;

	i = 1;
	if (ac > 1)
	{
		while (av[i] && i < ac)
		{
			ft_printf("%s\n", av[i]);
			i++;
		}
	}
	else
		ft_printf("no arg\n");
	return (EXIT_SUCCESS);
}
