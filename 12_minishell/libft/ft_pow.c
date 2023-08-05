/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:13:37 by arbutnar          #+#    #+#             */
/*   Updated: 2023/03/22 23:13:40 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_pow(int num, int n)
{
	long	res;

	if (num == 0)
		return (0);
	if (n == 0)
		return (1);
	res = num;
	n--;
	while (n-- > 0)
		res = res * num;
	return (res);
}
