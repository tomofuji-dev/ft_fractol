/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:31:08 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/07 11:42:34 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#include <mlx.h>

#define RED_PIXEL 0xFF0000

int	handle_loop(t_env *env)
{
	mlx_pixel_put(env->mlx_ptr, env->win_ptr, \
					WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, RED_PIXEL);
	return (0);
}
