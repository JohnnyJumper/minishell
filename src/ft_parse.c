/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 19:44:05 by jtahirov          #+#    #+#             */
/*   Updated: 2018/06/01 12:53:51 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_env 	ft_get_env(char **environ)
{
	t_env	fresh;

	ft_bzero(&fresh, sizeof(t_env));
	fresh.env = ft_parse_env(environ, &fresh);
	return (fresh);
}

char 	**ft_parse_env(char **environ, t_env *env)
{
	char 	**env_copy;
	int 	counter;

	counter = -1;
	env_copy = environ;
	env->length = 0;
	while (environ[env->length++]);
	env_copy = (char **)ft_memalloc(sizeof(char *) * env->length);
	while (environ[++counter])
	{
		env_copy[counter] = ft_strdup(environ[counter]);
		if (!(ft_strncmp(environ[counter],"PATH", 4)))
			env->path = &env_copy[counter][5];
		if (!(ft_strncmp(environ[counter], "PS1", 3)))
			env->ps1 = &env_copy[counter][4];
		if (!(ft_strncmp(environ[counter], "HOME", 4)))
			env->home = &env_copy[counter][5];
		if (!(ft_strncmp(environ[counter], "PWD", 3)))
			env->pwd = &env_copy[counter][4];
	}
	return (env_copy);
}

static void ft_sanitize(char command[MAXINPUT])
{
	char 	*ptr;

	ptr = ft_strchr(command, '\n');
	if (ptr)
		*ptr = '\0';
	ptr = command;
	while(*ptr)
	{

		if (*ptr == '\t')
			*ptr = ' ';
		ptr++;
	}
}

void 	ft_parse_command(char command[MAXINPUT], t_all *all)
{
	t_bfunc 	*func;

	if (!command[0])
		return ;
	ft_sanitize(command);
	all->words = ft_split_arg(command);
	ft_printf("comands I got\n");
	ft_print2d(all->words);
	ft_printf("end of my comands\n");
	func = (t_bfunc *)ft_dict_search(all->builtins, all->words[0]);
	if (!func)
	{
		if ((ft_check_in_path(all)))
			return ;
		else
			ft_printf("minishell: comand not found %s\n", all->words[0]);
	}
	else
		func(all);
}