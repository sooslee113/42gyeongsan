/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:47:55 by sooslee           #+#    #+#             */
/*   Updated: 2024/03/23 15:51:54 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H

# include <limits.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int	ft_printptr(void *ptr);
int	ft_puthex(int n);
int	ft_puthex2(int n);
int	ft_putnbr(int n);
int	ft_putunsignn(unsigned int n);
int	ft_printfc(int ch);
int	ft_putstr2(char *str);

#endif
