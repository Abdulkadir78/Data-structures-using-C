#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
	int data;
	struct node *next;
};

struct node *top = NULL;

struct node *push(struct node *);
struct node *pop(struct node *);
int peek(struct node *);
struct node *display(struct node *);

int main()
{
	int choice, result;

	printf("*****MENU*****\n1-push\n2-pop\n3-peek\n4-display\n5-exit\n");

	do
	{
		printf("\nEnter your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{

		case 1:
			top = push(top);
			printf("Element inserted\n");
			break;

		case 2:
			top = pop(top);
			break;

		case 3:
			result = peek(top);

			if (result == -1)
			{
				printf("Stack is empty\n");
			}

			else
			{
				printf("Element is %d\n", result);
			}

			break;

		case 4:
			top = display(top);
			break;

		default:

			if (choice == 5)
			{
				break;
			}

			else
			{
				printf("Invalid choice");
			}

			break;
		}

	} while (choice != 5);

	return 0;
}

struct node *push(struct node *top)
{
	int val;
	struct node *new_node;

	printf("Enter the number to be inserted: ");
	scanf("%d", &val);

	new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = val;

	if (top == NULL)
	{
		new_node->next = NULL;
		top = new_node;
	}

	else
	{
		new_node->next = top;
		top = new_node;
	}

	return top;
}

struct node *pop(struct node *top)
{
	struct node *ptr;
	ptr = top;

	if (top == NULL)
	{
		printf("Stack is empty\n");
	}

	else
	{
		top = top->next;
		printf("Element deleted is %d\n", ptr->data);
		free(ptr);
	}

	return top;
}

int peek(struct node *top)
{
	if (top == NULL)
	{
		return -1;
	}

	else
	{
		return top->data;
	}
}

struct node *display(struct node *top)
{
	struct node *ptr;
	ptr = top;

	if (top == NULL)
	{
		printf("Stack is empty\n");
	}

	else
	{
		while (ptr != NULL)
		{
			printf("%d\n", ptr->data);
			ptr = ptr->next;
		}
	}
	return top;
}