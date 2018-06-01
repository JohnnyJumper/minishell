/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 18:40:07 by jtahirov          #+#    #+#             */
/*   Updated: 2018/06/01 13:29:59 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void ft_run_shell(t_all *all, int fd)
{
	char 	raw_command[MAXINPUT];
	char 	*sanitized_command;
	int 	ret;

	while (1)
	{
		ft_print_prompt(all->env.ps1);
		ft_bzero(raw_command, MAXINPUT - 1);
		ret = read(fd, raw_command, MAXINPUT - 1);
		raw_command[ret] = '\0';
		sanitized_command = ft_strtrim(raw_command);
		ft_parse_command(sanitized_command, all);
	}
}

int main(int argc, char **argv, char **environ)
{
	t_all 	*all;

	int 	fd;

	if (argc || argv || environ)
		;
	// fd = STDINPUT;
	fd = open("debug.txt", O_RDONLY);
	all = (t_all *)ft_memalloc(sizeof(t_all));
	all->env = ft_get_env(environ);
	all->builtins = ft_initialize_builtins();
	ft_run_shell(all, fd);
	return (0);
}
