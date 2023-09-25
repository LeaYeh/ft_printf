/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:45:09 by lyeh              #+#    #+#             */
/*   Updated: 2023/09/25 16:58:54 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H
# include <stdarg.h>
# include <limits.h>
# include <stdlib.h>
# include "ft_boolean.h"

int				ft_in_substr(const char c, const char *sub);
int				ft_max(int count, ...);
int				ft_min(int count, ...);
char			*ft_utoa(unsigned long long_n);
char			*ft_utox(unsigned long int nbr, t_bool in_upper);
long long int	ft_pow(int base, int n);

#endif