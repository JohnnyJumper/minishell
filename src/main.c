/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 18:40:07 by jtahirov          #+#    #+#             */
/*   Updated: 2018/05/22 21:01:02 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void ft_run_shell(t_shell *shell, int fd)
{
	char 	command[MAXINPUT];
	int 	ret;

	while (1)
	{
		ft_print_dir(ft_dict_search(shell->env, "PS1"));
		ft_bzero(command, MAXINPUT - 1);
		ret = read(fd, command, MAXINPUT - 1);
		command[ret] = '\0';
		ft_parse_command(command, shell);
	}
}

int main(int argc, char **argv, char **environ)
{
	t_shell		*shell;

	int 	fd;

	if (argc || argv || environ)
		;
	fd = STDINPUT;
	shell = ft_init_variables(environ);
	ft_run_shell(shell, fd);
	return (0);
}
