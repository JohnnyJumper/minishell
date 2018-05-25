/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_replace_value.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 13:16:37 by jtahirov          #+#    #+#             */
/*   Updated: 2018/05/25 13:24:30 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dict.h"

void 	ft_dict_replace_value(t_dict *dict, char *key, void *new_value)
{
	unsigned long 	index;
	t_dict_item 	*iter;

	index = ft_dict_hash(key) % dict->capacity;
	if (dict->items[index])
	{
		iter = dict->items[index];
		while (iter && ft_strcmp(key, iter->key) != 0)
			iter = iter->next;
		if (!iter)
			return ;
		iter->value = new_value;
	}
}