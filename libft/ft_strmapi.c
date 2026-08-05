/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wczarnom <wczarnom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 20:21:23 by wczarnom          #+#    #+#             */
/*   Updated: 2026/06/04 20:21:49 by wczarnom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*word;

	i = 0;
	if (!s || !f)
		return (NULL);
	word = malloc(ft_strlen(s) + 1);
	if (!word)
		return (NULL);
	while (s[i] != '\0')
	{
		word[i] = f(i, s[i]);
		i++;
	}
	word[i] = '\0';
	return (word);
}
