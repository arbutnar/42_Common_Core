/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:06:10 by arbutnar          #+#    #+#             */
/*   Updated: 2023/05/02 14:36:57 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	a;

	if (needle == NULL || *needle == '\0')
		return ((char *) haystack);
	a = 0;
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		while (haystack[i] != *needle && haystack[i] != '\0' && i < len)
			i++;
		j = 0;
		while (haystack[i] == needle[j] && needle[j] != '\0' && i < len)
		{
			i++;
			j++;
		}
		a++;
		if (needle[j] == '\0')
			return ((char *) haystack + i - j);
		i = a;
	}
	return (NULL);
}
