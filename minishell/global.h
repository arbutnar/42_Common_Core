/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardett <mbardett@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:20:10 by mbardett          #+#    #+#             */
/*   Updated: 2023/03/22 23:20:11 by mbardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

# include "./libft/libft.h"

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <dirent.h>
# include <termios.h>
# include <sys/wait.h>
# include <sys/ioctl.h>
# include <sys/param.h>
# include <sys/types.h>
# include <errno.h>
# include <sys/types.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

# define CYEL "\e[0;33m"
# define CGRN "\e[0;32m"
# define CBRED "\e[1;31m"
# define CBGRN "\e[1;32m"
# define CBYEL "\e[1;33m"
# define CWHITE "\e[0m"

# define _POSIX_C_SOURCE 200809L

# define SUCCESS 0
# define FAIL 1

// Operator presence
# define PIPE 0
# define SQUOTE 1
# define DQUOTE 2
# define MQUOTE 3
# define REDIN 4
# define REDOUT 5
# define REDAPP 6
# define HERDOC 7
# define CASH 8
# define TILDE 9
# define NOCMD 10
# define EMPTY -1

// Errors
# define ERR_DIR 126
# define ERR_UNK 127

# define PROMPT ":"

extern void	rl_replace_line(const char *text, int clear_undo);

typedef struct s_minishell
{
	char				**env;

	char				*input;
	struct s_command	*current_cmd;

	int					exit_status;
	int					mc_pipes;
	int					mc_quotes;
	int					mc_wquotes;

}				t_minishell;

typedef struct s_command
{
	char				*str;
	char				**tokens;
	int					spc[11];

	char				*command;
	char				**arguments;
	int					args_number;

	int					*red_type;
	char				**red;
	int					red_error;

	struct s_command	*next;
	struct s_command	*prev;

	t_minishell			*shell;
}	t_command;

// builtins
int			redirector(t_command *cmd);
int			unset(t_command *cmd);
int			cd(t_command *cmd);
int			echo(t_command *cmd);
int			env(t_command *cmd);
int			ms_exit(t_command *cmd);
int			pwd(void);
int			ft_strchr_len(char *str, char c);

// expander/expander.c
void		expander(t_command *cmd);

// expander/expander_utils.c
char		*exp_tkn(char *str, char **env);

// expander/expander_utils.c
char		**ft_arrdup(char **arr);

// main/init.c
void		init_shell(t_minishell *shell, char **env);
t_command	*init_command(t_minishell *shell);
void		set_ecode(int code);
void		control_c_signal(int sig);

// main/free_structs.c
void		free_commands(t_minishell *shell);
void		free_shell(t_minishell *shell);

// parser.c
int			parser(t_minishell *sh);

// lexer/lexer.c
int			lexer_init(t_minishell *shell);

// lexer/lexer_splitter.c
char		*split_operator(char *line, int *ff, int not_new);
char		*split_line(char *line);

//expander.c
void		free_arr(char **split_arr);
char		**ft_arrdup(char **arr);
char		*exp_tkn(char *str, char **env);

//signals.c
//void	ft_suppress_output(void);
void		ft_sigs_handler(int sig);
void		control_slash(int sig);

//export.c
char		**exp_(t_minishell shell);

//export_utils.c
void		print_env_vars(char *env_cpy);
int			ft_strcmp_better(const char *s1, const char *s2);

// int		alpha_cmp(char *str1, char *str2);
void		alpha_sort(char **mtrx);
char		**export_aux(char **key_value, char **env_cpy);
int			ft_export(char **key_value, t_minishell *shell);

// export.c export2.c export3.c
void		add_string_to_env(t_minishell *shell, char *str, char **env);
void		val_env_part_2(int *exist, char **str, char *arg);
int			export_compare_values(char *entry, char *arg);
char		**insert_values_env(char **args, char **env);
int			export_check_argument(char *str);

// main/prompt.c
char		*our_prompt(t_minishell *shell, char *str);

#endif
