/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:31:08 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/10 18:55:45 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#include "draw.h"
#include "util.h"
#include <mlx.h>

int			handle_loop(t_env *env);
static void	init_image(t_env *env);

int	handle_loop(t_env *env)
{
	init_image(env);
	draw(env);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	return (0);
}

static void	init_image(t_env *env)
{
	env->img_ptr = mlx_new_image(env->mlx_ptr, FRACTAL_WIDTH, FRACTAL_HEIGHT);
	env->img_data = mlx_get_data_addr(env->img_ptr, &env->bits_per_pixel, \
										&env->bytes_per_line, &env->endian);
	env->bytes_per_pixel = env->bits_per_pixel / 8;
}
