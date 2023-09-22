/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 22:34:50 by lyeh              #+#    #+#             */
/*   Updated: 2023/09/22 22:39:57 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int n, t_bool is_upper)
{
	char	*num_str;
	int		len;

	num_str = ft_utox(n, is_upper);
	len = ft_strlen(num_str);
	write(1, num_str, len);
	free(num_str);
	return (len);
}
