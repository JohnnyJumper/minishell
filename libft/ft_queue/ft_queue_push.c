/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 13:40:56 by jtahirov          #+#    #+#             */
/*   Updated: 2018/05/20 14:34:52 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"

void	ft_queue_push(t_queue *queue, void *data)
{
	t_queue_node	*fresh;

	fresh = (t_queue_node *)malloc(sizeof(t_queue_node));
	fresh->next = NULL;
	fresh->content = data;
	if (ft_queue_empty(queue))
	{
		queue->first = fresh;
		queue->last = fresh;
		return ;
	}
	queue->last->next = fresh;
	queue->last = fresh;
}
