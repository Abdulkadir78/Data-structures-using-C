#include <stdio.h>
#define max 3

int val;
int front = -1;
int rear = -1;
int q[max];

void insert();
int del();
int peek();
void display();

int main()
{
	int choice;
	int result;
	printf("*****MENU******\n");
	printf("1-insert\n2-delete\n3-peek\n4-display\n5-exit\n");
	do
	{
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		switch (choice)
		{

		case 1:
			insert();
			break;

		case 2:
			result = del();

			if (result == -1)
			{
				printf("No element to delete\n");
			}

			else
			{
				printf("\ndeleted element is %d", result);
			}

			break;

		case 3:
			result = peek();

			if (result == -1)
			{
				printf("There is no element\n");
			}

			else
			{
				printf("element is %d\n", result);
			}

			break;

		case 4:
			display();
			break;

		default:

			if (choice == 5)
			{
				break;
			}

			else
			{
				printf("Invalid choice\n");
			}
		}
	} while (choice != 5);

	return 0;
}

void insert()
{
	printf("Enter the value to be inserted: ");
	scanf("%d", &val);

	if (rear == max - 1)
	{
		printf("Queue is full\n");
	}

	else if (front == -1 && rear == -1)
	{
		front = rear = 0;
		q[rear] = val;
	}

	else
	{
		rear++;
		q[rear] = val;
	}
}

int del()
{
	if (front == -1 || front > rear)
	{
		printf("Queue is empty\n");
		return -1;
	}

	else
	{
		val = q[front];
		front++;
		if (front > rear)
		{
			front = rear = -1;
		}
		return val;
	}
}

int peek()
{
	if (front == -1 || front > rear)
	{
		printf("Queue is empty\n");
		return -1;
	}

	else
	{
		val = q[front];
		return val;
	}
}

void display()
{
	int i;
	if (front == -1 || front > rear)
	{
		printf("Queue is empty\n");
	}

	else
	{

		for (i = front; i <= rear; i++)
		{
			printf("%d\t", q[i]);
		}
	}
}