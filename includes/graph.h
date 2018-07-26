/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 14:50:41 by ade-verd          #+#    #+#             */
/*   Updated: 2018/07/26 17:21:49 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H
# define GRAPH_H

# define GRAPH_SH		"./scripts/create_graph.sh"
# define DOTFILE		"./.graph/graph.dot"
# define OUTPUTFILE		"./.graph/mygraph"

/*
** General
*/
# define GV_TITLE		"42 - lem-in\\nade-verd's graph\\n "
# define GV_GRAPH 		"graph [label=\""GV_TITLE"\", labelloc=t]"
# define GV_CONCENTRATE	"concentrate=true"
# define GV_BGCOLOR		"bgcolor=transparent"
# define GV_RANKDIR_LR	"rankdir=LR"
# define GV_EDGE		"edge [color=grey]"
# define GV_NODE		"node [color=skyblue, fillcolor=azure, style=filled]"

/*
** Nodes START & END
*/
# define LABEL_START	"START"
# define LABEL_END		"END"
# define GV_STARTEND_C	"fillcolor=skyblue, style=filled"
# define GV_STARTEND	"shape=box, peripheries=2, "GV_STARTEND_C

/*
** Nodes on the way
*/
# define GV_NODE_WAY	"fillcolor=skyblue, style=filled, fontcolor=white"

/*
** Edges on the way
*/
# define GV_EDGE_WAY	"[color=skyblue, penwidth=2.5]"

#endif
