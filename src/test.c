/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: t.fuji <t.fuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:07:56 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/09 09:40:18 by t.fuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#include "init.h"

int	main(int argc, char *argv[])
{
	t_env		env;
	t_fractal	f;

	init(&env, &f, arg_parse(argc, argv));
	setup_hook(&env);
}
