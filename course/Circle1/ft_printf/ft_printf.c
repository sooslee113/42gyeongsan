/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:50:18 by sooslee           #+#    #+#             */
/*   Updated: 2024/09/19 20:49:32 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdarg.h>
// #include <unistd.h>
#include "ft_printf.h"
//#include <stdio.h>
//#include "libft/libft.h"

int	check_var_type(const char *str, va_list *ap)
{
	int	count;

	count = 0;
	if (*(str + 1) == 'c')
		count += ft_putchar(va_arg(*ap, int));
	else if (*(str + 1) == 's')
		count += ft_putstr(va_arg(*ap, char *));
	else if (*(str + 1) == 'p')
		count += ft_putptr(va_arg(*ap, void *));
	else if (*(str + 1) == 'd' || *(str + 1) == 'i')
		count += ft_putnbr(va_arg(*ap, int));
	else if (*(str + 1) == 'u')
		count += ft_putunsignn(va_arg(*ap, unsigned int));
	else if (*(str + 1) == 'x')
		count += ft_puthex(va_arg(*ap, unsigned int));
	else if (*(str + 1) == 'X')
		count += ft_puthex2(va_arg(*ap, unsigned int));
	else if (*(str + 1) == '%')
		count += write(1, "%", 1);
	return (count);
}

int	vaarg(const char *str, va_list *ap)
{	
	int	count;

	count = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			count += check_var_type(str, ap);
			str ++;
		}
		else
			count += ft_putchar(*str);
		str ++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;

	va_start (ap, format);
	if (format == NULL)
		return (-1);
	return (vaarg(format, &ap));
	va_end(ap);
}

int main()
{
	ft_printf("%s", "hello world");
}
