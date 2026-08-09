/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wczarnom <wczarnom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 16:33:46 by wczarnom          #+#    #+#             */
/*   Updated: 2026/08/05 16:44:57 by wczarnom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstrlen_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(fd, NULL_STR, 6);
		return (6);
	}
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbrlen_fd(int n, int fd)
{
	char	c;
	long	nbr;
	int		len;

	len = 0;
	nbr = n;
	if (nbr < 0)
	{
		write(fd, "-", 1);
		len++;
		nbr = -nbr;
	}
	if (nbr > 9)
		len += ft_putnbrlen_fd(nbr / 10, fd);
	c = nbr % 10 + '0';
	write(fd, &c, 1);
	len++;
	return (len);
}

int	ft_putuintlen_fd(unsigned int n, int fd)
{
	char	c;
	int		len;

	len = 0;
	if (n > 9)
		len += ft_putuintlen_fd(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
	len++;
	return (len);
}

int	ft_puthexlen_fd(unsigned long n, int fd, const char *hex_digits)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_puthexlen_fd(n / 16, fd, hex_digits);
	write(fd, &hex_digits[n % 16], 1);
	len++;
	return (len);
}

int	ft_putptr_fd(unsigned long n, int fd, const char *hex_digits)
{
	if (!n)
	{
		write(fd, NIL_STR, 5);
		return (5);
	}
	write(fd, "0x", 2);
	return (2 + ft_puthexlen_fd(n, fd, hex_digits));
}
