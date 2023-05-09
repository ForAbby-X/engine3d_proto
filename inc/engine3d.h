/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 05:21:46 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/05/09 20:47:48 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE3D_H
# define ENGINE3D_H

# include "engine.h"
# include "vec3.h"

typedef struct s_polygon
{
	t_v3f	pos[3];
}	t_polygon;

typedef struct s_game
{
	t_polygon	polygons[2048];
	t_length	length;
}	t_game;

static const t_polygon	g_cube_mesh[]
	= {
{(t_v3f){0.0f, 0.0f, 0.0f}, (t_v3f){0.0f, 1.0f, 0.0f}, (t_v3f){1.0f, 0.0f, 0.0f}},
{(t_v3f){0.0f, 0.0f, 0.0f}, (t_v3f){1.0f, 0.0f, 0.0f}, (t_v3f){0.0f, 0.0f, 1.0f}},
{(t_v3f){0.0f, 1.0f, 0.0f}, (t_v3f){1.0f, 0.0f, 0.0f}, (t_v3f){0.0f, 0.0f, 1.0f}}
};

void	ft_put_line(t_engine *eng, t_v2i pos1, t_v2i pos2, t_color col);
void	ft_put_tri(t_engine *eng, t_v2i pos1, t_v2i pos2, t_v2i pos3, t_color col);

#endif
