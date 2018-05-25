/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 19:44:05 by jtahirov          #+#    #+#             */
/*   Updated: 2018/05/25 13:34:27 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_dict 	*ft_parse_env(char **environ)
{
	t_dict 	*dict;
	int 	i;
	char 	*delim;

	dict = ft_dict_init(100);
	i = 0;
	while (environ[i])
	{
		delim = ft_strchr(environ[i], '=');
		*delim = '\0';
		ft_dict_insert(dict, environ[i], delim + 1);
		i++;
	}
	return (dict);
}

static void ft_sanitize(char command[MAXINPUT])
{
	char 	*ptr;

	ptr = ft_strchr(command, '\n');
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

	ft_sanitize(command);
	all->words = ft_strsplit(command, ' ');
	func = (t_bfunc *)ft_dict_search(all->shell->builtins, all->words[0]);
	if (!func)
		ft_printf("minishell: comand not found %s\n", all->words[0]);
	else
		func(all);
}