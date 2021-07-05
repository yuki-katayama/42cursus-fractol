/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:40:32 by kyuki             #+#    #+#             */
/*   Updated: 2021/07/05 12:40:33 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <ctype.h>
# include <stdlib.h>

char			*ft_strncpy(char *dest, char *src, unsigned int n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlen(const char *s);
int				ft_malloc_p(void **p, size_t len);

#endif
