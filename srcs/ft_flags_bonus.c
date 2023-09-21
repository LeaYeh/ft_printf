/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:56:58 by lyeh              #+#    #+#             */
/*   Updated: 2023/09/21 18:51:18 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_format_padding(
	char *str, char pad, t_print_tab *tab, t_bool is_perc)
{
	char	*ret;
	int		padded_len;

	if (!str)
		return (NULL);
	padded_len = ft_get_len_after_padding(str, tab, is_perc);
	if (tab->f_perc_shink && is_perc)
		str = str + (ft_strlen(str) - padded_len);
	if ((!ft_strlen(str) && tab->type == 'c' && \
			padded_len <= (int)ft_strlen(str)) || \
			(int)ft_strlen(str) >= padded_len)
		return (ft_strdup(str));
	if (ft_is_pad_on_left(tab, is_perc))
		ret = ft_pad_on_left(str, pad, tab->type, padded_len);
	else
		ret = ft_pad_on_right(str, pad, tab->type, padded_len);
	return (ret);
}

char	*_format_perc_num(char *num_str, t_print_tab *tab)
{
	char	*ret;
	char	*tmp;
	int		i;

	if (ft_strncmp(tab->sign, "-", 1) == 0)
		num_str = num_str + ft_strlen(tab->sign);
	tmp = ft_format_padding(num_str, '0', tab, TRUE);
	ret = (char *)malloc(
			sizeof(char) * (ft_strlen(tmp) + ft_strlen(tab->sign) + 1));
	if (!ret)
		return (NULL);
	i = 0;
	if (ft_strlen(tab->sign))
		ret[i++] = tab->sign[0];
	ft_memcpy(ret + i, tmp, ft_strlen(tmp));
	ret[i + ft_strlen(tmp)] = '\0';
	free(tmp);
	return (ret);
}

char	*_format_perc_hex(char *num_str, t_print_tab *tab)
{
	if (ft_strlen(num_str) >= (size_t)tab->perc_len && !tab->f_perc_shink)
	{
		if (ft_strncmp(tab->sign, "+", 1) == 0)
			return (ft_strjoin(tab->sign, num_str));
		return (ft_strdup(num_str));
	}
	return (_format_perc_num(num_str, tab));
}

char	*ft_format_persicion(char *num_str, t_print_tab *tab)
{
	if (ft_tolower(tab->type) == 'x')
		return (_format_perc_hex(num_str, tab));
	return (_format_perc_num(num_str, tab));
}

char	*ft_format_suffix(char *s, t_bool is_upper, t_print_tab *tab)
{
	char	*ret;

	if (!s)
		return (NULL);
	if (!tab->f_hash || ft_strncmp(s, "0", 1) == 0 || \
		ft_strncmp(s, "(nil)", 5) == 0)
		return (ft_strdup(s));
	if (is_upper)
		ret = ft_strjoin("0X", s);
	else
		ret = ft_strjoin("0x", s);
	return (ret);
}
