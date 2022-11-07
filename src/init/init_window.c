/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:46:32 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/07 11:18:23 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

void	init_window(t_window *window)
{
	window->mlx_ptr = mlx_init();
	if (window->mlx_ptr == NULL)
	{
		perror("failed to init mlx");
		exit(1);
	}
	window->win_ptr = mlx_new_window(window->mlx_ptr, WINDOW_WIDTH, \
									WINDOW_HEIGHT, WINDOW_TITLE);
	if (window->win_ptr == NULL)
	{
		free(window->mlx_ptr);
		perror("failed to create new window");
		exit(1);
	}
}
