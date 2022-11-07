/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:27:33 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/07 09:45:09 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <X11/keysym.h>
#include "hook.h"

static void	handle_esc(t_data *data);

int	handle_key(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		handle_esc(data);
	return (0);
}

static void	handle_esc(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
}
