/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:51:38 by lyeh              #+#    #+#             */
/*   Updated: 2023/09/17 18:32:03 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_utox(unsigned long int nbr, size_t len, t_bool is_upper)
{
	char					*ret;
	char					*tab;
	int						i;
	unsigned long long int	tmp;

	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	tab = "0123456789abcdef";
	if (is_upper)
		tab = "0123456789ABCDEF";
	i = 0;
	while (i < (int)len)
	{
		tmp = ft_pow(16, len - (i + 1));
		ret[i] = tab[(nbr / tmp)];
		nbr = nbr % tmp;
		i += 1;
	}
	ret[i] = '\0';
	return (ret);
}
