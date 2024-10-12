/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secound_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotkobay <kotkobay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:58:14 by kotkobay          #+#    #+#             */
/*   Updated: 2024/10/12 12:49:02 by kotkobay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_and_exit(char *str)
{
	write(1, "Error\n", 6);
	free(str);
	exit(1);
}

t_stacks	*initialize_stack_and_args(int argc, char **argv)
{
	t_stacks	*s;

	validate_arguments(argc, argv);
	s = malloc(sizeof(*s));
	if (!s)
		exit(1);
	initialize_stacks(argc, argv, s);
	join_args(argc, argv, s);
	return (s);
}

int	is_invalid_sign(char current, char next)
{
	if ((current == '-' || current == '+') && (next == '\0' || next == ' '))
		return (1);
	return (0);
}
