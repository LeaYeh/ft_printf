/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr2base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:51:38 by lyeh              #+#    #+#             */
/*   Updated: 2023/09/15 16:16:54 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

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

/*
char	*ft_nbr2hex(long long int nbr, size_t len, t_bool in_upper)
{
	char			*tab;
	char			*ret;
	long long int	tmp;
	int				i;

	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	tab = "0123456789abcdef";
	if (in_upper)
		tab = "0123456789ABCDEF";
	i = 0;
	while (i < len)
	{
		tmp = ft_pow(16, len - (i + 1));
		ret[i] = tab[(nbr / tmp)];
		nbr = nbr % tmp;
		i += 1;
	}
	ret[i] = '\0';
	return (ret);
}*/

// int main(void)
// {
// 	char *ret = ft_nbr2hex((long long int)0xFFFFFFFFFFFF, 32, TRUE);
// 	printf("|%s|\n", ret);
// }