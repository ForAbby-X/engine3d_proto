/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:13:54 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/05/09 19:33:46 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine3d.h"

static inline void	__init_game(t_game *game)
{
	size_t		i;
	t_polygon	*poly;

	game->length = 2048;
	i = 0;
	while (i < game->length)
	{
		poly = game->polygons + i;
		i++;
	}
}

static inline int	__loop(t_engine *eng, void *data, double et)
{
	t_game *const	game = data;
	t_polygon		*poly;
	size_t			i;

	(void)et;
	ft_clear(eng, (t_color){0x1E1E1E});
	i = 0;
	while (i < game->length)
	{
		poly = game->polygons + i;
		// ft_put_tri(eng,
		// 	(t_v2i){poly->pos[0][0], poly->pos[0][1]},
		// 	(t_v2i){poly->pos[1][0], poly->pos[1][1]},
		// 	(t_v2i){poly->pos[2][0], poly->pos[2][1]}, poly->col);
		i++;
	}
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
