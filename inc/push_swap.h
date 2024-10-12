/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotkobay <kotkobay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:29:38 by kotkobay          #+#    #+#             */
/*   Updated: 2024/10/12 12:49:18 by kotkobay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct s_stacks
{
	int		*a;
	int		*b;
	int		a_size;
	int		b_size;
	char	*join_args;
}			t_stacks;

void		rotate(int *array, int size, char *direction, char *list);
void		swap(char *str, int *array, int size);
void		push(char *str, t_stacks *s);
void		sort_three_elements(t_stacks *s);
void		sort_four_to_five_elements(t_stacks *s);
void		radix_sort(t_stacks *s);
void		parse_numbers(t_stacks *s);
void		create_index(t_stacks *s);
void		initialize_stacks(int argc, char **argv, t_stacks *s);
void		free_with_message(t_stacks *s, char *msg);
void		sort_is_duplicated(t_stacks *s, int i);
int			is_array_sorted(t_stacks *s);
int			ft_atol(const char *n, t_stacks *s);
t_stacks	*initialize_stack_and_args(int argc, char **argv);
void		join_args(int argc, char **argv, t_stacks *s);
void		validate_arguments(int argc, char **argv);
int			is_invalid_sign(char current, char next);
int			is_invalid_sign(char current, char next);

#endif