#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 	s_node
{
	char 		data;
	struct s_node *prev;
	struct s_node *next;
}				t_node;

typedef struct	s_deque
{
	int			size;
	t_node 		*front;
	t_node 		*rear;
}				t_deq;

void	print_deq(t_deq *deq)
{
	t_node *node;

	if (deq == NULL)
		return ;
	if (deq->front == NULL || deq->rear == NULL)
		return ;
	node = deq->front;
	printf("data : ");
	while (node != deq->rear)
	{
		printf("%c ", node->data);
		node = node->next;
	}
	printf("%c ", node->data);
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

void insert_front(t_deq *deq, t_node **node, int data)
{
	t_node *new;
	t_node *first;

	if (node == NULL || deq == NULL)
		return ;
	new = new_node(data);
	if (new == NULL)
		return ;
	if (*node == NULL)
	{
		deq->size++;
		deq->front = new;
		deq->rear = new;
		*node = new;
		return ;
	}
	first = *node;
	*node = new;
	(*node)->next = first;
	first->prev = *node;
	deq->front = *node;
	deq->front->prev = deq->rear;
	deq->size++;
}

void insert_rear(t_deq *deq, t_node **node, int data)
{
	t_node *new;
	t_node *last;

	if (node == NULL || deq == NULL)
		return ;
	new = new_node(data);
	if (new == NULL)
		return ;
	if (*node == NULL)
	{
		deq->size++;
		deq->front = new;
		deq->rear = new;
		*node = new;
		return ;
	}
	last = deq->rear;
	deq->rear = new;
	last->next = new;
	new->prev = last;
	new->next = *node;
	(*node)->prev = new;
	deq->size++;
}

void delete_front(t_deq *deq, t_node **node)
{
	if (deq == NULL || *node == NULL)
		return ;
	if (deq->size == 0)
		return ;
	if (deq->size == 1)
	{
		deq->front = NULL;
		deq->rear = NULL;
		*node = (*node)->next;
		deq->size--;
		return ;
	}
	deq->front = deq->front->next;
	deq->front->prev = deq->rear;
	deq->rear->next = deq->front;
	*node = (*node)->next;
	deq->size--;
}

void delete_rear(t_deq *deq, t_node **node)
{
	if (deq == NULL || *node == NULL)
		return ;
	if (deq->size == 0)
		return ;
	if (deq->size == 1)
	{
		deq->front = NULL;
		deq->rear = NULL;
		*node = (*node)->prev;
		deq->size--;
		return ;
	}
	deq->rear = deq->rear->prev;
	deq->front->prev = deq->rear;
	deq->rear->next = deq->front;
	*node = (*node)->prev;
	deq->size--;
}

int main()
{
	t_node *node;
	t_deq  *deq;
	char	*command;
	char	data;
	
	deq = malloc(sizeof(t_deq));
	if (deq == NULL)
		return (1);
	node = NULL;

	//command = (char *)malloc(sizeof(char) * 4);
	while (1)
	{
		command = (char *)malloc(sizeof(char) * 4);
		if (command == 0)
			return (0);
		printf("Command:");
		scanf("%s", command);
		if (*command == 'i')
		{
			printf("Data:");
			scanf(" %c", &data);
			printf("\n");
		}
		if (strcmp(command, "end") == 0)
		{
			free(command);
			break ;
		}
		if (strcmp(command, "df") == 0)
			delete_front(deq, &node);
		else if (strcmp(command, "dr") == 0)
			delete_rear(deq, &node);
		else if (strcmp(command, "if") == 0)
			insert_front(deq, &node, data);
		else if (strcmp(command, "ir") == 0)
			insert_rear(deq, &node, data);
		else
			printf("Error : Invalid Instruction\n");
		print_deq(deq);
		printf("\n");
		free(command);
	}
	/*insert_front(deq, &node, '2');
	insert_front(deq, &node, '1');
	insert_rear(deq, &node, '3');
	insert_rear(deq, &node, '4');
	delete_front(deq, &node);
	delete_rear(deq, &node);
	print_deq(deq);*/
}
