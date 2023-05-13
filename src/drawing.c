/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 05:21:11 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/05/13 16:35:03 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine3d.h"

static inline int	_sign(int a, int b)
{
	if (a < b)
		return (1);
	return (-1);
}

static inline int	_is_out_of_bound(t_engine *eng, t_v2i pos)
{
	if (pos[x] < -(int)eng->win_x * 0.5f || pos[y] < -(int)eng->win_y * 0.5f
		|| pos[x] >= (int)eng->win_x * 1.5f || pos[y] >= (int)eng->win_y * 1.5f)
		return (1);
	return (0);
}

void	ft_put_line(t_engine *eng, t_v2i pos1, t_v2i pos2, t_color col)
{
	t_v2i const	diff = {abs(pos2[0] - pos1[0]), -abs(pos2[1] - pos1[1])};
	t_v2i		spos;
	int			err;
	int			e2;

	if (_is_out_of_bound(eng, pos1) || _is_out_of_bound(eng, pos2))
		return ;
	spos = (t_v2i){_sign(pos1[0], pos2[0]), _sign(pos1[1], pos2[1])};
	err = diff[0] + diff[1];
	while (1)
	{
		ft_draw(eng, pos1, col);
		if (pos1[0] == pos2[0] && pos1[1] == pos2[1])
			return ;
		e2 = 2 * err;
		if (e2 >= diff[1])
		{
			err += diff[1];
			pos1[0] += spos[0];
		}
		if (e2 <= diff[0])
		{
			err += diff[0];
			pos1[1] += spos[1];
		}
	}
}

void	ft_put_tri(t_engine *eng, t_tri tri, t_color col)
{
	ft_put_line(eng, tri.pos[0], tri.pos[1], col);
	ft_put_line(eng, tri.pos[1], tri.pos[2], col);
	ft_put_line(eng, tri.pos[2], tri.pos[0], col);
}
