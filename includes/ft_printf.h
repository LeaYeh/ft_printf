/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:38:10 by lyeh              #+#    #+#             */
/*   Updated: 2023/09/19 22:16:54 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "ft_boolean.h"
# include "ft_utils.h"
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
	t_bool	f_hash;
	t_bool	f_perc_fmt;
	t_bool	f_perc_shink;
	t_bool	f_pointer;
}	t_print_tab;

/* ft_printf */
int		ft_printf(const char *format, ...);
char	*ft_eval_format(t_print_tab *tab);
char	*ft_format_char(char c, t_print_tab *tab);
char	*ft_format_string(char *s, t_print_tab *tab);
char	*ft_format_int(int n, t_print_tab *tab);
char	*ft_format_uint(unsigned int n, t_print_tab *tab);
char	*ft_format_hex(unsigned int n, t_bool is_upper, t_print_tab *tab);
char	*ft_format_addr(unsigned long int n, t_print_tab *tab);

/* ft_print_utils */
void	ft_init_print_table(t_print_tab *tab);
void	ft_print_table_status(t_print_tab *tab);

/* ft_flags_bonus */
void	ft_setup_print_table(const char *fmt, int start, t_print_tab *tab);
char	*ft_format_padding(
			char *str, char pad, t_print_tab *tab, t_bool is_perc);
char	*ft_format_persicion(char *num_str, t_print_tab *tab);
char	*ft_format_suffix(char *s, t_bool is_upper, t_print_tab *tab);

char	*ft_handle_null(t_print_tab *tab);

#endif