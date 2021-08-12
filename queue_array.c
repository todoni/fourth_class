#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct	s_queue
{
	int			max_size;
	int			current_size;
	char		*array;
}				t_que;

void new_queue(t_que *que, int max)
{
	char *new;

	new = malloc(sizeof(char) * (max + 1));
	memset(new, 0, sizeof(char)* (max + 1));
	que->max_size = max;
	que->array = new;
}

void enqueue(t_que *que, char data)
{
	char *front;

	front = que->array;
	if (que->current_size == que->max_size)
	{
		printf("고마해라, 마이 묵었다. Overflow\n");
		return ;
	}
	while (*front != 0)
		front++;
	*front = data;
	que->current_size++;
}

void dequeue(t_que *que)
{
	if (que->current_size == que->max_size)
	{
		printf("배고파염 힝구ㅜㅜ. Underflow\n");
		return ;
	}
	que->array++;
	que->current_size--;
}

void print_queue(t_que *que)
{
	printf("%s", que->array);
}

int main()
{
	t_que  *que;
	char	*array;

	que = malloc(sizeof(t_que));
	new_queue(que, 5);
	enqueue(que, 'a');
	enqueue(que, 'b');
	enqueue(que, 'c');

	dequeue(que);
	dequeue(que);

	print_queue(que);

}
