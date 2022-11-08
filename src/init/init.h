/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: t.fuji <t.fuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:33:08 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/08 10:33:40 by t.fuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "fractol.h"

typedef enum e_argerror
{
	ARGC_ERROR,
	ARGC_JULIA_ERROR,
	ARGC_MANDELBROT_ERROR,
	ARG_FRACTAL_TYPE_ERROR,
	ARG_JULIA_PARAMS_ERROR
}

void	init_env(t_env *env);

#endif