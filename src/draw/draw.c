/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:36:47 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/12 15:11:49 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "util.h"
#include "color.h"

void		draw(t_env *env);
static void	update_speed(t_fractal *f);
static void	normalize_speed(t_fractal *f);
static void	fractal_to_img(t_env *env, t_fractal *f);

void	draw(t_env *env)
{
	update_speed(env->f);
	fractal_to_img(env, env->f);
}

static void	update_speed(t_fractal *f)
{
	int	x;
	int	y;

	y = 0;
	while (y < FRACTAL_HEIGHT)
	{
		x = 0;
		while (x < FRACTAL_WIDTH)
		{
			if (f->type == JULIA)
				f->speed[y][x] = speed_julia(f, (t_coord){x, y});
			else if (f->type == MANDELBROT)
				f->speed[y][x] = speed_mandelbrot(f, (t_coord){x, y});
			x++;
		}
		y++;
	}
	normalize_speed(f);
}

static void	normalize_speed(t_fractal *f)
{
	int		x;
	int		y;
	double	raw_speed;

	y = 0;
	while (y < FRACTAL_HEIGHT)
	{
		x = 0;
		while (x < FRACTAL_WIDTH)
		{
			raw_speed = f->speed[y][x];
			f->speed[y][x] = raw_speed / f->max_loop * 255;
			x++;
		}
		y++;
	}
}

static void	fractal_to_img(t_env *env, t_fractal *f)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			color = speed_to_mlxcode(f->speed[y][x]);
			pixel_put(env, x, y, color);
			x++;
		}
		y++;
	}
}
