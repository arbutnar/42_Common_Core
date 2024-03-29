/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:14:25 by arbutnar          #+#    #+#             */
/*   Updated: 2023/03/22 23:14:27 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(long num)
{
	int	res;
	int	n;

	n = 0;
	while (n < MAXINT || n > num / 2)
	{
		res = ft_pow(n, 2);
		if (res == num)
			return (res);
		else if (res > num)
			return (-1);
		n++;
	}
	return (-1);
}
