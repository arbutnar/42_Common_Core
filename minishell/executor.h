/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:49:39 by arbutnar          #+#    #+#             */
/*   Updated: 2023/03/22 23:49:40 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "./global.h"

// executor.c
void	ft_execv(t_command *cmd, int *status);
void	ft_executor(t_command *parser);

// execute_process.c
void	execute_process(t_minishell *shell, char *path, char **args);

// ft_execv.c
char	*ft_append(char *path, t_command *cmd);
char	**ft_getpath(t_command *cmd);
void	ft_fixcommand(t_command *cmd);
char	*ft_findpath(t_command *cmd, int i);

// pipe.c
void	ft_pipe(t_command *cmd, int std_cpy[2], pid_t pid, int i);
void	ft_child(t_command *cmd, int **fd, int *i, int std_cpy[2]);
void	ft_wait(int i, int *stdin_cpy, int *stdout_cpy);

// redir.c
void	ft_redin(t_command *cmd, int *stdin_cpy);
void	ft_redout(t_command *cmd, int *stdin_cpy, int *stdout_cpy);
void	ft_redappend(t_command *cmd, int *stdout_cpy);
void	ft_heredoc(t_command *cmd, int *stdin_cpy);

// redirpipe.c
int		ft_redir(t_command *cmd, int *stdin_cpy, int *stdout_cpy);
void	ft_redirpipe(t_command *cmd, int *stdin_cpy, int *stdout_cpy);
void	ft_chooseredir(t_command *cmd, int *stdin_cpy, int *stdout_cpy);

#endif
