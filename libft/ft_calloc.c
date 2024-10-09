/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotkobay <kotkobay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 08:31:18 by kotkobay          #+#    #+#             */
/*   Updated: 2023/10/04 20:42:18 by kotkobay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;
	size_t	total;

	total = count * size;
	if (count != 0 && total / count != size)
		return (NULL);
	result = (void *)malloc(total);
	if (result == NULL)
		return (NULL);
	ft_memset((unsigned char *)result, 0, total);
	return (result);
}
