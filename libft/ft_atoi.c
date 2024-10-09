/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotkobay <kotkobay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:22:14 by kotkobay          #+#    #+#             */
/*   Updated: 2023/10/04 19:57:47 by kotkobay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_atoi(const char *str)
{
	unsigned long long	result;
	int					sign;

	result = 0;
	sign = 1;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		if (sign == -1 && result > (unsigned long long)(LONG_MAX - (*str - '0'))
			/ 10)
			return (0);
		if (sign == 1 && result > (unsigned long long)(LONG_MAX - (*str - '0'))
			/ 10)
			return (-1);
		result = result * 10 + *str - '0';
		str++;
	}
	return ((int)result * sign);
}

/* int	main(void)
{
	int ft_res;
	int res;

	ft_res = ft_atoi("9223372036854775807");
	res = atoi("9223372036854775807");
	printf("  ft_atoi: %d\n", ft_res);
	printf("  atoi: %d\n", res);
	return (0);
} */