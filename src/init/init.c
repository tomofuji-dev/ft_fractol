/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:46:32 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/13 10:04:25 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "libft.h"
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void				init(t_env *env, t_fractal *f, t_arg arg);
static void			init_env(t_env *env);
static void			init_fractal(t_fractal *f, t_arg arg);
static t_complex	julia_c(int julia_degree);

void	init(t_env *env, t_fractal *f, t_arg arg)
{
	init_env(env);
	init_fractal(f, arg);
	env->f = f;
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
	f->zoom = 0.01;
	f->max_loop = 50;
	if (f->type == JULIA)
		f->julia_c = julia_c(arg.julia_degree);
}

static t_complex	julia_c(int julia_degree)
{
	return ((t_complex){
		.r = JULIA_R * cos(M_PI * (double)julia_degree / 180),
		.i = JULIA_R * sin(M_PI * (double)julia_degree / 180)
	});
}
