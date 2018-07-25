/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 14:50:41 by ade-verd          #+#    #+#             */
/*   Updated: 2018/07/25 16:15:46 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H
# define GRAPH_H

# define GRAPH_SH		"./scripts/create_graph.sh"
# define DOTFILE		"./.graph/graph.dot"
# define PNGFILE		"./.graph/mygraph.png"

/*
** General
*/
# define GV_CONCENTRATE	"concentrate=true"
# define GV_BGCOLOR		"bgcolor=transparent"
# define GV_RANKDIR		"rankdir=LR"
# define GV_SPLINES		"splines=curved"
# define GV_EDGE		"edge [color=grey]"
# define GV_NODE		"node [color=skyblue, fillcolor=azure, style=filled]"

/*
** Nodes START & END
*/
# define LABEL_START	"label=START"
# define LABEL_END		"label=END"
# define GV_STARTEND	"shape=box, fillcolor=skyblue, style=filled, peripheries=2"


/*
** Nodes on the way
*/
# define GV_NODE_WAY	"fillcolor=skyblue, style=filled, fontcolor=white"

#endif
