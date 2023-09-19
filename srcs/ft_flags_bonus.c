/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:56:58 by lyeh              #+#    #+#             */
/*   Updated: 2023/09/18 17:40:37 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_format_padding(char *str, char pad, t_print_tab *tab)
{
	char	*ret;
	int		len;

	if (!str)
		return (NULL);
	if ((!ft_strlen(str) && tab->type == 'c') || \
			(int)ft_strlen(str) >= tab->total_len)
		return (ft_strdup(str));
	ret = (char *)malloc(sizeof(char) * (tab->total_len + 1));
	if (!ret)
		return (NULL);
	len = ft_strlen(str);
	if (tab->f_dash || tab->f_hash)
	{
		ft_memcpy(ret, str, len);
		ft_memset(ret + len, (int)pad, tab->total_len - len);
	}
	else
	{
		ft_memset(ret, (int)pad, tab->total_len - len);
		ft_memcpy(ret + (tab->total_len - len), str, len);
	}
	ret[tab->total_len] = '\0';
	return (ret);
}

char	*ft_format_persicion(char *num_str, int perc_len, t_print_tab *tab)
{
	char	*ret;
	int		i;
	char	*tmp;

	if (num_str[0] == '-')
		tab->sign = "-";
	if (ft_strlen(num_str) >= (size_t)perc_len)
	{
		if (ft_strncmp(tab->sign, "+", 1) == 0)
			return (ft_strjoin(tab->sign, num_str));
		return (ft_strdup(num_str));
	}
	ret = (char *)malloc(sizeof(char) * (perc_len + ft_strlen(tab->sign) + 1));
	if (!ret)
		return (NULL);
	i = 0;
	if (ft_strlen(tab->sign))
		ret[i++] = tab->sign[0];
	tmp = ft_format_padding(num_str + ft_strlen(tab->sign), '0', tab);
	ft_memcpy(ret + i, tmp, ft_strlen(tmp));
	ret[perc_len + ft_strlen(tab->sign)] = '\0';
	free(tmp);
	return (ret);
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
