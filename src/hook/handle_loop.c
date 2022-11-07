/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:31:08 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/07 11:28:58 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#include <mlx.h>

#define RED_PIXEL 0xFF0000

int	handle_loop(t_window *window)
{
	mlx_pixel_put(window->mlx_ptr, window->win_ptr, \
					WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, RED_PIXEL);
	return (0);
}
