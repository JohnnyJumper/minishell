/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 12:24:43 by jtahirov          #+#    #+#             */
/*   Updated: 2018/05/27 12:26:59 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int 	ft_strclen(char *str, int c)
{
	int		length;

	length = 0;
	while (str[length])
	{
		if (str[length] == c)
			return (length);
		length++;
	}
	return (length);
}
