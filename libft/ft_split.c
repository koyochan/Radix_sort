/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotkobay <kotkobay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:06:32 by kotkobay          #+#    #+#             */
/*   Updated: 2023/10/08 13:12:10 by kotkobay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(char const *s, char sep)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == sep)
			s++;
		if (*s && *s != sep)
		{
			count++;
			while (*s && *s != sep)
				s++;
		}
	}
	return (count);
}

char	*make_word(char const *s, char sep)
{
	char	*word;
	int		i;

	i = 0;
	while (s[i] && *s != sep)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (*s && *s != sep)
	{
		word[i++] = *s++;
	}
	word[i] = '\0';
	return (word);
}

void	clean_up(char **words, int idx)
{
	while (idx >= 0)
	{
		free(words[idx]);
		idx--;
	}
	free(words);
}

const char	*process_current_word(char ***words, int *i, const char *s,
		char sep)
{
	(*words)[*i] = make_word(s, sep);
	if (*s != sep && *s)
	{
		if (!(*words)[*i])
		{
			clean_up(*words, *i);
			*words = NULL;
			return (NULL);
		}
		(*i)++;
		while (*s && *s != sep)
			s++;
	}
	if (*s)
		s++;
	return (s);
}

char	**ft_split(char const *s, char sep)
{
	int		i;
	char	**words;

	i = 0;
	if (!s)
		return (NULL);
	words = (char **)malloc(sizeof(char *) * (word_count(s, sep) + 1));
	if (!words)
		return (NULL);
	while (*s)
	{
		s = process_current_word(&words, &i, s, sep);
		if (!words)
			return (NULL);
	}
	words[i] = NULL;
	return (words);
}
