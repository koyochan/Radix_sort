/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotkobay <kotkobay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:28:21 by kotkobay          #+#    #+#             */
/*   Updated: 2024/10/09 19:17:05 by kotkobay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q push_swap");
// }

void	free_with_message(t_stacks *s, char *msg)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	if (s != NULL)
	{
		if (s->a != NULL)
			free(s->a);
		if (s->b != NULL)
			free(s->b);
		if (s->join_args != NULL)
			free(s->join_args);
		if (s != NULL)
			free(s);
	}
	exit(1);
}

static void	validate_arguments(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (!(ft_isdigit(argv[1][i])) && (argv[1][i] != ' ')
				&& (argv[1][i] != '-' && argv[1][i] != '+'))
			{
				free_with_message(NULL, "Error\n");
			}
			if ((argv[1][i] == '-' && (argv[1][i + 1] == '\0' || argv[1][i
						+ 1] == ' ')) || (argv[1][i] == '+' && (argv[1][i
						+ 1] == '\0' || argv[1][i + 1] == ' ')))
			{
				free_with_message(NULL, "Error\n");
			}
			i++;
		}
	}
	else
	{
		while (++i < argc)
		{
			j = 0;
			if (!argv[i][0] || (argv[i][0] && argv[i][0] == ' '))
				free_with_message(NULL, "Error\n");
			while (argv[i][j] != '\0')
			{
				if ((!(ft_isdigit(argv[i][j])) && (argv[i][j] != ' ')
						&& (argv[i][j] != '-' && argv[i][j] != '+'
							&& argv[i][j] != ' ')) || (argv[i][j] == '-'
						&& argv[i][j + 1] == '\0') || (argv[i][j] == '+'
						&& argv[i][j + 1] == '\0') || (argv[i][j] == '-'
						&& argv[i][j + 1] == ' ') || (argv[i][j] == '+'
						&& argv[i][j + 1] == ' '))
					free_with_message(NULL, "Error\n");
				j++;
			}
		}
	}
}

static void	join_args(int argc, char **argv, t_stacks *s)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	tmp2 = ft_strdup("");
	while (++i < argc && argv[i] != NULL)
	{
		tmp = ft_strjoin(tmp2, argv[i]);
		if (tmp2)
			free(tmp2);
		if (i != argc - 1)
		{
			tmp2 = ft_strjoin(tmp, " ");
			if (tmp)
				free(tmp);
			tmp = tmp2;
		}
	}
	s->join_args = ft_strdup(tmp);
	if (s->join_args == NULL)
		free_with_message(s, "Error\n");
	if (tmp)
		free(tmp);
}

void	remove_newline(char *str)
{
	char	*newline;

	newline = ft_strchr(str, '\n');
	if (newline)
	{
		*newline = '\0';
	}
}

int	main(int argc, char **argv)
{
	t_stacks	*s;
	char		*input;
	char		**new_argv;

	input = NULL;
	s = NULL;
	if (argc == 1)
	{
		input = get_next_line(0);
		if (input == NULL)
		{
			free_with_message(NULL, "Error\n");
			return (1);
		}
		remove_newline(input);
		new_argv = malloc((argc + 1) * sizeof(char *));
		if (new_argv == NULL)
		{
			free(input);
			free_with_message(NULL, "Error\n");
			return (1);
		}
		for (int i = 0; i < argc; i++)
		{
			new_argv[i] = argv[i];
		}
		new_argv[argc] = input;
		argc++;
		validate_arguments(argc, new_argv);
		s = malloc(sizeof(*s));
		if (s == NULL)
		{
			free(new_argv);
			return (1);
		}
		initialize_stacks(argc, new_argv, s);
		join_args(argc, new_argv, s);
		free(new_argv);
	}
	else
	{
		validate_arguments(argc, argv);
		s = malloc(sizeof(*s));
		if (s == NULL)
			exit(1);
		initialize_stacks(argc, argv, s);
		join_args(argc, argv, s);
	}
	parse_numbers(s);
	sort_is_duplicated(s, 0);
	create_index(s);
	if (s->a_size == 2 && s->a[0] > s->a[1])
		swap("sa", s->a, s->a_size);
	else if (s->a_size == 3)
		sort_three_elements(s);
	else if (s->a_size >= 4 && s->a_size <= 5)
		sort_four_to_five_elements(s);
	else
		radix_sort(s);
	sort_is_duplicated(s, 1);
	free_with_message(s, "Error\n");
	return (0);
}
