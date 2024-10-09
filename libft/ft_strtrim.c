/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotkobay <kotkobay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 10:20:57 by kotkobay          #+#    #+#             */
/*   Updated: 2023/10/08 12:33:32 by kotkobay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_start(char const *s1, char const *set)
{
	int	start;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	return (start);
}

int	find_goal(char const *s1, char const *set, int start)
{
	int	goal;

	goal = ft_strlen(s1) - 1;
	while (goal > start && ft_strchr(set, s1[goal]))
		goal--;
	return (goal);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		goal;
	char	*result;
	int		i;

	if (!s1 || !set)
		return (NULL);
	start = find_start(s1, set);
	goal = find_goal(s1, set, start);
	if (start > goal)
		return (ft_strdup(""));
	result = (char *)malloc(sizeof(char) * (goal - start + 2));
	if (!result)
		return (NULL);
	i = 0;
	while (start <= goal)
		result[i++] = s1[start++];
	result[i] = 0;
	return (result);
}

/* int	main(void)
{
	char *s1 = "setadwadatttse";
	char *set = "set";
	printf("%s\n", ft_strtrim(s1, set));
} */