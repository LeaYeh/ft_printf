/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:58:27 by lyeh              #+#    #+#             */
/*   Updated: 2023/09/18 15:49:12 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_format_char(char c, t_print_tab *tab)
{
	char		*ret;
	char		arg_val[2];
	const char	pad_char = ' ';

	tab->total_len = ft_max(tab->width, 1);
	arg_val[0] = c;
	arg_val[1] = '\0';
	ret = ft_format_padding(
			arg_val,
			pad_char,
			tab->total_len,
			tab->f_dash);
	return (ret);
}
