/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:27:33 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/07 11:34:43 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <X11/keysym.h>
#include <stdlib.h>
#include "hook.h"

static void	handle_esc(t_window *window);

int	handle_key(int keysym, t_window *window)
{
	if (keysym == XK_Escape)
		handle_esc(window);
	return (0);
}

static void	handle_esc(t_window *window)
{
	mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	mlx_destroy_display(window->mlx_ptr);
	exit(0);
}
