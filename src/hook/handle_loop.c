/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:31:08 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/08 20:20:01 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#include "util.h"
#include <mlx.h>

#define RED_PIXEL 0xFF0000

int	handle_loop(t_env *env)
{
	pixel_put(env, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, RED_PIXEL);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	return (0);
}
