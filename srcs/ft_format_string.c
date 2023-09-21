/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:01:22 by lyeh              #+#    #+#             */
/*   Updated: 2023/09/21 18:44:08 by lyeh             ###   ########.fr       */
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
	if (ft_strncmp(s, "(null)", ft_strlen(s)) == 0 && tab->f_perc_fmt)
	{
		if (tab->perc_len >= ft_strlen(s))
			tmp = ft_strdup(s);
		else
			tmp = ft_strdup("");
	}
	else if (tab->f_perc_fmt)
		tmp = ft_substr(s, 0, tab->perc_len);
	else
		tmp = ft_substr(s, 0, ft_strlen(s));
	ret = ft_format_padding(tmp, pad_char, tab, FALSE);
	tab->total_len = ft_strlen(ret);
	free(tmp);
	return (ret);
}
