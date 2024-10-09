/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotkobay <kotkobay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:46:32 by kotkobay          #+#    #+#             */
/*   Updated: 2023/10/04 14:35:37 by kotkobay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (src == NULL && dst == NULL)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (d > s)
	{
		while (len--)
		{
			d[len] = s[len];
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}

/* int	main(void)
{
	char	str1[50];
	char	str2[50];
	char	str3[50];
	char	str4[50];

	str1[50] = "Hello World!";
	str2[50] = "Hello World!";
	str3[50] = "HelloHello";
	str4[50] = "HelloHello";
	// Case 1: Source and destination do not overlap
	printf("Before memmove: %s\n", str1);
	memmove(str1 + 6, str1 + 0, 5);
	printf("After memmove: %s\n", str1);
	printf("Before ft_memmove: %s\n", str2);
	ft_memmove(str2 + 6, str2 + 0, 5);
	printf("After ft_memmove: %s\n", str2);
	printf("Before memmove: %s\n", str3);
	memmove(str3 + 5, str3, 5);
	printf("After memmove: %s\n", str3);
	printf("Before ft_memmove: %s\n", str4);
	ft_memmove(str4 + 5, str4, 5);
	printf("After ft_memmove: %s\n", str4);
	return (0);
}
	*/