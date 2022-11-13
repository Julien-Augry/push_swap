/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaugry <juaugry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 22:16:17 by juaugry           #+#    #+#             */
/*   Updated: 2022/10/22 17:36:55 by juaugry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_free(char **s, int i)
{
	i--;
	while (i >= 0)
		free(s[i--]);
	free(s);
}

static	int	ft_lenw(char const *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i] != '\0' && s[i] == c)
		i++;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

static	int	ft_countwords(char *s, char c)
{
	int		i;
	int		check;
	int		words;

	check = 0;
	i = 0;
	words = 0;
	if (!s || s[i] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			check = 1;
			i++;
		}
		while (s[i] == c && s[i] != '\0')
			i++;
		if (check == 1)
			words++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		words;

	i = 0;
	words = ft_countwords((char *)s, c);
	tab = (char **)malloc(sizeof(char *) * (words + 1));
	if (!(s) || !(tab))
		return (NULL);
	while (i < words && *s != '\0')
	{
		j = 0;
		tab[i] = malloc(sizeof(char) * (ft_lenw(s, c) + 1));
		if (!(tab[i]))
			return (ft_free(tab, i), NULL);
		while (*s == c)
			s++;
		while (*s && *s != c)
			tab[i][j++] = *s++;
		tab[i++][j] = '\0';
	}
	tab[i] = NULL;
	return (tab);
}
