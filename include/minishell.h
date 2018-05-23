/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 19:38:01 by jtahirov          #+#    #+#             */
/*   Updated: 2018/05/22 21:01:01 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# define MAXINPUT 1024
# define STDINPUT 0
# define STDOUT 1
# define STDERR 2

typedef void *(*t_builtin_func(t_dict *env));

typedef struct 	s_ft_shell
{
	t_dict 	*env;
	t_dict 	*builtins;
}				t_shell;

union 	u_ft_shell
{
	t_shell 	shell;
	t_dict 		*iter_shell[2];
};

enum 	shell{env, buildins};


void 	ft_print_dir(char *prompt);
void 	ft_run_shell(t_shell *shell, int fd);
void 	ft_parse_command(char command[MAXINPUT], t_shell *shell);


t_shell *ft_init_variables(char **environ);	
t_dict 	*ft_parse_env(char **environ);
t_dict 	*ft_initialize_builtins(void);


void 	*ft_pwd(t_dict *env);

#endif