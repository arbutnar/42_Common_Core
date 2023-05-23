/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:25:18 by arbutnar          #+#    #+#             */
/*   Updated: 2023/03/22 23:25:20 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *des, const void *src, size_t n)
{
	size_t	i;

	if (des == src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(char *)(des + i) = *(const char *)(src + i);
		i++;
	}
	return (des);
}
