/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speed.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:26:36 by t.fuji            #+#    #+#             */
/*   Updated: 2022/11/10 13:01:56 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "util.h"
#include <math.h>
#define JULIA_R 0.7885

unsigned int		speed_julia(t_fractal *f, t_coord coord);
unsigned int		speed_mandelbrot(t_fractal *f, t_coord coord);
static t_complex	z_recurrence(t_complex z, t_complex c);

unsigned int	speed_julia(t_fractal *f, t_coord coord)
{
	t_complex		z;
	t_complex		c;
	unsigned int	i;

	z = window_to_complex(coord.x, coord.y, f->zoom);
	c = f->julia_c;
	i = 0;
	while (i < f->max_loop)
	{
		z = z_recurrence(z, c);
		if (isinf(z.r) || isinf(z.i))
			return (i);
		i++;
	}
	return (i);
}

unsigned int	speed_mandelbrot(t_fractal *f, t_coord coord)
{
	t_complex		z;
	t_complex		c;
	unsigned int	i;

	c = window_to_complex(coord.x, coord.y, f->zoom);
	z = (t_complex){0, 0};
	i = 0;
	while (i < f->max_loop)
	{
		z = z_recurrence(z, c);
		if (isinf(z.r) || isinf(z.i))
			return (i);
		i++;
	}
	return (i);
}

static t_complex	z_recurrence(t_complex z, t_complex c)
{
	return ((t_complex){
		.r = z.r * z.r - z.i * z.i + c.r,
		.i = z.r * z.i + z.i * z.r + c.i
	});
}
