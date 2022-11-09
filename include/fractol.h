/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: t.fuji <t.fuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:28:41 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/09 10:37:27 by t.fuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stddef.h>
# include <stdbool.h>
# include <stdint.h>

# define WINDOW_WIDTH 400
# define WINDOW_HEIGHT 400
# define FRACTAL_WIDTH 400
# define FRACTAL_HEIGHT 400
# define WINDOW_TITLE "fractol"

typedef enum e_fractal_type {
	JULIA,
	MANDELBROT,
}	t_fractal_type;

typedef struct s_coord {
	int	x;
	int	y;
}	t_coord;

typedef struct s_arg {
	t_fractal_type	fractal_type;
	int				julia_degree;
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

typedef struct s_fractal {
	t_fractal_type	type;

	unsigned int	zoom_level;
	t_coord			center;
	unsigned int	max_loop;
	int				speeds[FRACTAL_HEIGHT][FRACTAL_WIDTH];

	unsigned int	julia_degree;
}	t_fractal;

#endif