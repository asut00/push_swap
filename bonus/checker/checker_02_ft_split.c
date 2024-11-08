/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 07:47:56 by asuteau           #+#    #+#             */
/*   Updated: 2024/05/24 17:09:19 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	count_words(char const *str, char charset)
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

int	ft_sl_s(char const *str, char charset)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0' && !(str[i] == charset))
		i++;
	return (i);
}

char	**free_tab(char **tab, int x)
{
	while (x >= 0)
	{
		free(tab[x]);
		x--;
	}
	free(tab);
	return (NULL);
}

char	**attribute_words(char **tab, char const *str, char c)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	while (str && str[i] != '\0')
	{
		while (str[i] != '\0' && (str[i] == c))
			i++;
		if (str[i] != '\0' && !((str[i] == c)))
		{
			y = 0;
			tab[x] = malloc(((ft_sl_s(&str[i], c) + 1) * sizeof(char)));
			if (!tab[x])
				return (free_tab(tab, x));
			while (str[i] != '\0' && !(str[i] == c))
				tab[x][y++] = str[i++];
			tab[x++][y] = '\0';
		}
	}
	tab[x] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		word_count;
	char	**tab;

	word_count = count_words(s, c);
	tab = malloc((word_count + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	tab = attribute_words(tab, s, c);
	return (tab);
}

/*
#include <stdio.h>

int	main(void)
{
	char str2[] = "...salut.cava..";
	char charset2 = '.';
	char **split2;
	split2 = ft_split(str2, charset2);
	int i2 = 0;
	while(split2[i2] != 0)
	{
		printf("split2[%d] is : |%s|\n", i2, split2[i2]);
		i2++;
		//printf("%d", ft_charset_counter(str, charset));
	}
	printf("split2[%d] is : |%s|\n", i2, split2[i2]);
}
*/