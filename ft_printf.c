/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wczarnom <wczarnom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 18:10:25 by wczarnom          #+#    #+#             */
/*   Updated: 2026/08/05 20:33:01 by wczarnom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	conversion_specifiers(char specifier, va_list list)
{
	if (specifier == 'c')
		return (ft_putchar_fd((char)(va_arg(list, int)), 1), 1);
	if (specifier == 's')
		return (ft_putstrlen_fd(va_arg(list, char *), 1));
	if (specifier == 'p')
		return (ft_putptr_fd((unsigned long)va_arg(list, void *), 1,
				HEX_LOWER));
	if (specifier == 'd' || specifier == 'i')
		return (ft_putnbrlen_fd(va_arg(list, int), 1));
	if (specifier == 'u')
		return (ft_putuintlen_fd(va_arg(list, unsigned int), 1));
	if (specifier == 'x')
		return (ft_puthexlen_fd((unsigned long)(va_arg(list, unsigned int)), 1,
			HEX_LOWER));
	if (specifier == 'X')
		return (ft_puthexlen_fd((unsigned long)(va_arg(list, unsigned int)), 1,
			HEX_UPPER));
	if (specifier == '%')
		return (ft_putchar_fd('%', 1), 1);
	return (0);
}

static int	is_specifier(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%');
}

static int	manage_arguments(const char *format, va_list list, int result)
{
	int	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			if (is_specifier(format[i + 1]))
				result += conversion_specifiers(format[++i], list);
			else
			{
				ft_putchar_fd('%', 1);
				result += 1;
			}
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			result++;
		}
		i++;
	}
	return (result);
}

int	ft_printf(const char *format, ...)
{
	int		result;
	va_list	list;

	result = 0;
	if (!format)
	{
		return (-1);
	}
	va_start(list, format);
	result = manage_arguments(format, list, result);
	va_end(list);
	return (result);
}
