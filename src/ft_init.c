/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 20:55:00 by jtahirov          #+#    #+#             */
/*   Updated: 2018/05/27 11:54:52 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_dict 	*ft_initialize_builtins()
{
	t_dict 	*builtins;

	builtins = ft_dict_init(32);
	ft_dict_insert(builtins, "pwd", &ft_pwd);
	ft_dict_insert(builtins, "cd", &ft_cd);
	ft_dict_insert(builtins, "echo", &ft_echo);
	ft_dict_insert(builtins, "env", &ft_env);
	ft_dict_insert(builtins, "export", &ft_export);
	ft_dict_insert(builtins, "setenv", &ft_export);
	ft_dict_insert(builtins, "unsetenv", &ft_unsetenv);
	ft_dict_insert(builtins, "exit", &ft_exit);
	ft_dict_insert(builtins, "help", &ft_help);
	return (builtins);
}
