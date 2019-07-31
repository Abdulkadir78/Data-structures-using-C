#include <stdio.h>
#include <stdlib.h>
#define max 3

int st[max];
int top = -1;
int val;

int main()
{
	int choice, i, result, ans;
	void push(int st[], int val);
	int pop(int st[]);
	int peek(int st[]);
	void display(int st[]);

	printf("\n*****MENU*****\n");
	printf("Enter 1 for push\nEnter 2 for pop\nEnter 3 for peek\nEnter 4 to display\nEnter 5 to exit\n");

	do
	{
		printf("\nenter your choice: \n");
		scanf("%d", &choice);

		switch (choice)
		{

		case 1:
			push(st, val);
			break;

		case 2:
			result = pop(st);
			printf("removed element is %d\n", result);
			break;

		case 3:
			ans = peek(st);
			printf("\nelement is %d", ans);
			break;

		case 4:
			display(st);
			break;
		}

	} while (choice != 5);

	return 0;
}

void push(int st[], int val)
{
	if (top == max - 1)
	{
		printf("stack is full\n");
	}

	else
	{
		top++;
		printf("enter the number\n");
		scanf("%d", &val);
		st[top] = val;
	}
}

int pop(int st[])
{
	if (top == -1)
	{
		printf("stack is empty");
	}

	else
	{
		val = st[top];
		top--;
		return val;
	}
}

int peek(int st[])
{
	if (top == -1)
	{
		printf("stack is empty");
		return -1;
	}

	else
	{
		return st[top];
	}
}

void display(int st[])
{
	int i;

	if (top == -1)
	{
		printf("stack is empty");
	}

	else
	{
		for (i = top; i >= 0; i--)
		{
			printf("%d\t", st[i]);
		}
	}
}