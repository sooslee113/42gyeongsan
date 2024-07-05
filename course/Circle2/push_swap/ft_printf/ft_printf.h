/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:47:55 by sooslee           #+#    #+#             */
/*   Updated: 2024/06/12 02:12:30 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putptr(void *ptr);
int	ft_puthex(unsigned int n);
int	ft_puthex2(unsigned int n);
int	ft_putnbr(int n);
int	ft_putunsignn(unsigned int n);
int	ft_putchar(int ch);
int	ft_putstr(char *str);

#endif
