/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:39:01 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/10/07 15:39:12 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strncpy(char *dest, char *src, int n)
{	
	int	i;

	i = 0;
	while (i < n)
	{
		*dest = *src;
		dest++;
		i++;
		if (*src != '\0')
		{
			src++;
		}
	}
}
