/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_rot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:45:49 by alde-fre          #+#    #+#             */
/*   Updated: 2023/05/11 20:53:17 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "vec3.h"

t_v3f	v3f_rot(t_v3f vec, float phi, float theta)
{
	(void)theta;
	return ((t_v3f){
		vec[x] * cosf(theta) - vec[y] * sinf(theta),
		vec[x] * sinf(theta) + vec[y] * cosf(phi) - vec[z] * sinf(phi),
		vec[y] * sinf(phi) + vec[z] * cosf(phi)});
}

t_v3f	v3f_rotx(t_v3f vec, float phi)
{
	return ((t_v3f){
		vec[x],
		vec[y] * cosf(phi) - vec[z] * sinf(phi),
		vec[y] * sinf(phi) + vec[z] * cosf(phi)});
}

t_v3f	v3f_roty(t_v3f vec, float phi)
{
	return ((t_v3f){
		vec[x] * cosf(phi) - vec[z] * sinf(phi),
		vec[y],
		vec[x] * sinf(phi) + vec[z] * cosf(phi)});
}

t_v3f	v3f_rotz(t_v3f vec, float phi)
{
	return ((t_v3f){
		vec[x] * cosf(phi) - vec[y] * sinf(phi),
		vec[x] * sinf(phi) + vec[y] * cosf(phi),
		vec[z]});
}
