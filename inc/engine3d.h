/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 05:21:46 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/05/08 15:35:12 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE3D_H
# define ENGINE3D_H

#include "engine.h"

typedef struct s_polygon
{
	t_v2f	pos[3];
	t_color	col;
}	t_polygon;

typedef struct s_game
{
	t_polygon	polygons[2048];
	t_length	length;
}	t_game;

void	ft_put_line(t_engine *eng, t_v2i pos1, t_v2i pos2, t_color col);
void	ft_put_tri(t_engine *eng, t_v2i pos1, t_v2i pos2, t_v2i pos3, t_color col);

#endif
