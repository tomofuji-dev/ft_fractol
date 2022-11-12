/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:59:15 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/12 14:27:55 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	pixel_put(t_env *env, int x, int y, int color)
{
	char	*dst;

	dst = env->img_data + (y * env->bytes_per_line + x * env->bytes_per_pixel);
	*(int *)dst = color;
}

t_complex	window_to_complex(int x, int y, double zoom)
{
	return ((t_complex){
		.r = ((double)x - (double)FRACTAL_WIDTH / 2) * zoom,
		.i = ((double)FRACTAL_HEIGHT / 2 - (double)y) * zoom
	});
}
