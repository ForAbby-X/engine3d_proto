/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:45:49 by alde-fre          #+#    #+#             */
/*   Updated: 2023/05/10 03:38:39 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

# include "vec2.h"

enum e_z{
	z = 2
};

typedef float			t_v3f __attribute__((vector_size (16)));
typedef unsigned int	t_v3u __attribute__((vector_size (16)));
typedef int				t_v3i __attribute__((vector_size (16)));

t_v3f	v3f_rot2(t_v3f vec, float phi, float theta);
float	v3f_mag(t_v3f a);
float	v3f_dot(t_v3f a, t_v3f b);
t_v3f	v3f_cross(t_v3f a, t_v3f b);
t_v3f	v3f_norm(t_v3f a, float n);

#endif
