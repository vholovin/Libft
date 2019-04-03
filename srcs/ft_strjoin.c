/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 16:05:51 by vholovin          #+#    #+#             */
/*   Updated: 2016/12/26 19:24:18 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	char		*res;

	if (!(str = (char *)malloc(sizeof(char) *
				(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	res = str;
	if (s1)
		while (*s1)
			*(str++) = *(s1++);
	if (s2)
		while (*s2)
			*(str++) = *(s2++);
	*str = '\0';
	return (res);
}
