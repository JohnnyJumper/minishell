/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 14:03:04 by jtahirov          #+#    #+#             */
/*   Updated: 2018/05/20 14:21:19 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dict.h"

void	*ft_dict_search(t_dict *dict, char *key)
{
	unsigned long	index;
	t_dict_item		*iter;

	index = ft_dict_hash(key) % dict->capacity;
	iter = dict->items[index];
	while (iter)
	{
		if (strcmp(key, iter->key) == 0)
			return (iter->value);
		iter = iter->next;
	}
	return (NULL);
}
