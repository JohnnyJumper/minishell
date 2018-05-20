/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 14:12:11 by jtahirov          #+#    #+#             */
/*   Updated: 2018/05/20 14:16:29 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dict.h"

void	ft_dict_remove(t_dict *dict, char *key)
{
	unsigned long	index;
	t_dict_item		*iter;
	t_dict_item		*next;

	index = ft_dict_hash(key) % dict->capacity;
	iter = dict->items[index];
	if (strcmp(key, iter->key) == 0)
	{
		dict->items[index] = iter->next;
		free(iter);
		return ;
	}
	while (iter->next)
	{
		if (strcmp(key, iter->next->key) == 0)
		{
			next = iter->next->next;
			free(iter->next);
			iter->next = next;
			return ;
		}
		iter = iter->next;
	}
}
