/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:09:13 by lyeh              #+#    #+#             */
/*   Updated: 2023/09/19 15:23:45 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// void    ft_set_total_len(const char *context, t_print_tab *tab)
// {
// 	if (tab->type == 'd')
// 	{
		
// 	}
// }

char	*ft_handle_null(t_print_tab *tab)
{
	char	*term;

	if (tab->type == 'p')
		term = "(nil)";
	else
		term = "(null)";
	if (tab->f_perc_fmt && tab->perc_len < (int)ft_strlen(term))
	{
		tab->total_len = tab->width;
		return (ft_strdup(""));
	}
	tab->total_len = ft_max(ft_strlen(term), tab->width);
	return (ft_strdup(term));
}

