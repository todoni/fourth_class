#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct 	s_node
{
	char		data;
	struct s_node *prev;
	struct s_node *next;
}				t_node;

typedef struct	s_queue
{
	int			size;
	t_node 		*front;
	t_node 		*rear;
}				t_que;

typedef struct	s_deque
{
	int			size;
	t_node 		*front;
	t_node 		*rear;
}				t_deq;

void	print_que(t_que *que);
t_node	*new_node(char data);
void	enqueue(t_que *que, t_node **node, int data);
void	dequeue(t_que *que, t_node **node);
t_node	*peek(t_que *que);

#endif
