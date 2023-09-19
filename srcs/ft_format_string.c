/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:01:22 by lyeh              #+#    #+#             */
/*   Updated: 2023/09/19 16:36:52 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_format_string(char *s, t_print_tab *tab)
{
	char		*ret;
	const char	pad_char = ' ';
	char		*tmp;

	if (!s)
		s = "(null)";
	if (tab->f_perc_fmt)
		tmp = ft_substr(s, 0, tab->perc_len);
	else
		tmp = ft_substr(s, 0, ft_strlen(s));
	tab->total_len = ft_max(2, ft_strlen(tmp), tab->width);
	ret = ft_format_padding(tmp, pad_char, tab);
	free(tmp);
	return (ret);
}
