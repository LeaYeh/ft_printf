/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:52:47 by lyeh              #+#    #+#             */
/*   Updated: 2023/09/17 18:02:38 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_in_substr(const char c, const char *sub)
{
	int	i;

	i = 0;
	while (sub[i])
	{
		if (sub[i] == c)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

long long int	ft_pow(int base, int n)
{
	long long int	ret;

	ret = 1;
	while (n > 0)
	{
		ret *= base;
		n--;
	}
	return (ret);
}
