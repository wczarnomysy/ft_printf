/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wczarnom <wczarnom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 19:36:56 by wczarnom          #+#    #+#             */
/*   Updated: 2026/06/28 21:40:50 by wczarnom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest1;
	const unsigned char	*src1;

	if (!dest && !src)
		return (NULL);
	dest1 = (unsigned char *)dest;
	src1 = (const unsigned char *)src;
	if (src1 < dest1)
	{
		while (n--)
			dest1[n] = src1[n];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			dest1[i] = src1[i];
			i++;
		}
	}
	return (dest);
}
