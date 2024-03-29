/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:16:30 by arbutnar          #+#    #+#             */
/*   Updated: 2023/03/22 23:16:31 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	l;
	char	*str;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	l = ft_strlen(s);
	i = 0;
	str = (char *) malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len && s[start] && start < (size_t)l)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}
