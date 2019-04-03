/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:29:54 by vholovin          #+#    #+#             */
/*   Updated: 2019/04/02 16:29:56 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		countwords(char const *s, char c)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			j++;
		i++;
	}
	return (j);
}

static size_t		countchr(char const *s, size_t n, char c)
{
	size_t j;

	j = 0;
	while (s[n] != c && s[n++] != '\0')
		j++;
	return (j);
}

char				**ft_strsplitlen(char const *s, char c, int *num)
{
	size_t		v[3];
	char		**array;

	bzero(&v, 3 * sizeof(size_t));
	if (!s)
		return (NULL);
	*num = countwords(s, c);
	if (!(array = (char **)malloc((*num + 1) * sizeof(char*))))
		return (NULL);
	while (s[v[1]])
	{
		while (s[v[1]] == c)
			v[1]++;
		if (s[v[1]])
		{
			if (!(array[v[0]] = (char*)malloc(countchr(s, v[1], c) + 1)))
				return (NULL);
			v[2] = 0;
			while (s[v[1]] != c && s[v[1]] != '\0')
				array[v[0]][v[2]++] = s[v[1]++];
			array[v[0]++][v[2]] = '\0';
		}
	}
	array[v[0]] = (NULL);
	return (array);
}
