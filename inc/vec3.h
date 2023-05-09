/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:45:49 by alde-fre          #+#    #+#             */
/*   Updated: 2023/05/09 19:08:14 by alde-fre         ###   ########.fr       */
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

// algorithm
// FLOAT
t_v2f	ft_v3fr(float r, float d);
float	ft_v3fmag(t_v2f a);
float	ft_v3fdot(t_v2f a, t_v2f b);
float	ft_v3fcross(t_v2f a, t_v2f b);
t_v2f	ft_v3fnorm(t_v2f a, float n);

#endif
