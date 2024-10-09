/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotkobay <kotkobay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:02:35 by kotkobay          #+#    #+#             */
/*   Updated: 2023/10/04 13:45:37 by kotkobay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*s != 0)
	{
		count++;
		s++;
	}
	return (count);
}
/*
#include <stdio.h>

int	main(void)
{
	const char	*str;
	int			length;

	str = "Hello, World!";
	length = ft_strlen(str);
	printf("文字列の長さは %d です。\n", length);
	return (0);
} */
