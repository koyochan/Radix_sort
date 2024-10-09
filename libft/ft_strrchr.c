/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotkobay <kotkobay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:58:47 by kotkobay          #+#    #+#             */
/*   Updated: 2023/09/30 14:41:33 by kotkobay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	count;
	char	z;

	z = c;
	count = ft_strlen(s);
	if (c == '\0')
		return ((char *)s + count);
	while (count--)
	{
		if (s[count] == z)
		{
			return ((char *)s + count);
		}
	}
	return (NULL);
}

/* size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (*s != 0)
	{
		count++;
		s++;
	}
	return (count);
}

int	main(void)
{
	char *s = "libft-test-tokyo";
	printf("%s\n", strrchr(s, 'i'));

	printf("%s\n", ft_strrchr(s, 'i'));
} */