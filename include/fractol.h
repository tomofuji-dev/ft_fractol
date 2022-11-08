/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:28:41 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/08 20:55:32 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stddef.h>
# include <stdbool.h>
# include <stdint.h>

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 400
# define WINDOW_TITLE "fractol"

typedef enum e_fractal {
	JULIA,
	MANDELBROT,
}	t_fractal;

typedef struct s_arg {
	t_fractal	fractal;
	int			julia_param_a;
	int			julia_param_b;
}	t_arg;

typedef struct s_env {
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_data;
	int		bits_per_pixel;
	int		bytes_per_pixel;
	int		bytes_per_line;
	int		endian;
}	t_env;

struct s_fractal {
	t_fractal		fractal_type;

	unsigned int	zoom_level;
	t_dpoint		center;
	unsigned int	max_loop;
	int				speeds[400][400];

	unsigned int	julia_degree;
};

#endif