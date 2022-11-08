/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:46:32 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/08 20:07:26 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

void	init_env(t_env *env)
{
	env->mlx_ptr = mlx_init();
	if (env->mlx_ptr == NULL)
	{
		perror("failed to init mlx");
		exit(1);
	}
	env->win_ptr = mlx_new_window(env->mlx_ptr, WINDOW_WIDTH, \
									WINDOW_HEIGHT, WINDOW_TITLE);
	if (env->win_ptr == NULL)
	{
		mlx_destroy_display(env->mlx_ptr);
		perror("failed to create new window");
		exit(1);
	}
	env->img_ptr = mlx_new_image(env->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (env->img_ptr == NULL)
	{
		mlx_destroy_window(env->mlx_ptr, env->win_ptr);
		mlx_destroy_display(env->mlx_ptr);
		perror("failed to create new window");
		exit(1);
	}
	env->img_data = mlx_get_data_addr(env->img_ptr, &env->bits_per_pixel, \
										&env->bytes_per_line, &env->endian);
	env->bytes_per_pixel = env->bits_per_pixel / 8;
}
