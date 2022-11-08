/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: t.fuji <t.fuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:53:31 by t.fuji            #+#    #+#             */
/*   Updated: 2022/11/08 11:55:12 by t.fuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "init.h"
#include <limits.h>
#include <stdlib.h>

void		arg_error(t_argerror error_code);
static int	parse_int(const char *nptr);
static int	process_digit(const char *nptr, long code);

t_arg	arg_parse(int argc, char *argv[])
{
	t_arg	arg;

	if (argc < 2)
		arg_error(ARGC_ERROR);
	ft_memset(&arg, 0, sizeof(t_arg));
	if (ft_strcmp(argv[1], "julia") == 0)
	{
		arg.fractal = JULIA;
		if (argc != 4)
			arg_error(ARGC_JULIA_ERROR);
		arg.julia_param_a = parse_int(argv[2]);
		arg.julia_param_b = parse_int(argv[3]);
	}
	else if (ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		if (argc != 2)
			arg_error(ARGC_MANDELBROT_ERROR);
		arg.fractal = MANDELBROT;
	}
	else
		arg_error(ARG_FRACTAL_TYPE_ERROR);
	return (arg);
}

void	arg_error(t_argerror error_code)
{
	if (error_code == ARGC_ERROR)
		ft_putendl_fd("ARGC_ERROR:\t\
number of params should be 1(mandelbrot) or 3(julia).", 1);
	else if (error_code == ARGC_JULIA_ERROR)
		ft_putendl_fd("ARGC_ERROR:\t\
number of params should be 3 in drawing julia.", 1);
	else if (error_code == ARGC_MANDELBROT_ERROR)
		ft_putendl_fd("ARGC_ERROR:\t\
number of params should be 1 in drawing mandelbrot.", 1);
	else if (error_code == ARG_FRACTAL_TYPE_ERROR)
		ft_putendl_fd("ARG_FRACTAL_TYPE_ERROR:\t\
fractal type should be \"julia\" or \"mandelbrot\".", 1);
	else if (error_code == ARG_JULIA_PARAMS_ERROR)
		ft_putendl_fd("ARG_JULIA_PARAMS_ERROR:\t\
your julia params are not proper.", 1);
	ft_putendl_fd("\n\tUsage:\t./fractol <fractol type> \
<julia_param_a> <julia_param_b>", 1);
	exit(1);
}

static int	parse_int(const char *nptr)
{
	long	code;

	while (ft_isspace(*nptr))
		nptr++;
	code = 1;
	if (*nptr == '-')
	{
		code *= -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	if (!ft_isdigit(*nptr))
		arg_error(ARG_JULIA_PARAMS_ERROR);
	return (process_digit(nptr, code));
}

static int	process_digit(const char *nptr, long code)
{
	long	n;
	long	d;

	n = 0;
	while (ft_isdigit(*nptr))
	{
		d = *nptr++ - '0';
		if (code > 0)
		{
			if (n <= (INT_MAX - d) / 10)
				n = 10 * n + d;
			else
				arg_error(ARG_JULIA_PARAMS_ERROR);
		}
		else
		{
			if (n >= (INT_MIN + d) / 10)
				n = 10 * n - d;
			else
				arg_error(ARG_JULIA_PARAMS_ERROR);
		}
	}
	return ((int) n);
}
