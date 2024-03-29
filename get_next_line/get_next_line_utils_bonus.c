/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 23:29:16 by arbutnar          #+#    #+#             */
/*   Updated: 2022/02/13 23:31:33 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(char *save)
{
	size_t	i;

	if (!save)
		return (NULL);
	i = 0;
	while (save[i])
	{
		if (save[i] == '\n')
			return (save + i);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 && (!s2 || !*s2))
		return (NULL);
	i = 0;
	if (s1)
		while (s1[i])
			i++;
	j = 0;
	while (s2[j])
		j++;
	str = (char *)malloc(sizeof(char) * i + j + 1);
	if (!str)
		return (NULL);
	str[i + j] = '\0';
	while (--j >= 0)
		str[i + j] = s2[j];
	while (--i >= 0)
		str[i] = s1[i];
	free(s1);
	return (str);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}
