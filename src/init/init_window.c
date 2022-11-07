/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:46:32 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/07 11:43:36 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

void	init_env(t_env *env)
{
	env->mlx_ptr = mlx_init();
	if (env->mlx_ptr == NULL)
	{
		perror("failed to init mlx");
		exit(1);
	}
	env->win_ptr = mlx_new_window(env->mlx_ptr, WINDOW_WIDTH, \
									WINDOW_HEIGHT, WINDOW_TITLE);
	if (env->win_ptr == NULL)
	{
		free(env->mlx_ptr);
		perror("failed to create new window");
		exit(1);
	}
}
