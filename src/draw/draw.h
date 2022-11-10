/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:33:08 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/10 18:41:53 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "fractol.h"

void			draw(t_env *env);
unsigned int	speed_julia(t_fractal *f, t_coord coord);
unsigned int	speed_mandelbrot(t_fractal *f, t_coord coord);

#endif