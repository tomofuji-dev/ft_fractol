/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: t.fuji <t.fuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:23:44 by t.fuji            #+#    #+#             */
/*   Updated: 2022/11/08 11:25:47 by t.fuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

int		ft_isdigit(int c);
int		ft_isspace(int c);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putendl_fd(char *s, int fd);
int		ft_strcmp(const char *s1, const char *s2);

#endif