/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: t.fuji <t.fuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:28:41 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/08 11:16:34 by t.fuji           ###   ########.fr       */
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
	JULIA,
	MANDELBROT,
}	t_fractal;

typedef struct s_arg {
	t_fractal	fractal;
	int			julia_param_a;
	int			julia_param_b;
}	t_arg;

typedef struct s_env {
	t_arg	*arg;
	void	*mlx_ptr;
	void	*win_ptr;
	char	*data;
	int		bits_per_pixel;
	int		bytes_per_pixel;
	int		bytes_per_line;
	int		endian;
}	t_env;

#endif