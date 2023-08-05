/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:42:43 by arbutnar          #+#    #+#             */
/*   Updated: 2023/03/22 22:42:43 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../global.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

int	env(t_command *cmd)
{
	int		i;

	i = 0;
	while (cmd->shell->env[i])
	{
		if (!(ft_strchr_len(cmd->shell->env[i], '=') == -1))
			ft_putendl_fd(cmd->shell->env[i], 1);
		i++;
	}
	return (0);
}
