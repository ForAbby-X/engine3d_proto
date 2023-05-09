/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:47:13 by alde-fre          #+#    #+#             */
/*   Updated: 2023/05/09 19:05:42 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_v3f	ft_v3fr(float phi, float theta, float d)
{
	return ((t_v3f){
		sinf(theta) * cosf(phi),
		sinf(theta) * sinf(phi),
		cosf(theta)} * d);
}

float	ft_v3fmag(t_v3f a)
{
	a *= a;
	return (sqrtf(a[0] + a[1] + a[2]));
}

float	ft_v3fdot(t_v3f a, t_v3f b)
{
	a *= b;
	return (a[0] + a[1]);
}

float	ft_v3fcross(t_v3f a, t_v3f b)
{
	return ((t_v3f){
	a[z],
	0.0f,
	0.0f
	});
}

t_v3f	ft_v3fnorm(t_v3f a, float n)
{
	float	mag;

	mag = ft_v3fmag(a);
	if (mag == 0.0f)
		return ((t_v3f){0.0f, 0.0f, 0.0f});
	return (a / mag * n);
}
