/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:01:22 by lyeh              #+#    #+#             */
/*   Updated: 2023/09/15 18:42:27 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_format_string(char *s, t_print_tab *tab)
{
	char		*ret;
	const char	pad_char = ' ';

	tab->total_len = ft_max(tab->width, ft_strlen(s));
	ret = ft_format_padding(s, pad_char, tab->total_len, tab->f_dash);
	return (ret);
}
