/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:55:22 by alde-fre          #+#    #+#             */
/*   Updated: 2023/05/02 17:36:20 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	ft_eng_destroy(t_engine *eng)
{
	mlx_loop_end(eng->mlx);
	ft_destroy_sprite(eng, eng->screen);
	ft_destroy_sprite(eng, eng->ascii_spr);
	mlx_destroy_window(eng->mlx, eng->win);
	mlx_destroy_display(eng->mlx);
	free(eng->mlx);
	free(eng);
	ft_putstr_fd("Destroying engine...\n", 1);
}

int	ft_eng_play(t_engine *eng, void *data,
		int (*on_repeat)(t_engine *eng, void *data, double elapsed_time))
{
	ft_putstr_fd("Starting engine...\n", 1);
	if (on_repeat)
	{
		eng->data = data;
		eng->on_repeat = on_repeat;
		clock_gettime(CLOCK_MONOTONIC, &eng->time_e);
		mlx_loop(eng->mlx);
	}
	return (1);
}
