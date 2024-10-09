/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotkobay <kotkobay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:15:08 by kotkobay          #+#    #+#             */
/*   Updated: 2023/10/02 14:20:04 by kotkobay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		index;
	char	*res;
	int		len;
	char	*original_res;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	res = (char *)malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	index = 0;
	original_res = res;
	while (*s)
	{
		*res = (*f)(index, *s);
		index++;
		s++;
		res++;
	}
	*res = 0;
	return (original_res);
}
