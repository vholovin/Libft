/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 18:24:47 by vholovin          #+#    #+#             */
/*   Updated: 2016/12/26 18:48:02 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int		ft_power_d(long int nb, int pow)
{
	int x;

	x = nb;
	while (pow > 1)
	{
		nb *= x;
		pow--;
	}
	return (nb);
}

static int			ft_strisdigit(char *str)
{
	int		i;
	int		end;

	i = -1;
	end = 0;
	while (str[++i] == ' ')
		;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if ((str[i] >= 48 && str[i] <= 57) && end == 0)
			i++;
		else if (str[i] == ' ' && end == 0)
			end = 1;
		else
			return (0);
	}
	return (1);
}

static int			ft_lennb(char *str)
{
	int		i;

	i = -1;
	while (ft_isdigit(str[++i]))
		;
	return (i);
}

static long int		ft_atoi_d(char *str)
{
	int			minus;
	long int	n;

	minus = 0;
	n = 0;
	while (*str == ' ')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		minus = '1';
		str++;
	}
	while ((*str <= '9') && (*str >= '0'))
	{
		n = (n * 10) + (*str - '0');
		str++;
	}
	if (minus == '1')
		n = -n;
	return (n);
}

float				ft_atof(char *s, char c)
{
	float	result;
	int		i;
	char	*a;

	i = -1;
	a = NULL;
	result = 0;
	while (s[++i] != c)
	{
		if (s[i] == '\0')
			return (ft_atoi_d(s));
	}
	a = &s[i + 1];
	i = -1;
	if (!ft_strisdigit(&a[++i]))
		ft_atoi_d(s);
	result = ft_atoi_d(s);
	if (result < 0)
		result -= (double)ft_atoi_d(a) / (double)ft_power_d(10, ft_lennb(a));
	else
		result += (double)ft_atoi_d(a) / (double)ft_power_d(10, ft_lennb(a));
	if (s[0] == '-' && ft_atoi_d(s) == 0)
		result *= -1;
	return (result);
}
