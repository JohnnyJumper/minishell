/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitargs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 16:36:14 by jtahirov          #+#    #+#             */
/*   Updated: 2018/06/01 13:09:18 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int ft_calculate_len(char *comand)
{
	int len;
	char quote;

	len = 0;
	while (*comand)
	{
		if (*comand == '\"' || *comand == '\'')
		{
			quote = *comand++;
			comand = ft_strchr(comand, quote);
			if (!comand)
				return (-1);
			len++;
		}
		else if (NOT_SPACE(*comand) &&
				 ((*(comand + 1) == ' ') || *(comand + 1) == '\0'))
			len++;
		comand++;
	}
	return (len);
}

static void ft_quote_parser(char **args, int *i, char **comand)
{
	char 	quote;
	char 	*end;

	quote = **comand;
	*comand += 1;
	end = ft_strchr(*comand, quote);
	*end = '\0';
	args[(*i)++] = ft_strdup(*comand);
	*end = quote;
	*comand = end + 1;
	if (**comand == ' ')
		(*comand) += 1;
}

char **ft_split_arg(char *comand)
{
	char **args;
	char *end;
	int len;
	int i;

	len = ft_calculate_len(comand);
	if (len == -1)
		return (NULL);
	args = (char **)ft_memalloc(sizeof(char *) * len + 1);
	i = 0;
	while (*comand)
	{
		if (*comand == '\"' || *comand == '\'')
		{
			ft_quote_parser(args, &i, &comand);
			continue;
		}
		end = ft_strchr(comand, ' ');
		if (end && SEP(end))
		{
			*end = '\0';
			args[i++] = ft_strdup(comand);
			*end = ' ';
			comand = end + 1;
			continue ;
		}
		else if (*comand)
		{
			args[i++] = ft_strdup(comand);
			return (args);
		}
		comand++;
	}
	return (args);
}