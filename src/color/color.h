/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:07:43 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/12 14:38:33 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

#include <stdint.h>

typedef struct s_rgb {
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}	t_rgb;

typedef struct s_hsv {
	uint8_t	h;
	uint8_t	s;
	uint8_t	v;
}	t_hsv;

int	speed_to_mlxcode(uint8_t speed);
int	encode_rgb(t_rgb code);

#endif