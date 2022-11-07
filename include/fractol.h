/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:28:41 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/07 11:46:52 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stddef.h>
# include <stdbool.h>
# include <stdint.h>

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 430
# define WINDOW_TITLE "fractol"

typedef enum e_fractal {
	MANDELBROT,
	JULIA
}	t_fractal;

typedef struct s_env {
	t_fractal	fractal;
	void		*mlx_ptr;
	void		*win_ptr;
	char		*data;
	int			bits_per_pixel;
	int			bytes_per_pixel;
	int			bytes_per_line;
	int			endian;
}	t_env;

#endif