/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:50:18 by sooslee           #+#    #+#             */
/*   Updated: 2024/03/26 18:48:06 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdarg.h>
// #include <unistd.h>
#include "ft_printf.h"
//#include <stdio.h>
//#include "libft/libft.h"

int	check_var_type(const char *str, va_list **ap)
{
	int	count;

	count = 0;
	if (*(str + 1) == 'c')
		count += ft_printfc(va_arg(**ap, int));
	else if (*(str + 1) == 's')
		count += ft_putstr2(va_arg(**ap, char *));
	else if (*(str + 1) == 'p')
		count += ft_printptr(va_arg(**ap, void *));
	else if (*(str + 1) == 'd' || *(str + 1) == 'i')
		count += ft_putnbr(va_arg(**ap, int));
	else if (*(str + 1) == 'u')
		count += ft_putunsignn(va_arg(**ap, unsigned int));
	else if (*(str + 1) == 'x')
		count += ft_puthex(va_arg(**ap, unsigned int));
	else if (*(str + 1) == 'X')
		count += ft_puthex2(va_arg(**ap, unsigned int));
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
			count += check_var_type(str, &ap);
			str ++;
		}
		else
			count += ft_printfc(*str);
		str ++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;

	va_start (ap, format);
	return (vaarg(format, &ap));
	va_end(ap);
}
/* int	main()
 {
		char *a = 0;
	char c = 'a';
	char b[10] = "helloworld";
	printf("i:%d\n", printf("d:%d\n", -2147483647));
	printf("i:%d\n", printf("d:%d\n", 0));
	printf("i:%d\n", printf("d:%d\n", 2147483647));
	printf("i:%d\n", printf("i:%i\n", -2147483647));
	printf("i:%d\n", printf("i:%i\n", 0));
	printf("i:%d\n", printf("i:%i\n", 2147483647));
	printf("i:%d\n", printf("u:%u\n", 0));
	printf("i:%d\n", printf("u:%u\n", 2147483647));
	printf("i:%d\n", printf("s:%s\n", a));
	printf("i:%d\n", printf("s:%s\n", b));
	printf("i:%d\n", printf("c:%c\n", 'a'));
	printf("i:%d\n", printf("c:%c\n", 0));
	printf("i:%d\n", printf("x:%x\n", 0));
	printf("i:%d\n", printf("x:%x\n", -2));
	printf("i:%d\n", printf("x:%x\n", 2147483647));
	printf("i:%d\n", printf("X:%X\n", 0));
	printf("i:%d\n", printf("X:%X\n", -2147483647));
	printf("i:%d\n", printf("X:%X\n", 2147483647));
	printf("i:%d\n", printf("%%\n"));
	printf("i:%d\n", printf("%p\n", a));
	printf("i:%d\n", printf("%p\n", b));
	printf("i:%d\n", printf("%p\n", &c));
	printf("i:%d\n", printf("asds%%%d123%i1123%s132%%\n\n", 0, 2147483647, b));
	printf("----------------\n\n");
printf("i:%d\n", printf("d:%d\n", -2147483647));
	ft_printf("i:%d\n", ft_printf("d:%d\n", 0));
	ft_printf("i:%d\n", ft_printf("d:%d\n", 2147483647));
	ft_printf("i:%d\n", ft_printf("i:%i\n", -2147483647));
	ft_printf("i:%d\n", ft_printf("i:%i\n", 0));
	ft_printf("i:%d\n", ft_printf("i:%i\n", 2147483647));
	ft_printf("i:%d\n", ft_printf("u:%u\n", 0));
	ft_printf("i:%d\n", ft_printf("u:%u\n", 2147483647));
	ft_printf("i:%d\n", ft_printf("s:%s\n", a));
	ft_printf("i:%d\n", ft_printf("s:%s\n", b));
	ft_printf("i:%d\n", ft_printf("c:%c\n", 'a'));
	ft_printf("i:%d\n", ft_printf("c:%c\n", 0));
	ft_printf("i:%d\n", ft_printf("x:%x\n", 0));
	ft_printf("i:%d\n", ft_printf("x:%x\n", -2));
	ft_printf("i:%d\n", ft_printf("x:%x\n", 2147483647));
	ft_printf("i:%d\n", ft_printf("X:%X\n", 0));
	ft_printf("i:%d\n", ft_printf("X:%X\n", -2));
	ft_printf("i:%d\n", ft_printf("X:%X\n", 2147483647));
	ft_printf("i:%d\n", ft_printf("%%\n"));
	ft_printf("i:%d\n", ft_printf("%p\n", a));
	ft_printf("i:%d\n", ft_printf("%p\n", b));
	ft_printf("i:%d\n", ft_printf("%p\n", &c));
	ft_printf("i:%d\n", ft_printf("asds%%%d123%i1123%s132%%\n\n", 0, 2147483647, b));

	printf("\n\n");

 }*/
