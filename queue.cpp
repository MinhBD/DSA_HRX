#include <stdio.h>
#include <stdlib.h>
typedef int item;
struct note
{
	item data;
	note *next;
};
struct queue
{
	note * first, *end;
	int cout;

};
void init(queue &q);
int isempty(queue q);
void push(queue &q, item x);
int pop(queue &q);
int qfirst(queue q);
note *notepad(item x);
void input(queue &q);
void output(queue q);
void init(queue &q)
{
	q.first = q.end = NULL;
	q.cout = 0;
}
int isempty(queue q)
{
	if(q.cout == 0)
		return 1;
	return 0;
}
note *notepad(item x)
{
	note *p = (note*)malloc(sizeof(note));
	p->next = NULL;
	p->data = x;
	return p;
}
void push(queue &q, item x)
{
	note *p = notepad(x);
	if(isempty(q))
	{
		q.first = q.end = p;
	}
	else
		{
			q.end->next = p;
			q.end = p;
		}
		q.cout++;
}
int pop(queue &q)
{
	if(isempty(q))
	{
		printf("queue empty");
		return 0;
	}
	else{
		item x = q.first-> data;
		if(q.cout == 1)
			init(q);
		else
			q.first = q.first -> next;
		q.cout--;
		return x;
	}
}
void input(queue &q)
{
	int i=0; 
    item x;
    do
    {
	    i++;
        printf ("enter value %d : ",i);
        scanf("%d",&x);
        if (x != 0) push(q,x);
    } while(x != 0);
}
void output(queue q)
{
	note*p = q.first;
	while(p != NULL)
		{
			printf("%d  ",p->data);
			p = p->next;
		}
		printf("\n");

}
int main()
{
	queue q;
	init(q);
	input(q);
	output(q);
	int seclect;
	printf("\n seclect math with queue : \n 1:test queue empty\n 2:add queue\n 3:delete queue\n 4:output queue \n 5:exit");
	do
	{
		printf("enter seclect :\n");
		scanf("%d", &seclect);
		switch(seclect)
		{
			case 1:
			{
				if(isempty(q))
					printf("queue empty\n");
				else
					printf("queue not empty\n");
				break;
			}
			case 2 :
			{
				item x;
				printf("add queue \n");
				scanf("%d", &x);
				push(q,x);
				break;
			}
			case 3:
			{
				pop(q);
				break;
			}
			case 4:
			{
				output(q);
				break;
			}
			case 5:
			break;
		}
	}while(seclect != 5);
	return 0;
}