/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotkobay <kotkobay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:45:45 by kotkobay          #+#    #+#             */
/*   Updated: 2023/10/02 12:12:12 by kotkobay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	p;
	unsigned char	*ptr;

	p = (unsigned char)c;
	ptr = (unsigned char *)b;
	while (len--)
	{
		*ptr++ = p;
	}
	return (b);
}
