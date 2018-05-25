/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 19:38:01 by jtahirov          #+#    #+#             */
/*   Updated: 2018/05/25 13:40:42 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# define MAXINPUT 1024
# define STDINPUT 0
# define STDOUT 1
# define STDERR 2

typedef struct 	s_ft_shell
{
	t_dict 	*env;
	t_dict 	*builtins;
}				t_shell;

typedef struct 	s_ft_all
{
	t_shell 	*shell;
	char 		**words;
}				t_all;

typedef union 	u_ft_shell
{
	t_shell 	shell;
	t_dict 		*iter_shell[2];
}				iter_shell;

enum 	shell{env, buildins};
typedef void (*t_bfunc(t_all *all));

void 	ft_print_dir(char *prompt);
void 	ft_words_free(char **words);
void 	ft_free_all(t_all **all);

void 	ft_run_shell(t_all *all, int fd);
void 	ft_parse_command(char command[MAXINPUT], t_all *all);


t_shell *ft_init_variables(char **environ);	
t_dict 	*ft_parse_env(char **environ);
t_dict 	*ft_initialize_builtins(void);


void 	ft_pwd(t_all *all);
void 	ft_cd(t_all *all);
void 	ft_echo(t_all *all);
void 	ft_env(t_all *all);
void 	ft_export(t_all *all);
void 	ft_unsetenv(t_all *all);
void 	ft_exit(t_all *all);
void 	ft_help(t_all *all);
#endif