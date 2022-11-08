/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: t.fuji <t.fuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:33:08 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/08 11:21:25 by t.fuji           ###   ########.fr       */
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
}	t_argerror;

void	init_env(t_env *env);
t_arg	arg_parse(int argc, char *argv[]);

#endif