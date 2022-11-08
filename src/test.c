/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: t.fuji <t.fuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:07:56 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/08 11:22:18 by t.fuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#include "init.h"

int	main(int argc, char *argv[])
{
	t_arg	arg;
	t_env	env;

	arg = arg_parse(argc, argv);
	init_env(&env);
	env.arg = &arg;
	setup_hook(&env);
}
