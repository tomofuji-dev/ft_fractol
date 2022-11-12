/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:49:37 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/12 15:32:46 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#include <X11/keysym.h>
#include <stdio.h>

int	handle_mouse(int button, int x, int y, t_env *e)
{
	(void) x;
	(void) y;

	if (button == MOUSE_WHEEL_UP)
	{
		if (e->f->max_loop > 10)
		{
			e->f->zoom /= 0.9;
			e->f->max_loop -= 2;
		}
	}
	else if (button == MOUSE_WHEEL_DOWN)
	{
		if (e->f->zoom > 0.00001)
		{
			e->f->zoom *= 0.9;
			e->f->max_loop += 2;
		}
	}
	return (0);
}
