/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:19:47 by arbutnar          #+#    #+#             */
/*   Updated: 2023/03/22 23:19:48 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	ps_move_to_next_char(t_command *cmd)
{
	while (cmd->str[0] && ft_isspace(cmd->str[0]))
		cmd->str++;
}
