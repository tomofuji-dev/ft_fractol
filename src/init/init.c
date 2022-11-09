/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: t.fuji <t.fuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:46:32 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/09 10:36:00 by t.fuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "libft.h"
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

static void	init_env(t_env *env);
static void	init_fractal(t_fractal *f, t_arg arg);

void	init(t_env *env, t_fractal *f, t_arg arg)
{
	init_env(env);
	init_fractal(f, arg);
}

static void	init_env(t_env *env)
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
	env->img_ptr = mlx_new_image(env->mlx_ptr, FRACTAL_WIDTH, FRACTAL_HEIGHT);
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

static void	init_fractal(t_fractal *f, t_arg arg)
{
	ft_memset(f, 0, sizeof(t_fractal));
	f->type = arg.fractal_type;
	f->zoom_level = 0;
	f->center = (t_coord){0, 0};
	f->max_loop = 100;
	f->julia_degree = arg.julia_degree;
}
