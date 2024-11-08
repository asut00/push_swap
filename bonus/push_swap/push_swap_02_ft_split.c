/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_02_ft_split.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:23:03 by asuteau           #+#    #+#             */
/*   Updated: 2024/02/24 17:23:10 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	count_words_spe(char const *str, char charset)
{
	int	i;
	int	count_words;

	i = 0;
	count_words = 0;
	while (str && str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == charset)
			i++;
		if (str[i] != '\0' && !(str[i] == charset))
			count_words++;
		while (str[i] != '\0' && !(str[i] == charset))
			i++;
	}
	return (count_words);
}

int	ft_sl_s_spe(char const *str, char charset)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0' && !(str[i] == charset))
		i++;
	return (i);
}

char	**free_tab_spe(char **tab, int x)
{
	while (x >= 0)
	{
		free(tab[x]);
		x--;
	}
	free(tab);
	exit(1);
}

char	**attribute_words_spe(char **tab, char const *str, char c)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	tab[0] = NULL;
	x = 1;
	while (str && str[i] != '\0')
	{
		while (str[i] != '\0' && (str[i] == c))
			i++;
		if (str[i] != '\0' && !((str[i] == c)))
		{
			y = 0;
			tab[x] = malloc(((ft_sl_s_spe(&str[i], c) + 1) * sizeof(char)));
			if (!tab[x])
				return (free_tab_spe(tab, x));
			while (str[i] != '\0' && !(str[i] == c))
				tab[x][y++] = str[i++];
			tab[x++][y] = '\0';
		}
	}
	tab[x] = NULL;
	return (tab);
}

char	**ft_split_spe(char const *str, char c)
{
	int		word_count;
	char	**tab;

	word_count = count_words_spe(str, c) + 1;
	tab = malloc((word_count + 1) * sizeof(char *));
	if (!tab)
		exit(1);
	tab = attribute_words_spe(tab, str, c);
	if (!tab)
		return (NULL);
	return (tab);
}
