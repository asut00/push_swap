/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_01_check_args.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:23:03 by asuteau           #+#    #+#             */
/*   Updated: 2024/02/24 17:23:10 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_args_and_fillup(t_stacks *stacks, int *argc, char ***argv)
{
	*argv = check_args(argc, *argv);
	if (!*argv)
		return (error_return_function(0));
	stacks->stack_a = fill_up_arrays(stacks, *argc, *argv);
	if (stacks->original_argc == 2)
		free_splitted_words_and_argv(*argv, *argc - 1);
	if (!stacks->stack_a)
		return (error_return_function(0));
	return (1);
}

char	**check_args(int *argc, char **argv)
{
	int	original_argc;

	original_argc = *argc;
	if (*argc < 2 || !argv[1][0])
		return (NULL);
	else if (*argc == 2 && argv[1][0])
	{
		if (!contains_only_space_sign_or_digit(argv[1]))
			return (NULL);
		*argc = count_words_spe(argv[1], ' ') + 1;
		argv = ft_split_spe(argv[1], ' ');
		if (!argv)
			return (NULL);
	}
	if (!check_num_format(argc, argv))
	{
		if (original_argc == 2)
			free_splitted_words_and_argv(argv, *argc - 1);
		return (NULL);
	}
	return (argv);
}

int	contains_only_space_sign_or_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '-' || str[i] == '+')
			&& (!str[i + 1] || !ft_isdigit(str[i + 1])))
			return (0);
		if (!ft_is_space_sign_or_digit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_space_sign_or_digit(int c)
{
	if ((48 <= c && c <= 57) || c == ' ' || c == '-' || c == '+')
		return (1);
	else
		return (0);
}

char	**check_num_format(int *argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < *argc)
	{
		j = 0;
		if (argv[i][j] == '+' || argv[i][j] == '-')
			j++;
		if (!argv[i][j])
			return (NULL);
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]))
				j++;
			else
				return (NULL);
		}
		i++;
	}
	return (argv);
}
