/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:24:53 by alermi            #+#    #+#             */
/*   Updated: 2024/10/30 13:25:42 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_word_count(char const *s, char c)
{
	int				is_word;
	unsigned int	word_count;

	word_count = 0;
	is_word = 0;
	while (*s)
	{
		if (*s != c && is_word == 0)
		{
			is_word = 1;
			word_count++;
		}
		else if (*s == c)
			is_word = 0;
		s++;
	}
	return (word_count);
}

static void	ft_freemem(char **matris, int count_O_words)
{
	while (count_O_words >= 0)
	{
		free(matris[count_O_words]);
		count_O_words--;
	}
	free(matris);
}

static int	ft_word_selector(char const *s, char c, int word_count, char **dest)
{
	int	i;
	int	j;
	int	a;

	i = 0;
	a = 0;
	while (a < word_count)
	{
		while (s[i] == c && s[i])
			i++;
		j = 0;
		while (s[j + i] && s[j + i] != c)
			j++;
		dest[a] = ft_substr(s, i, j);
		if (dest[a] == 0)
		{
			ft_freemem(dest, a - 1);
			return (-1);
		}
		a++;
		i += j;
	}
	dest[a] = 0;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	word_count;
	char			**matris;

	word_count = ft_word_count(s, c);
	matris = (char **)ft_calloc((word_count + 1), (sizeof(char *)));
	if (!matris)
		return (NULL);
	if (ft_word_selector(s, c, word_count, matris) == -1)
		return (NULL);
	return (matris);
}
