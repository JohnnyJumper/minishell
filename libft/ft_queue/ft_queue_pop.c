/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 13:44:21 by jtahirov          #+#    #+#             */
/*   Updated: 2018/05/20 14:35:00 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"

void	*ft_queue_pop(t_queue *queue)
{
	void			*content;
	t_queue_node	*ptr;

	if (ft_queue_empty(queue))
		return (NULL);
	content = queue->first->content;
	free(queue->first->content);
	ptr = queue->first->next;
	free(queue->first);
	queue->first = ptr;
	return (content);
}
