/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 14:12:11 by jtahirov          #+#    #+#             */
/*   Updated: 2018/05/20 19:57:09 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dict.h"

static void ft_dict_item_free(t_dict_item **item)
{
	free((*item)->value);
	free((*item)->key);
	free((*item));
	*item = NULL;
}

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
		ft_dict_item_free(&iter);
		return ;
	}
	while (iter->next)
	{
		if (strcmp(key, iter->next->key) == 0)
		{
			next = iter->next->next;
			ft_dict_item_free(&iter->next);
			iter->next = next;
			return ;
		}
		iter = iter->next;
	}
}
