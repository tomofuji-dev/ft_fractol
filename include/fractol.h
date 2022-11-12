/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:28:41 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/12 14:51:51 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stddef.h>
# include <stdbool.h>
# include <stdint.h>

# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 1000
# define FRACTAL_WIDTH 1000
# define FRACTAL_HEIGHT 1000
# define WINDOW_TITLE "fractol"
# define JULIA_R 0.7885
# define MOUSE_WHEEL_UP 5
# define MOUSE_WHEEL_DOWN 4

typedef enum e_fractal_type {
	JULIA,
	MANDELBROT,
}	t_fractal_type;

typedef struct s_coord {
	int	x;
	int	y;
}	t_coord;

typedef struct s_complex {
	double	r;
	double	i;
}	t_complex;

typedef struct s_arg {
	t_fractal_type	fractal_type;
	int				julia_degree;
}	t_arg;

typedef struct s_fractal {
	t_fractal_type	type;

	double			zoom;
	unsigned int	max_loop;
	unsigned int	speed[FRACTAL_HEIGHT][FRACTAL_WIDTH];

	t_complex		julia_c;
}	t_fractal;

typedef struct s_env {
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*img_data;
	int			bits_per_pixel;
	int			bytes_per_pixel;
	int			bytes_per_line;
	int			endian;
	t_fractal	*f;
}	t_env;

#endif