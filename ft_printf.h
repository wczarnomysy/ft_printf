/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wczarnom <wczarnom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 21:38:53 by wczarnom          #+#    #+#             */
/*   Updated: 2026/08/05 17:21:52 by wczarnom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>

int	ft_putstrlen_fd(char *s, int fd);
int	ft_putnbrlen_fd(int n, int fd);
int	ft_putuintlen_fd(unsigned int n, int fd);
int	ft_puthexlen_fd(unsigned long n, int fd, const char *hex_digits);
int	ft_putptr_fd(unsigned long n, int fd, const char *hex_digits);
int	ft_printf(const char *format, ...);

#endif