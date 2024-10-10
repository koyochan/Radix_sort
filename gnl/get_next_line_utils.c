/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotkobay <kotkobay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:33:30 by kotkobay          #+#    #+#             */
/*   Updated: 2024/05/20 14:38:18 by kotkobay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_c(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_c(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (s);
		i++;
	}
	return (0);
}

char	*ft_strjoin_c(char *save, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!save)
	{
		save = (char *)malloc(1 * sizeof(char));
		save[0] = '\0';
	}
	if (!save || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen_c(save) + ft_strlen_c(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (save)
		while (save[++i] != '\0')
			str[i] = save[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen_c(save) + ft_strlen_c(buff)] = '\0';
	free(save);
	return (str);
}
