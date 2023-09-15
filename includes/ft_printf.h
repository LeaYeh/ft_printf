/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:38:10 by lyeh              #+#    #+#             */
/*   Updated: 2023/09/15 18:31:28 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "ft_boolean.h"
# include "libft.h"

typedef struct s_print_tab
{
	va_list	args;
	int		width;
	int		perc_len;
	int		total_len;
	int		fmt_len;
	char	*sign;
	char	type;
	t_bool	f_zero_pad;
	t_bool	f_space_pad;
	t_bool	f_dash;
	t_bool	f_perc_fmt;
	t_bool	f_perc_arg;
	t_bool	f_pointer;
	t_bool	f_hex_suffix;
}	t_print_tab;

/* ft_printf */
int		ft_printf(const char *format, ...);
char	*ft_eval_format(const char *fmt, int i, t_print_tab *tab);
char	*ft_format_char(char c, t_print_tab *tab);
char	*ft_format_string(char *s, t_print_tab *tab);
char	*ft_format_decimal(int n, t_print_tab *tab);

/* ft_print_utils */
void	ft_init_print_table(t_print_tab *tab);
void	ft_print_table_status(t_print_tab *tab);

/* ft_flags_bonus */
void	ft_setup_print_table(const char *fmt, int start, t_print_tab *tab);
char	*ft_format_padding(char *str, char pad, int total_len, t_bool on_right);
char	*ft_format_persicion(char *num_str, int perc_len, t_print_tab *tab);

/* utils */
int		ft_in_substr(const char c, const char *sub);
int		ft_max(int a, int b);

#endif