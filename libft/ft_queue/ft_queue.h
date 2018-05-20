/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 13:35:49 by jtahirov          #+#    #+#             */
/*   Updated: 2018/05/20 14:37:14 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_QUEUE_H
# define FT_QUEUE_H

# include "../libft.h"

typedef struct	s_queue_node
{
	void				*content;
	struct s_queue_node	*next;
}				t_queue_node;

typedef struct	s_queue
{
	struct s_queue_node	*first;
	struct s_queue_node	*last;
}				t_queue;

t_queue			*ft_queue_init(void);
int				ft_queue_empty(t_queue *queue);
void			*ft_queue_peek(t_queue *queue);
void			ft_queue_push(t_queue *queue, void *data);
void			*ft_queue_pop(t_queue *queue);

#endif
