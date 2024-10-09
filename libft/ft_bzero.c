/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotkobay <kotkobay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 05:11:04 by kotkobay          #+#    #+#             */
/*   Updated: 2024/04/27 05:11:04 by kotkobay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, int n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
	{
		*ptr++ = 0;
	}
}

/* #include <stdio.h>
#include <strings.h>

int	main(void)
{
	char	buffer[10];

	buffer[10] = "123456789";
	printf("buffer: %s\n", buffer);
	bzero(buffer, 0);
	printf("buffer: %s\n", buffer);
	strcpy(buffer, "123456789");
	ft_bzero(buffer, 0);
	printf("buffer: %s\n", buffer);
	return (0);
} */
