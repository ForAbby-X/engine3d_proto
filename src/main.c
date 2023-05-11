/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:13:54 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/05/11 23:04:58 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine3d.h"

static inline void	__init_mesh(t_game *game)
{
	t_v2i		pos;

	pos[y] = 0;
	while (pos[y] < 10)
	{
		pos[x] = 0;
		while (pos[x] < 10)
		{
			game->polygons[pos[x] * 10 + pos[y]] = (t_polygon){
				(t_v3f){pos[x] + ft_rand(- 0.7f, 0.3f), pos[y] + ft_rand(- 0.3f, 0.7f), 0.0f},
				(t_v3f){pos[x] + ft_rand(- 0.2f, 0.2f), pos[y] + ft_rand(- 0.2f, 0.2f), ft_rand(-0.5f, -2.0f)},
				(t_v3f){pos[x] + ft_rand(- 0.3f, 0.7f), pos[y] + ft_rand(- 0.7f, 0.3f), 0.0f}
			};
			pos[x]++;
		}
		pos[y]++;
	}
	game->length = 100;
}

static inline void	__init_game(t_game *game, t_engine *eng)
{
	ft_putstr_fd("[3D] initialisation...\n", 2);
	__init_mesh(game);
	ft_memcpy(game->polygons + game->length, g_cub_mesh, sizeof(g_cub_mesh));
	game->length += sizeof(g_cub_mesh) / sizeof(t_polygon);
	ft_memcpy(game->polygons + game->length, g_pyramid_mesh, sizeof(g_pyramid_mesh));
	game->length += sizeof(g_pyramid_mesh) / sizeof(t_polygon);
	game->cam_rot = (t_v3f){0.0f, 0.0f, 0.0f};
	game->cam_pos = (t_v3f){0.0f, -20.0f, 0.0f};
	ft_putstr_fd("[3D] done !\n", 2);
	game->eng = eng;
	mlx_mouse_move(eng->mlx, eng->win, 480, 320);
}

static inline t_v2i	__proj(t_v3f vec, t_v3f cam_pos, t_v3f cam_rot)
{
	t_v3f	proj;
	t_v2f	res;

	proj = v3f_rotz(vec - cam_pos, -cam_rot[y]);
	proj = v3f_rotx(proj, -cam_rot[x]);
	proj = v3f_roty(proj, -cam_rot[z]);
	if (proj[y] <= 0.001f)
		return ((t_v2i){INT32_MIN, INT32_MIN});
	res = (t_v2f){proj[x], proj[z]} / proj[y] * 1000.0f;
	return ((t_v2i){480 + res[x], 320 + res[y]});
}

static inline t_tri	__full_proj(t_polygon poly, t_v3f cam_pos, t_v3f cam_rot)
{
	return ((t_tri){
		__proj(poly.pos[0], cam_pos, cam_rot),
		__proj(poly.pos[1], cam_pos, cam_rot),
		__proj(poly.pos[2], cam_pos, cam_rot)});
}

static inline void	__control(t_engine *eng, t_game *game, float et)
{
	t_v3f const	dir = {-sinf(game->cam_rot[1]), cosf(game->cam_rot[1]), 0.0f};
	t_v3f const	off = {cosf(game->cam_rot[1]), sinf(game->cam_rot[1]), 0.0f};

	if (eng->keys[XK_w])
		game->cam_pos += dir * 20.0f * et;
	if (eng->keys[XK_s])
		game->cam_pos -= dir * 20.0f * et;
	if (eng->keys[XK_d])
		game->cam_pos += off * 20.0f * et;
	if (eng->keys[XK_a])
		game->cam_pos -= off * 20.0f * et;
	if (eng->keys[XK_space])
		game->cam_pos[z] -= 20.0f * et;
	if (eng->keys[XK_Shift_L])
		game->cam_pos[z] += 20.0f * et;
	if (eng->keys[XK_Left])
		game->cam_rot[y] += et;
	if (eng->keys[XK_Right])
		game->cam_rot[y] -= et;
	if (eng->keys[XK_Up])
		game->cam_rot[x] -= et;
	if (eng->keys[XK_Down])
		game->cam_rot[x] += et;
	if (eng->keys[XK_q])
		game->cam_rot[z] = -0.25f;
	else if (eng->keys[XK_e])
		game->cam_rot[z] = 0.25f;
	else
		game->cam_rot[z] = 0.0f;
	//printf("cam_pos[%f:%f:%f]{%f,%f}\n", game->cam_pos[x], game->cam_pos[y], game->cam_pos[z], game->cam_rot[0], game->cam_rot[1]);
}

static inline int	__loop(t_engine *eng, void *data, double et)
{
	t_game *const	game = data;
	t_polygon		*poly;
	t_tri			tri;
	size_t			i;

	ft_clear(eng, (t_color){0x1E1E1E});
	i = 0;
	while (i < game->length)
	{
		poly = game->polygons + i;
		tri = __full_proj(*poly, game->cam_pos, game->cam_rot);
		if (tri.pos[0][x] > INT32_MIN
			&& tri.pos[1][x] > INT32_MIN
			&& tri.pos[2][x] > INT32_MIN)
			ft_put_tri(eng, tri, (t_color){0xFEFEFE});
		i++;
	}
	__control(eng, game, et);
	game->cam_rot[y] -= ((float)eng->mouse_x - 480) / 500.0f;
	game->cam_rot[x] += ((float)eng->mouse_y - 320) / 500.0f;
	mlx_mouse_move(eng->mlx, eng->win, 480, 320);
	return (1);
}

int	main(void)
{
	t_engine	*eng;
	t_game		game;

	eng = ft_eng_create(240 * 4, 160 * 4, "3D Engine");
	if (eng)
	{
		__init_game(&game, eng);
		ft_eng_play(eng, &game, &__loop);
		ft_eng_destroy(eng);
	}
	else
		ft_putstr_fd("[ERROR] Failed to launch engine.", 2);
	return (0);
}
