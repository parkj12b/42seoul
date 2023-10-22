/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 09:49:44 by minsepar          #+#    #+#             */
/*   Updated: 2023/09/14 11:57:17 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_btree.h"

int	count_node(t_btree *root)
{
	int	left;
	int	right;

	left = 0;
	right = 0;
	if (!root)
		return (0);
	if (root->left)
		left = count_node(root->left);
	if (root->right)
		right = count_node(root->right);
	return (left + right + 1);
}

void	enqueue(t_queue *q, t_btree *node)
{
	q->arr[q->rear] = *node;
	q->rear = q->rear + 1;
	q->size = q->size + 1;
}

t_btree	*dequeue(t_queue *q)
{
	t_btree	*temp;

	temp = &q->arr[q->front];
	q->front++;
	q->size--;
	return (temp);
}

void	queue_init(t_queue *q, t_btree *root)
{
	int	num_node;

	num_node = count_node(root);
	q->arr = (t_btree *)malloc(sizeof(t_btree) * num_node);
	q->front = 0;
	q->rear = 0;
	q->level = 0;
	q->level_size = 1;
	q->size = 0;
	q->i = 0;
}

void	btree_apply_by_level(t_btree *root,
		void (*applyf)(void *item, int current_level, int is_first_elem))
{
	t_queue	q;
	t_btree	*node;

	queue_init(&q, root);
	enqueue(&q, root);
	while (q.size)
	{
		node = dequeue(&q);
		if (q.i == 0)
			applyf(node->item, q.level, 1);
		else
			applyf(node->item, q.level, 0);
		if (node->left)
			enqueue(&q, node->left);
		if (node->right)
			enqueue(&q, node->right);
		q.i++;
		if (q.i >= q.level_size)
		{
			q.level++;
			q.level_size = q.size;
			q.i = 0;
		}
	}
}
