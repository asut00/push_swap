/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:23:03 by asuteau           #+#    #+#             */
/*   Updated: 2024/02/24 17:23:10 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	algorythm(&stacks);
	free_and_return_null(&(stacks.stack_a), &(stacks.stack_b), NULL, NULL);
	return (0);
}
