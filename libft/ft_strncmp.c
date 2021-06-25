/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 01:26:35 by kyuki             #+#    #+#             */
/*   Updated: 2021/06/13 14:50:34 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = -1;
	if (n == 0)
		return (0);
	while (++i < n && s1[i] && s1[i] == s2[i])
		;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
