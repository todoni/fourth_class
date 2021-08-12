#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct 	s_node
{
	int 		data;
	struct s_node *prev;
	struct s_node *next;
}				t_node;

typedef struct	s_queue
{
	int			size;
	t_node 		*front;
	t_node 		*rear;
}				t_que;

void	print_que(t_que *que)
{
	t_node *node;

	if (que == NULL)
		return ;
	if (que->front == NULL || que->rear == NULL)
		return ;
	node = que->front;
	while (node != que->rear)
	{
		printf("data: %d\n", node->data);
		node = node->next;
	}
	printf("data: %d\n", node->data);
}

t_node *new_node(char data)
{
	t_node *ret;

	ret = (t_node *)malloc(sizeof(t_node));
	if (ret == NULL)
		return (NULL);
	ret->data = data;
	ret->prev = NULL;
	ret->next = NULL;
	return (ret);
}

void enqueue(t_que *que, t_node **node, int data)
{
	t_node *new;
	t_node *last;

	if (node == NULL || que == NULL)
		return ;
	new = new_node(data);
	if (new == NULL)
		return ;
	if (*node == NULL)
	{
		que->size++;
		que->front = new;
		que->rear = new;
		*node = new;
		return ;
	}
	last = que->rear;
	que->rear = new;
	last->next = new;
	new->prev = last;
	new->next = *node;
	(*node)->prev = new;
	que->size++;
}

void dequeue(t_que *que, t_node **node)
{
	t_node	*temp;

	if (que == NULL || *node == NULL)
		return ;
	if (que->size == 0)
		return ;
	if (que->size == 1)
	{
		que->front = NULL;
		que->rear = NULL;
		temp = *node;
		*node = (*node)->next;
		free(temp);
		que->size--;
		return ;
	}
	que->front = que->front->next;
	que->front->prev = que->rear;
	que->rear->next = que->front;
	temp = *node;
	*node = (*node)->next;
	free(temp);
	que->size--;
}

t_node *peek(t_que *que)
{
	if (que == NULL)
		return (NULL);
	return (que->front);
}

int main()
{
	t_node *node;
	t_que  *que;

	que = malloc(sizeof(t_que));
	if (que == NULL)
		return (0);
	node = NULL;
t_node	*new_node(char data);

t_node	*new_node(char data);
	enqueue(que, &node, 1);
	enqueue(que, &node, 2);
	enqueue(que, &node, 3);
	enqueue(que, &node, 4);
	dequeue(que, &node);
	dequeue(que, &node);
	print_que(que);
}
