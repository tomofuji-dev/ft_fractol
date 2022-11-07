/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:35:53 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/07 11:17:22 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#include <mlx.h>
#include <X11/X.h>

void	setup_hook(t_window *window)
{
	mlx_loop_hook(window->mlx_ptr, &handle_loop, window);
	mlx_hook(window->win_ptr, KeyPress, KeyPressMask, &handle_key, window);
	mlx_loop(window->mlx_ptr);
}
