/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:56:58 by lyeh              #+#    #+#             */
/*   Updated: 2023/09/15 21:56:49 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	else if (*c == '*')
		tab->f_perc_arg = TRUE;
	else if (*c == '#')
		tab->f_hex_suffix = TRUE;
	else if (ft_isdigit(*c))
	{
		if (tab->f_perc_fmt && !tab->perc_len)
			tab->perc_len = ft_atoi(c);
		else if (!tab->width)
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
}

char	*ft_format_padding(
	char *str, char pad, int total_len, t_bool on_right)
{
	char	*ret;
	int		len;

	if (!str)
		return (NULL);
	if (ft_strlen(str) >= (size_t)total_len)
		return (ft_strdup(str));
	ret = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!ret)
		return (NULL);
	len = ft_strlen(str);
	if (on_right)
	{
		ft_memcpy(ret, str, len);
		ft_memset(ret + len, (int)pad, total_len - len);
	}
	else
	{
		ft_memset(ret, (int)pad, total_len - len);
		ft_memcpy(ret + (total_len - len), str, len);
	}
	ret[total_len] = '\0';
	return (ret);
}

char	*ft_format_persicion(char *num_str, int perc_len, t_print_tab *tab)
{
	char	*ret;
	int		i;
	char	*tmp;

	if (ft_strlen(num_str) >= (size_t)perc_len)
		return (ft_strdup(num_str));
	if (num_str[0] == '-')
		tab->sign = "-";
	ret = (char *)malloc(sizeof(char) * (perc_len + ft_strlen(tab->sign) + 1));
	if (!ret)
		return (NULL);
	i = 0;
	if (ft_strlen(tab->sign))
		ret[i++] = tab->sign[0];
	tmp = ft_format_padding(
			num_str + ft_strlen(tab->sign), '0', perc_len, FALSE);
	ft_memcpy(ret + i, tmp, ft_strlen(tmp));
	ret[perc_len + ft_strlen(tab->sign)] = '\0';
	free(tmp);
	return (ret);
}
