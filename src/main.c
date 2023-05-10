/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:13:54 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/05/10 06:29:36 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine3d.h"

static inline void	__init_game(t_game *game)
{
	ft_putstr_fd("[3D] initialisation...\n", 2);
	game->length = sizeof(g_test_mesh) / sizeof(t_polygon);
	memcpy(game->polygons, &g_test_mesh[0], sizeof(g_test_mesh));
	game->cam_rot = (t_v2f){0.0f, 0.0f};
	game->cam_pos = (t_v3f){0.0f, 0.0f, 0.0f};
	ft_putstr_fd("[3D] done !\n", 2);
}

static inline t_v2i	__proj(t_v3f vec, t_v3f cam_pos, t_v2f cam_rot)
{
	t_v3f	proj;
	t_v2f	res;

	proj = v3f_rot2(vec - cam_pos, -cam_rot[0], -cam_rot[1]);
	if (proj[y] <= 0.00001f)
		return ((t_v2i){480, 320});
	res = (t_v2f){proj[x], proj[z]} / proj[y] * 1000.0f;
	printf("depth:%f\n", res[y]);
	return ((t_v2i){480 + res[x], 320 + res[y]});
}

static inline t_tri	__full_proj(t_polygon poly, t_v3f cam_pos, t_v2f cam_rot)
{
	t_tri	tri;

	tri.pos[0] = __proj(poly.pos[0], cam_pos, cam_rot);
	tri.pos[1] = __proj(poly.pos[1], cam_pos, cam_rot);
	tri.pos[2] = __proj(poly.pos[2], cam_pos, cam_rot);
	return (tri);
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
		printf("tri_pos0[%d:%d]\n", tri.pos[0][x], tri.pos[0][y]);
		printf("tri_pos1[%d:%d]\n", tri.pos[0][x], tri.pos[0][y]);
		printf("tri_pos2[%d:%d]\n", tri.pos[0][x], tri.pos[0][y]);
		ft_put_tri(eng, tri, (t_color){0xFEFEFE});
		poly->pos[0] = v3f_rot2(poly->pos[0], 0.0f, et);
		poly->pos[1] = v3f_rot2(poly->pos[1], 0.0f, et);
		poly->pos[2] = v3f_rot2(poly->pos[2], 0.0f, et);
		i++;
	}
	if (eng->keys[XK_Up])
		game->cam_pos[y] += et * 5;
	if (eng->keys[XK_Down])
		game->cam_pos[y] -= et * 5;
	if (eng->keys[XK_Left])
		game->cam_rot[1] += et;
	if (eng->keys[XK_Right])
		game->cam_rot[1] -= et;
	printf("cam_pos[%f:%f:%f]{%f,%f}\n", game->cam_pos[x], game->cam_pos[y], game->cam_pos[z], game->cam_rot[0], game->cam_rot[1]);
	return (1);
}

int	main(void)
{
	t_engine	*eng;
	t_game		game;

	eng = ft_eng_create(240 * 4, 160 * 4, "3D Engine");
	if (eng)
	{
		__init_game(&game);
		ft_eng_play(eng, &game, &__loop);
		ft_eng_destroy(eng);
	}
	else
		ft_putstr_fd("[ERROR] Failed to launch engine.", 2);
	return (0);
}
