/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:12:08 by lyeh              #+#    #+#             */
/*   Updated: 2023/09/25 17:12:13 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include "ft_boolean.h"
# include "ft_utils.h"
# include "libft.h"

int	ft_printf(const char *format, ...);
int	ft_print_string(char *s);
int	ft_print_char(char c);
int	ft_print_int(int n);
int	ft_print_uint(unsigned int n);
int	ft_print_addr(unsigned long int n);
int	ft_print_hex(unsigned int n, t_bool is_upper);

#endif