/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_pad_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:09:13 by lyeh              #+#    #+#             */
/*   Updated: 2023/09/25 17:08:04 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_pad_on_right(char *str, char pad, char type, int total_len)
{
	char	*ret;
	int		len;
	int		i;

	ret = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!ret || !str)
		return (NULL);
	len = ft_strlen(str);
	if (type == 'c')
		len = ft_max(2, 1, ft_strlen(str));
	i = 0;
	ft_memcpy(ret, str, len);
	while (i < len)
	{
		if (str[i])
			ret[i] = str[i];
		i++;
	}
	while (i < total_len)
	{
		ret[i] = pad;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_pad_on_left(char *str, char pad, char type, int total_len)
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
	if (type == 'c')
		len = ft_max(2, 1, ft_strlen(str + i));
	ft_memset(ret + i, (int)pad, total_len - len - i);
	ft_memcpy(ret + (total_len - len), str + i, len);
	ret[total_len] = '\0';
	return (ret);
}

int	ft_get_shink_len(char *context, t_print_tab *tab)
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

int	ft_get_len_after_padding(char *context, t_print_tab *tab, t_bool is_perc)
{
	int	len;

	if (ft_strncmp(context, "(null)", 6) == 0 && tab->f_perc_shink)
		len = ft_strlen(context);
	else if (tab->f_perc_shink && \
		(is_perc || (tab->type == 's' && tab->perc_len && !tab->width)))
		len = ft_get_shink_len(context, tab);
	else if (is_perc)
		len = tab->perc_len;
	else if (tab->f_space_pad && tab->type != 's' && !ft_strlen(tab->sign))
		len = ft_max(2, tab->width, 1 + ft_strlen(context));
	else
		len = tab->width;
	return (len);
}

t_bool	ft_is_pad_on_left(t_print_tab *tab, t_bool is_perc)
{
	if (tab->type == 'p' && !tab->f_dash)
		return (TRUE);
	else if (tab->type == 'p' && tab->f_dash)
		return (FALSE);
	if (!is_perc && (tab->f_dash || tab->f_hash))
		return (FALSE);
	if ((tab->type == 'd' || tab->type == 'i') && ft_strlen(tab->sign))
		return (TRUE);
	return (TRUE);
}
