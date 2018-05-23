/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 21:51:04 by jtahirov          #+#    #+#             */
/*   Updated: 2018/05/22 21:59:46 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dict.h"

static void ft_dict_delete_list(t_dict_item **root)
{
	if (*root)
		return ;
	if ((*root)->next)
		ft_dict_delete_list(&(*root)->next);
	ft_strdel(&(*root)->key);
	free(*root);
	*root = NULL;
} 

void 		ft_dict_free(t_dict **dict)
{
	int 	counter;

	counter = 0;
	while (counter < (*dict)->capacity)
	{
		if ((*dict)->items[counter])
			ft_dict_delete_list(&(*dict)->items[counter]);
		counter++;
	}
	free(*dict);
	*dict = NULL;
}