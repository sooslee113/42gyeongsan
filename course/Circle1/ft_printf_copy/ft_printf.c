/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:50:18 by sooslee           #+#    #+#             */
/*   Updated: 2024/03/24 14:52:01 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdarg.h>
// #include <unistd.h>
#include "ftprintf.h"
// #include <stdio.h>
#include "libft/libft.h"

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
		count += ft_puthex(va_arg(**ap, int));
	else if (*(str + 1) == 'X')
		count += ft_puthex2(va_arg(**ap, int));
	else if (*(str + 1) == '%')
		write(1, "%", 1);
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
//  int	main()
//  {
// 	int a = 10;
// 	int *b = &a;
// 	int c = ft_printf("%s", "Hello");
// 	printf("%d" , c);
	// printf("char 확인\n");
	// printf("printf : 123456%c\n", 'c');
	// ft_printf("ft_printfc : 123456%c\n", 'c');
	// printf("%c\n", 'c');
	// ft_printf("%c\n", 'c');
	// printf("printf : 123456%s\n", "sooslee");
	// ft_printf("ft_printfc : 123456%s\n", "sooslee");
	// printf("printf : 123456 %p\n", b);
	// ft_printf("ft_printfc : 123456 %p\n", b);
	// printf("int값 확인\n\n");
	// printf("printf : %d\n", 789);
	// ft_printf("ft_printfc : %d\n", 789);
	// printf("printf : %ld\n", -2147483648);
	// ft_printf("ft_printfc : %d\n", -2147483648);
	// printf("%%i 값 확인\n");
	// printf("printf : %i\n", 789);
	// ft_printf("ft_printfc : %i\n", 789);
	// printf("printf : %li\n", -2147483648);
	// ft_printf("ft_printfc : %i\n", -2147483648);
	// printf("unsigned int 값 확인\n");
	// printf("printf : %lu\n", 4294967295);
	// ft_printf("ft_printfc : %u\n", 4294967295);
	// printf("printf : %u\n", 123456789);
	// ft_printf("ft_printfc : %u\n", 123456789);
	// printf("printf : 123456%x\n", 123456);
	// ft_printf("ft_printfc : 123456%x\n", 123456);
	// printf("printf : 123456%X\n", 123456);
	// ft_printf("ft_printfc : 123456%X\n", 123456);
	// printf("printf : 123456%%\n");
	// ft_printf("ft_printfc : 123456%%\n");
	// printf("리턴값 확인\n");
	// printf("%%d의 리턴값 확인\n");
	// printf("%d\n", ft_printf("%d\n", 123456789));
	// printf("%d\n", ft_printf("%d\n", -2147483648));
	// printf("%d\n", ft_printf("%d\n", -2147));
	// printf("%d\n", ft_printf("%d\n", 0));
	// printf("%%s의 리턴값 확인\n");
	// printf("%d\n", ft_printf("%s\n", "sooslee"));
	// printf("%%p의 리턴값 확인\n");
	// printf("%d\n", ft_printf("%p\n", b));
	// printf("%%i의 리턴값 확인\n");
	// printf("%d\n", ft_printf("%i\n", 123));
	// printf("%d\n", ft_printf("%i\n", -2147483648));
	// printf("%d\n", ft_printf("%i\n", -2147));
	// printf("%d\n", ft_printf("%i\n", 0));
	// printf("%%u의 리턴값 확인\n");
	// printf("%d\n", ft_printf("%u\n", 123456));
	// printf("%%x의 리턴값 확인\n");
	// printf("%d\n", ft_printf("%x\n", 123456));
	// printf("%%X의 리턴값 확인\n");
	// printf("%d\n", ft_printf("%X\n", 123456));
	// printf("리턴값 확인\n");
	// printf("%d\n", ft_printf("sooslee"));
	// printf("포인터 NULL 값 확인\n");
	// printf("printf : %p\n", NULL);
	// ft_printf("ft_printf : %p\n", NULL);
	// printf("printf : %u\n", 9);
	// ft_printf("ft_printfc : %u\n", 9);
	// printf("%d", ft_printf("%%\n"));
// }
