/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_01_read_actions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:23:03 by asuteau           #+#    #+#             */
/*   Updated: 2024/02/24 17:23:10 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_add_char(char *s, char c)
{
	char	*new_s;
	int		new_size;
	char	*original_new_s;
	char	*original_s;

	original_s = s;
	new_size = ft_strlen(s) + 2;
	new_s = malloc(new_size * sizeof(char));
	if (!new_s)
	{
		free(original_s);
		return (NULL);
	}
	original_new_s = new_s;
	while (*s)
	{
		*new_s = *s;
		new_s++;
		s++;
	}
	*new_s = c;
	new_s++;
	*new_s = '\0';
	free(original_s);
	return (original_new_s);
}

char	*read_actions(void)
{
	int		read_status;
	char	char_buffer;
	char	*s;

	char_buffer = ' ';
	s = malloc(sizeof(char));
	if (!s)
		return (NULL);
	*s = '\0';
	read_status = 1;
	while (char_buffer && read_status)
	{
		read_status = read(STDIN_FILENO, &char_buffer, 1);
		if (read_status == -1)
		{
			free(s);
			return (NULL);
		}
		s = ft_add_char(s, char_buffer);
		if (!s)
			return (NULL);
	}
	return (s);
}
