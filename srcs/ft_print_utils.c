/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:51:42 by lyeh              #+#    #+#             */
/*   Updated: 2023/09/21 18:16:42 by lyeh             ###   ########.fr       */
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
	tab->f_space_pad = FALSE;
	tab->f_dash = FALSE;
	tab->f_perc_fmt = FALSE;
	tab->f_perc_shink = FALSE;
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
	printf("\tf_perc_shink: %d\n", tab->f_perc_shink);
	printf("\tf_pointer:    %d\n", tab->f_pointer);
	printf("\tf_hash:       %d\n", tab->f_hash);
}

void	_setup_print_flags(t_print_tab *tab, const char *c)
{
	if (*c == '0' && !tab->f_perc_fmt && !tab->width)
		tab->f_zero_pad = TRUE;
	else if (*c == ' ')
		tab->f_space_pad = TRUE;
	else if (*c == '-')
		tab->f_dash = TRUE;
	else if (*c == '+')
		tab->sign = "+";
	else if (*c == '.')
		tab->f_perc_fmt = TRUE;
	else if (*c == '#')
		tab->f_hash = TRUE;
	else if (ft_isdigit(*c))
	{
		if (tab->f_perc_fmt && !tab->perc_len)
		{
			if (*c == '0')
				tab->f_perc_shink = TRUE;
			tab->perc_len = ft_atoi(c);
		}
		else if (!tab->width && !tab->perc_len)
			tab->width = ft_atoi(c);
	}
}

void	ft_setup_print_table(const char *fmt, int start, t_print_tab *tab)
{
	const char	*formatters = "udicsupxX%";
	int			i;

	ft_init_print_table(tab);
	i = 0;
	while (fmt[start + i] && !ft_in_substr(fmt[start + i], formatters))
	{
		_setup_print_flags(tab, fmt + (start + i));
		i += 1;
	}
	tab->fmt_len = i + 1;
	tab->type = fmt[start + i];
	if (ft_tolower(tab->type) == 'x')
		tab->sign = "";
	if (ft_tolower(tab->type) == 'p')
		tab->f_hash = TRUE;
	if (tab->f_perc_fmt && !tab->perc_len && \
		(tab->type == 'd' || tab->type == 'i' || tab->type == 'u' || ft_tolower(tab->type) == 'x'))
		tab->f_perc_shink = TRUE;
}
