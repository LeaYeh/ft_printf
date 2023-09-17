/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:51:42 by lyeh              #+#    #+#             */
/*   Updated: 2023/09/17 18:29:51 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_print_table(t_print_tab *tab)
{
	tab->width = 0;
	tab->perc_len = 0;
	tab->total_len = 0;
	tab->fmt_len = 0;
	tab->sign = "";
	tab->type = '\0';
	tab->f_zero_pad = FALSE;
	tab->f_dash = FALSE;
	tab->f_perc_fmt = FALSE;
	tab->f_perc_arg = FALSE;
	tab->f_pointer = FALSE;
	tab->f_hash = FALSE;
}

void	ft_print_table_status(t_print_tab *tab)
{
	printf("table_status:   %p\n", tab);
	printf("\twidth:        %d\n", tab->width);
	printf("\tperc_len:     %d\n", tab->perc_len);
	printf("\ttotal_len:    %d\n", tab->total_len);
	printf("\tfmt_len:      %d\n", tab->fmt_len);
	printf("\tsign:         %s\n", tab->sign);
	printf("\ttype:         %c\n", tab->type);
	printf("\tf_zero_pad:   %d\n", tab->f_zero_pad);
	printf("\tf_space_pad:  %d\n", tab->f_space_pad);
	printf("\tf_dash:       %d\n", tab->f_dash);
	printf("\tf_perc_fmt:   %d\n", tab->f_perc_fmt);
	printf("\tf_perc_arg:   %d\n", tab->f_perc_arg);
	printf("\tf_pointer:    %d\n", tab->f_pointer);
	printf("\tf_hash:       %d\n", tab->f_hash);
}
