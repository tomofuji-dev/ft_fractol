/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: t.fuji <t.fuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:53:31 by t.fuji            #+#    #+#             */
/*   Updated: 2022/11/08 10:33:01 by t.fuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "init.h"

// ./fractol <fractol type> <julia_param_a> <julia_param_b>
t_arg	arg_parse(int argc, char *argv[])
{
	t_arg	*arg;

	if (argc < 2)
		return (arg_error(ARGC_ERROR));
	if (ft_strncmp(argv[1], "julia") == 0)
	{
		arg->fractal = JULIA;
		if (argc != 4)
			return (arg_error(ARGC_JULIA_ERROR));
		arg->julia_param_a = parse_int(argv[2]);
		arg->julia_param_b = parse_int(argv[3]);
		return (arg);
	}
	elif (ft_strncmp(argv[1], "mandelbrot") == 0)
	{
		if (argc != 2)
			return (arg_error(ARGC_MANDELBROT_ERROR));
		arg->fractal = MANDELBROT;
		return (arg);
	}
	else
		return (arg_error(ARG_FRACTAL_TYPE_ERROR));
}


