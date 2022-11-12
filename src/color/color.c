/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:45:30 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/12 14:45:27 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

int				speed_to_mlxcode(uint8_t speed);
static t_rgb	hsv2rgb(t_hsv hsv);
int				encode_rgb(t_rgb code);

int	speed_to_mlxcode(uint8_t speed)
{
	t_hsv	hsv;
	t_rgb	rgb;

	hsv = (t_hsv){0, 255, speed};
	rgb = hsv2rgb(hsv);
	return (encode_rgb(rgb));
}

static t_rgb	hsv2rgb(t_hsv hsv)
{
	uint8_t	region;
	uint8_t	remainder;
	uint8_t	p;
	uint8_t	q;
	uint8_t	t;

	if (hsv.s == 0)
		return ((t_rgb){hsv.v, hsv.v, hsv.v});
	region = hsv.h / 43;
	remainder = (hsv.h - (region * 43)) * 6;
	p = (hsv.v * (255 - hsv.s)) >> 8;
	q = (hsv.v * (255 - ((hsv.s * remainder) >> 8))) >> 8;
	t = (hsv.v * (255 - ((hsv.s * (255 - remainder)) >> 8))) >> 8;
	if (region == 0)
		return ((t_rgb){hsv.v, t, p});
	else if (region == 1)
		return ((t_rgb){q, hsv.v, p});
	else if (region == 2)
		return ((t_rgb){p, hsv.v, t});
	else if (region == 3)
		return ((t_rgb){p, q, hsv.v});
	else if (region == 4)
		return ((t_rgb){t, p, hsv.v});
	else
		return ((t_rgb){hsv.v, p, q});
}

int	encode_rgb(t_rgb code)
{
	return (code.r << 16 | code.g << 8 | code.b);
}
