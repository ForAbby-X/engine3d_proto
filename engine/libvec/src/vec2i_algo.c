/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2i_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 07:59:14 by alde-fre          #+#    #+#             */
/*   Updated: 2022/12/23 18:46:53 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec2.h"

t_v2i	ft_v2irot(t_v2i a, float r)
{
	t_v2i	b;
	float	c;
	float	s;

	c = cosf(r);
	s = sinf(r);
	b[0] = a[0] * c - a[1] * s;
	b[1] = a[0] * s + a[1] * c;
	return (b);
}
