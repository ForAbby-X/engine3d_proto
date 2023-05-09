/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 05:21:11 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/05/08 05:58:47 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine3d.h"

static inline int	_sign(int a, int b)
{
	if (a < b)
		return (1);
	return (-1);
}

void	ft_put_line(t_engine *eng, t_v2i pos1, t_v2i pos2, t_color col)
{
	t_v2i const	diff = {abs(pos2[0] - pos1[0]), -abs(pos2[1] - pos1[1])};
	t_v2i		spos;
	int			err;
	int			e2;

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

void	ft_put_tri(t_engine *eng, t_v2i pos1, t_v2i pos2, t_v2i pos3, t_color col)
{
	ft_put_line(eng, pos1, pos2, col);
	ft_put_line(eng, pos2, pos3, col);
	ft_put_line(eng, pos3, pos1, col);
}
