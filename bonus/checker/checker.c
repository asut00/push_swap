/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:23:03 by asuteau           #+#    #+#             */
/*   Updated: 2024/02/24 17:23:10 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	checker(t_stacks	*stks)
{
	char		*actions_str;
	char		**splitted_actions;

	actions_str = read_actions();
	if (!actions_str)
	{
		free_and_return_null(&(stks->stack_a), &(stks->stack_b), NULL, NULL);
		error_exit_function(EXIT_FAILURE);
	}
	splitted_actions = ft_split(actions_str, '\n');
	free(actions_str);
	if (!splitted_actions)
	{
		free_and_return_null(&(stks->stack_a), &(stks->stack_b), NULL, NULL);
		error_exit_function(EXIT_FAILURE);
	}
	if (ft_strlen(splitted_actions[0]) != 1)
		execute_actions(stks, splitted_actions);
	if (stks->size_a == stks->original_size_a
		&& stks->size_b == 0
		&& is_sorted(stks->stack_a, stks->size_a))
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
	free_splitted(splitted_actions);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	int			check;

	stacks.original_argc = argc;
	stacks.size_b = 0;
	if (!check_args_and_fillup(&stacks, &argc, &argv))
		return (EXIT_FAILURE);
	stacks.original_size_a = argc - 1;
	stacks.size_a = argc - 1;
	check = check_doubles_and_if_sorted(&stacks);
	if (check == ERROR_DOUBLES)
		return (error_return_function(EXIT_FAILURE));
	else if (check == SORTED)
		return (EXIT_SUCCESS);
	if (stacks.size_a < 2)
	{
		free_and_return_null(&(stacks.stack_a), &(stacks.stack_b), NULL, NULL);
		return (0);
	}
	checker(&stacks);
	free_and_return_null(&(stacks.stack_a), &(stacks.stack_b), NULL, NULL);
	return (0);
}
