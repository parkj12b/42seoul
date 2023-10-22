/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 07:53:42 by minsepar          #+#    #+#             */
/*   Updated: 2023/09/14 20:59:11 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_btree.h"

t_btree	*btree_create_node(void *item);

void	btree_insert_data(t_btree **root,
		void *item, int (*cmpf)(void *, void *))
{
	int	diff;

	if (*root == 0)
	{
		*root = btree_create_node(item);
		return ;
	}
	diff = cmpf((*root)->item, item);
	if (diff > 0)
		btree_insert_data(&(*root)->left, item, cmpf);
	else
		btree_insert_data(&(*root)->right, item, cmpf);
}
