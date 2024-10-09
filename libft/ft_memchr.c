/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotkobay <kotkobay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:22:49 by kotkobay          #+#    #+#             */
/*   Updated: 2023/10/08 12:39:41 by kotkobay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	c1;

	c1 = (unsigned char)c;
	s1 = (unsigned char *)s;
	while (n)
	{
		if (*s1 == c1)
		{
			return ((void *)s1);
		}
		s1++;
		n--;
	}
	return (0);
}
