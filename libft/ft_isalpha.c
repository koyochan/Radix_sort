/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotkobay <kotkobay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 08:46:43 by kotkobay          #+#    #+#             */
/*   Updated: 2023/09/22 07:34:25 by kotkobay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
		return (1);
	else
		return (0);
}

/* #include <ctype.h>
#include <stdio.h>

int	main(void)
{
	char	ch;

	ch = 'A';
	if (isalpha(ch))
	{
		printf("%c is an alphabet character\n", ch);
	}
	else
	{
		printf("%c is not an alphabet character\n", ch);
	}
	return (0);
} */
