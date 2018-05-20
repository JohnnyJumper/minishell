/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 13:51:45 by jtahirov          #+#    #+#             */
/*   Updated: 2018/05/20 14:28:02 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DICT_H
# define FT_DICT_H

# include "../libft.h"

typedef struct	s_dict_item
{
	char				*key;
	void				*value;
	struct s_dict_item	*next;
}				t_dict_item;

typedef struct	s_dict
{
	struct s_dict_item	**items;
	int					capacity;
}				t_dict;

size_t			ft_dict_hash(char *input);
t_dict			*ft_dict_init(int capacity);
t_dict_item		*ft_dict_create_item(char *key, void *value);
int				ft_dict_insert(t_dict *dict, char *key, void *value);
void			*ft_dict_search(t_dict *dict, char *key);
void			ft_dict_remove(t_dict *dict, char *key);

#endif
