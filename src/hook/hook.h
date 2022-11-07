/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:33:08 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/07 11:23:07 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

# include "fractol.h"

void	setup_hook(t_window *window);

int		handle_key(int keysym, t_window *window);
int		handle_loop(t_window *window);

#endif