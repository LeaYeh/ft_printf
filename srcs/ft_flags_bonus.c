/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:56:58 by lyeh              #+#    #+#             */
/*   Updated: 2023/09/20 18:58:05 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*_pad_on_right(char *str, char pad, size_t total_len)
{
	char	*ret;
	int		len;

	ret = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!ret || !str)
		return (NULL);
	len = ft_strlen(str);
	ft_memcpy(ret, str, len);
	ft_memset(ret + len, (int)pad, total_len - len);
	ret[total_len] = '\0';
	return (ret);
}

char	*_pad_on_left(char *str, char pad, size_t total_len)
{
	char	*ret;
	int		len;
	int		i;

	ret = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!ret || !str)
		return (NULL);
	i = 0;
	if (str[0] == '-' && pad == '0')
		ret[i++] = '-';
	len = ft_strlen(str + i);
	ft_memset(ret + i, (int)pad, total_len - len - i);
	ft_memcpy(ret + (total_len - len), str + i, len);
	ret[total_len] = '\0';
	return (ret);
}

int		_get_shink_len(char *context, t_print_tab *tab)
{
	int	len;

	len = ft_strlen(context);
	if (tab->type == 'i' || tab->type == 'd' || tab->type == 'u' || \
		ft_tolower(tab->type) == 'x')
	{
		if (*context++ == '0')
			len--;
	}
	return (len);
}

int	_get_len_after_padding(char *context, t_print_tab *tab, t_bool is_perc)
{
	int	len;

	len = tab->width;
	if (tab->f_perc_shink && is_perc)
		len = _get_shink_len(context, tab);
	else if (is_perc)
		len = tab->perc_len;
	else if (tab->f_space_pad && tab->type != 's' && !ft_strlen(tab->sign))
		len = ft_max(2, tab->width, 1 + ft_strlen(context));
	else
		len = tab->width;
	return (len);
}

t_bool	_is_pad_on_left(t_print_tab *tab, t_bool is_perc)
{
	if (!is_perc && (tab->f_dash || tab->f_hash))
		return (FALSE);
	if ((tab->type == 'd' || tab->type == 'i') && ft_strlen(tab->sign))
		return (TRUE);
	return (TRUE);
}

char	*ft_format_padding(
	char *str, char pad, t_print_tab *tab, t_bool is_perc)
{
	char	*ret;
	int		padded_len;

	if (!str)
		return (NULL);
	padded_len = _get_len_after_padding(str, tab, is_perc);
	if (tab->f_perc_shink && is_perc)
		str = str + (ft_strlen(str) - padded_len);
	if ((!ft_strlen(str) && tab->type == 'c') || \
			(int)ft_strlen(str) >= padded_len)
		return (ft_strdup(str));
	if (_is_pad_on_left(tab, is_perc))
		ret = _pad_on_left(str, pad, padded_len);
	else
		ret = _pad_on_right(str, pad, padded_len);
	return (ret);
}

char	*_format_perc_num(char *num_str, t_print_tab *tab)
{
	char	*ret;
	char	*tmp;
	int		i;
	int		perc_len;

	perc_len = tab->perc_len;
	if (!tab->f_perc_fmt && !tab->f_perc_shink)
		perc_len = ft_strlen(num_str);
	ret = (char *)malloc(
			sizeof(char) * (perc_len + ft_strlen(tab->sign) + 1));
	if (!ret)
		return (NULL);
	i = 0;
	if (ft_strlen(tab->sign))
		ret[i++] = tab->sign[0];
	if (ft_strncmp(tab->sign, "-", 1) == 0)
		num_str = num_str + ft_strlen(tab->sign);
	tmp = ft_format_padding(num_str, '0', tab, TRUE);
	ft_memcpy(ret + i, tmp, ft_strlen(tmp));
	ret[i + ft_strlen(tmp)] = '\0';
	free(tmp);
	return (ret);
}

char	*_format_perc_hex(char *num_str, t_print_tab *tab)
{
	if (ft_strlen(num_str) >= (size_t)tab->perc_len)
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
	if (!tab->f_hash)
		return (ft_strdup(s));
	if (is_upper)
		ret = ft_strjoin("0X", s);
	else
		ret = ft_strjoin("0x", s);
	return (ret);
}
