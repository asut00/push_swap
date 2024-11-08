/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_00_errors_and_free.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:23:03 by asuteau           #+#    #+#             */
/*   Updated: 2024/02/24 17:23:10 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_return_function(int ret_value)
{
	write(2, "Error\n", 6);
	return (ret_value);
}

int	*free_and_return_null(int **m1, int **m2, int **m3, char **m4)
{
	if (m1 && *m1)
	{
		free(*m1);
		*m1 = NULL;
	}
	if (m2 && *m2)
	{
		free(*m2);
		*m2 = NULL;
	}
	if (m3 && *m3)
	{
		free(*m3);
		*m3 = NULL;
	}
	if (m4 && *m4)
	{
		free(*m4);
		*m4 = NULL;
	}
	return (NULL);
}

void	free_splitted_words_and_argv(char **argv, int size)
{
	int	i;

	i = 0;
	while (i <= size + 1)
	{
		free_and_return_null(NULL, NULL, NULL, &argv[i]);
		i++;
	}
	free(argv);
}
