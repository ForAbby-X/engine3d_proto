/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:47:13 by alde-fre          #+#    #+#             */
/*   Updated: 2023/05/10 17:06:58 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_v3f	v3f_rot2(t_v3f vec, float phi, float theta)
{
	(void)phi;
	return ((t_v3f){
		vec[x] * cosf(theta) - vec[y] * sinf(theta),
		vec[x] * sinf(theta) + vec[y] * cosf(theta),
		vec[z]});
}

t_v3f	v3f_rot3(t_v3f vec, float phi, float theta)
{
	(void)theta;
	return ((t_v3f){
		vec[x],
		vec[y] * cosf(phi) - vec[z] * sinf(phi),
		vec[y] * sinf(phi) + vec[z] * cosf(phi)});
}

float	v3f_mag(t_v3f a)
{
	a *= a;
	return (sqrtf(a[0] + a[1] + a[2]));
}

float	v3f_dot(t_v3f a, t_v3f b)
{
	a *= b;
	return (a[0] + a[1]);
}

t_v3f	v3f_cross(t_v3f a, t_v3f b)
{
	return ((t_v3f){
	a[y] * b[z] - a[z] * b[y],
	a[z] * b[x] - a[x] * b[z],
	a[x] * b[y] - a[y] * b[x]});
}

t_v3f	v3f_norm(t_v3f a, float n)
{
	float	mag;

	mag = v3f_mag(a);
	if (mag == 0.0f)
		return ((t_v3f){0.0f, 0.0f, 0.0f});
	return (a / mag * n);
}
