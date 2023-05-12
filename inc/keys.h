/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 23:15:34 by alde-fre          #+#    #+#             */
/*   Updated: 2023/05/12 23:16:04 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifdef KEYS_WASD
#  define MOVE_UP XK_w
#  define MOVE_DOWN XK_s
#  define MOVE_LEFT XK_a
#  define MOVE_RIGHT XK_d
#  define LEAN_LEFT XK_q
#  define LEAN_RIGHT XK_e
# endif

# ifndef KEYS_WASD
#  define MOVE_UP XK_z
#  define MOVE_DOWN XK_s
#  define MOVE_LEFT XK_q
#  define MOVE_RIGHT XK_d
#  define LEAN_LEFT XK_a
#  define LEAN_RIGHT XK_e
# endif
