/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:45:09 by lyeh              #+#    #+#             */
/*   Updated: 2023/09/18 13:00:30 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H
# include "ft_boolean.h"
# include <unistd.h>

int				ft_in_substr(const char c, const char *sub);
int				ft_max(int a, int b);
int				ft_min(int a, int b);
char			*ft_utoa(unsigned long long_n);
char			*ft_utox(unsigned long int nbr, t_bool in_upper);
long long int	ft_pow(int base, int n);

#endif