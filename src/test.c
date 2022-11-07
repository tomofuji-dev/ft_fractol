/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:07:56 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/07 11:44:26 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#include "init.h"

int	main(void)
{
	t_env	env;

	// argparse
	// init_env(env)
	init_env(&env);
	setup_hook(&env);
}
