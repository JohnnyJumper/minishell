/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 19:44:05 by jtahirov          #+#    #+#             */
/*   Updated: 2018/05/22 21:01:45 by jtahirov         ###   ########.fr       */
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
	ft_printf("This is env\n\n");
	while (environ[i])
	{
		ft_printf("%s\n", environ[i]);
		delim = ft_strchr(environ[i], '=');
		*delim = '\0';
		ft_dict_insert(dict, environ[i], delim + 1);
		i++;
	}
	ft_printf("-------------\n");
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

void 	ft_parse_command(char command[MAXINPUT], t_shell *shell)
{
	char 			**words;
	t_builtin_func 	*func;

	ft_sanitize(command);
	words = ft_strsplit(command, ' ');
	func = (t_builtin_func *)ft_dict_search(shell->builtins, words[0]);
	func(shell->env);	
}