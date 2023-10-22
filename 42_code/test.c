#include "ex07/ft_btree.h"
#include <stdio.h>
#include <string.h>
#include <_malloc.h>

void print_node(void *item)
{
	printf("%s\n", item);
}

t_btree	*btree_create_node(void *item)
{
	t_btree	*node;

	node = (t_btree *)malloc(sizeof(t_btree));
	node->item = item;
	node->left = 0;
	node->right = 0;
	return (node);
}

void btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	applyf(root->item);
	if (root->left)
		btree_apply_prefix(root->left, applyf);
	if (root->right)
		btree_apply_prefix(root->right, applyf);
}

void	btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (root->left)
		btree_apply_infix(root->left, applyf);
	applyf(root->item);
	if (root->right)
		btree_apply_infix(root->right, applyf);
}

void	btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (root->left)
		btree_apply_suffix(root->left, applyf);
	if (root->right)
		btree_apply_suffix(root->right, applyf);
	applyf(root->item);
}

void btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
	int diff;

	if (*root == 0)
	{
		*root = btree_create_node(item);
		return ;
	}
	diff = cmpf((*root)->item, item);
	if (diff > 0)
	{
		if ((*root)->left == 0)
			(*root)->left = btree_create_node(item);
		else
			btree_insert_data(&(*root)->left, item, cmpf);
	}
	else
	{
		if ((*root)->right == 0)
			(*root)->right = btree_create_node(item);
		else
			btree_insert_data(&(*root)->right, item, cmpf);
	}
}

int	ft_cmp(void *a, void *b)
{
	unsigned char *s1 = (unsigned char *) a;
	unsigned char *s2 = (unsigned char *) b;
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char) *s1 - (unsigned char) *s2);
}
void *btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	void *data;

	data = 0;
	if (!root)
		return (0);
	data = btree_search_item(root->left, data_ref, cmpf);
	if (data)
		return (data);
	if (cmpf(root->item, data_ref) == 0)
		return (root->item);
	data = btree_search_item(root->right, data_ref, cmpf);
	if (data)
		return (data);
	return (0);
}
int	btree_level_count(t_btree *root)
{
	int left;
	int right;

	left = 0;
	right = 0;
	if (root->left)
		left = btree_level_count(root->left);
	if (root->right)
		right = btree_level_count(root->right);
	if (left > right)
		return (left + 1);
	else
		return (right + 1);
}
int	count_node(t_btree *root)
{
	int left;
	int right;

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
	t_btree *temp;
	temp = q->arr[q->front];
	q.front++;
	q.size--;
	return (temp);
}

void	queue_init(t_queue *q, t_btree *root)
{
	int num_node;
	
	num_node = count_node(root);
	q->arr = (t_btree *)malloc(sizeof(t_btree) * num_node);
	q->front = 0;
	q->rear = 0;
	q->level = 0;
	q->level_size = 1;
	q->size = 0;
	q.i = 0;
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
void	applyf(void *item, int current_level, int is_first_elem)
{
	printf("item = [%s], current-level=%d, isfirstelem=%d\n", item, current_level, is_first_elem);
}
int main()
{
	t_btree *head = btree_create_node("1");	
	head->left = btree_create_node("2");
	head->right = btree_create_node("3");
	head->left->left = btree_create_node("4");
	head->left->right = btree_create_node("5");
	head->right->left = btree_create_node("6");
	head->right->right = btree_create_node("7");
	head->right->right->right = btree_create_node("8");
	//btree_insert_data(&head, "8", ft_cmp);
	
	//printf("%s\n", btree_search_item(head, "2", ft_cmp));

	//printf("count: %d\n", count_node(head));

	//printf("%d\n", btree_level_count(head));

	btree_apply_by_level(head, applyf);
	/*
	printf("infix:\n");
	btree_apply_infix(head, print_node);
	printf("prefix:\n");
	btree_apply_prefix(head, print_node);
	printf("suffix:\n");
	btree_apply_suffix(head, print_node);
	*/
}
