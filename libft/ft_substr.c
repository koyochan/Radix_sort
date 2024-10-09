/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotkobay <kotkobay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 09:10:57 by kotkobay          #+#    #+#             */
/*   Updated: 2023/10/04 18:51:02 by kotkobay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*result;
	int				i;
	unsigned int	len_s;

	i = 0;
	if (s == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (len_s <= start)
		return (ft_strdup(""));
	if (len > len_s - start)
		len = len_s - start;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	while (len)
	{
		result[i] = s[i + start];
		i++;
		len--;
	}
	result[i] = 0;
	return (result);
}

/* int	main(void)
{
	char *s = "hello fuk";
	size_t len = 3;
	unsigned int start = 2;
	printf("%s\n", ft_substr(s, start, len));
} */