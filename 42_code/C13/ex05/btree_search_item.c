/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 08:19:35 by minsepar          #+#    #+#             */
/*   Updated: 2023/09/14 11:50:58 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	void	*data;

	data = 0;
	if (!root)
		return (0);
	data = btree_search_item(root->left, data_ref, cmpf);
	if (data)
		return (data);
	if (cmpf(root->item, data_ref) == 0)
		return (root->item);
	data = btree_search_item(root->right, data_ref, cmpf);
	return (data);
}
