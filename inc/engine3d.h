/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 05:21:46 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/05/11 00:23:08 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE3D_H
# define ENGINE3D_H

# include "engine.h"
# include "vec3.h"

typedef struct s_tri
{
	t_v2i	pos[3];
}	t_tri;

typedef struct s_polygon
{
	t_v3f	pos[3];
}	t_polygon;

typedef struct s_game
{
	t_polygon	polygons[2048];
	t_length	length;
	t_v2f		cam_rot;
	t_v3f		cam_pos;
}	t_game;

static const t_polygon	g_cub_mesh[]
	= {
{(t_v3f){-5.0f, -5.0f, -5.0f}, (t_v3f){-5.0f, -5.0f, 5.0f}, (t_v3f){5.0f, -5.0f, -5.0f}},
{(t_v3f){5.0f, -5.0f, 5.0f}, (t_v3f){-5.0f, -5.0f, 5.0f}, (t_v3f){5.0f, -5.0f, -5.0f}},
{(t_v3f){5.0f, -5.0f, -5.0f}, (t_v3f){5.0f, 5.0f, -5.0f}, (t_v3f){5.0f, -5.0f, 5.0f}},
{(t_v3f){5.0f, 5.0f, 5.0f}, (t_v3f){5.0f, 5.0f, -5.0f}, (t_v3f){5.0f, -5.0f, 5.0f}},
{(t_v3f){5.0f, 5.0f, 5.0f}, (t_v3f){5.0f, 5.0f, -5.0f}, (t_v3f){-5.0f, 5.0f, -5.0f}},
{(t_v3f){-5.0f, 5.0f, 5.0f}, (t_v3f){5.0f, 5.0f, 5.0f}, (t_v3f){-5.0f, 5.0f, -5.0f}},
{(t_v3f){-5.0f, -5.0f, 5.0f}, (t_v3f){-5.0f, 5.0f, 5.0f}, (t_v3f){-5.0f, -5.0f, -5.0f}},
{(t_v3f){-5.0f, -5.0f, -5.0f}, (t_v3f){-5.0f, 5.0f, 5.0f}, (t_v3f){-5.0f, 5.0f, -5.0f}},
};

static const t_polygon	g_pyramid_mesh[]
	= {
{(t_v3f){-5.0f, -5.0f, 0.0f}, (t_v3f){0.0f, 0.0f, -10.0f}, (t_v3f){5.0f, -5.0f, 0.0f}},
{(t_v3f){-5.0f, 5.0f, 0.0f}, (t_v3f){0.0f, 0.0f, -10.0f}, (t_v3f){5.0f, 5.0f, 0.0f}},
{(t_v3f){-5.0f, -5.0f, 0.0f}, (t_v3f){0.0f, 0.0f, -10.0f}, (t_v3f){-5.0f, 5.0f, 0.0f}},
{(t_v3f){5.0f, -5.0f, 0.0f}, (t_v3f){0.0f, 0.0f, -10.0f}, (t_v3f){5.0f, 5.0f, 0.0f}},
};

void	ft_put_line(t_engine *eng, t_v2i pos1, t_v2i pos2, t_color col);
void	ft_put_tri(t_engine *eng, t_tri tri, t_color col);

#endif
