/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:29:41 by minsepar          #+#    #+#             */
/*   Updated: 2023/09/13 16:57:21 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}	t_list;

typedef struct s_ptr
{
	struct s_list	*prev;
	struct s_list	*cur;
	struct s_list	*next;
}	t_ptr;

t_list	*ft_create_elem(void *data);

#endif
