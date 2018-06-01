/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 19:38:01 by jtahirov          #+#    #+#             */
/*   Updated: 2018/06/01 13:03:41 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# define MAXINPUT 1024
# define STDINPUT 0
# define STDOUT 1
# define STDERR 2

# define SEP(x) ((x - 1) && (*(x - 1) != ' '))
# define NOT_SPACE(x) (x != ' ' && x != '\t')

typedef struct	s_env
{
	char	**env;
	int	 	length;
	char 	*path;
	char	*ps1;
	char 	*home;
	char 	*pwd;
}				t_env;

typedef struct 	s_ft_all
{
	t_dict 		*builtins;
	t_env 		env;
	char 		**words;
	
}				t_all;

typedef void (*t_bfunc(t_all *all));

void	 	ft_print_prompt(char *prompt);
void	 	ft_words_free(char **words);
void 		ft_env_add(t_all *all, char *toadd);
void	 	ft_free_all(t_all **all);

void 		ft_run_shell(t_all *all, int fd);
char 		**ft_split_arg(char *comand);
void 		ft_parse_command(char command[MAXINPUT], t_all *all);
int	 		ft_check_in_path(t_all *all);
int 		ft_execute(char *path, char **args, char **env);


char  		**ft_parse_env(char **environ, t_env *env);
t_dict 		*ft_initialize_builtins(void);
t_env 		ft_get_env(char **environ);

void 		ft_pwd(t_all *all);
void 		ft_cd(t_all *all);
void 		ft_echo(t_all *all);
void 		ft_env(t_all *all);
void 		ft_export(t_all *all);
void 		ft_unsetenv(t_all *all);
void 		ft_exit(t_all *all);
void 		ft_help(t_all *all);

#endif