/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstring.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <jtahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 20:31:32 by jtahirov          #+#    #+#             */
/*   Updated: 2018/05/21 12:44:08 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DSTRING_H
# define FT_DSTRING_H

# include "../libft.h"

typedef struct 	s_dstring_elem
{
        char *word;
        int  occurence;
}				t_dstring_elem;

typedef struct 	s_dstring_list
{
        struct s_elem **elems;
        int           len;
}				t_dstring_list;

typedef struct 	s_dstring
{
  char *content;
  int  length;
  int  capacity;
}				t_dstring;


t_dstring 		*ft_dstring_init(void);
int 			ft_string_append(t_dstring *dstr, char *add);

#endif
