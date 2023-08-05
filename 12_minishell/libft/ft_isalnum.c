/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:08:59 by arbutnar          #+#    #+#             */
/*   Updated: 2023/03/22 23:09:02 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int ch)
{
	if (ch >= 'A' && ch <= 'Z')
		return (1);
	else if (ch >= 'a' && ch <= 'z')
		return (1);
	else if (ch >= '0' && ch <= '9')
		return (1);
	return (0);
}
