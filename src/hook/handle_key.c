/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:27:33 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/07 11:42:22 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <X11/keysym.h>
#include <stdlib.h>
#include "hook.h"

static void	handle_esc(t_env *env);

int	handle_key(int keysym, t_env *env)
{
	if (keysym == XK_Escape)
		handle_esc(env);
	return (0);
}

static void	handle_esc(t_env *env)
{
	mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	mlx_destroy_display(env->mlx_ptr);
	exit(0);
}
