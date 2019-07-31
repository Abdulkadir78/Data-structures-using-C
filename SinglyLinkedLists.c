#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *create_ll(struct node *);
struct node *insert_beginning(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *delete_node(struct node *);
struct node *delete_beginning(struct node *);
struct node *delete_end(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);
struct node *display(struct node *);

int main()
{
    int choice;
    printf("*****MENU*****\n1-Create list\n2-Insert at beginning\n3-Insert at end\n4-Insert before an element\n5-Insert after an element\n6-Delete a node\n7-Delete at beginning\n8-Delete at end\n9-Delete after an element\n10-Delete whole list\n11-Display the list\n");

    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {

        case 1:
            start = create_ll(start);
            delete_end(start); //to delete the unwanted -1 at the end
            break;

        case 2:
            start = insert_beginning(start);
            printf("Element inserted at the beginning\n");
            break;

        case 3:
            start = insert_end(start);
            printf("Element inserted at the end\n");
            break;

        case 4:
            start = insert_before(start);
            printf("Element inserted\n");
            break;

        case 5:
            start = insert_after(start);
            printf("Element inserted\n");
            break;

        case 6:
            start = delete_node(start);
            printf("Element deleted\n");
            break;

        case 7:
            start = delete_beginning(start);
            printf("Beginning element deleted\n");
            break;

        case 8:
            start = delete_end(start);
            printf("End element deleted\n");
            break;

        case 9:
            start = delete_after(start);
            printf("Element deleted\n");
            break;

        case 10:
            start = delete_list(start);
            printf("List deleted\n");
            break;

        case 11:
            start = display(start);
            break;

        default:
            if (choice == 12)
            {
                break;
            }
            else
            {
                printf("Invalid choice\n");
            }
        }
    } while (choice != 12);

    return 0;
}

struct node *create_ll(struct node *start)
{
    int num;
    struct node *new_node, *ptr;

    printf("Press -1 to stop\n");

    do
    {
        printf("Enter the element: ");
        scanf("%d", &num);

        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;

        if (start == NULL)
        {
            start = new_node;
            new_node->next = NULL;
        }

        else
        {
            ptr = start;

            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }

            ptr->next = new_node;
            new_node->next = NULL;
        }

    } while (num != -1);

    return start;
}

struct node *insert_beginning(struct node *start)
{
    int num;
    struct node *new_node;

    printf("Enter the element: ");
    scanf("%d", &num);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = start;
    start = new_node;
    return start;
}

struct node *insert_end(struct node *start)
{
    int num;
    struct node *new_node, *ptr;

    printf("Enter the element: ");
    scanf("%d", &num);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = new_node;
    new_node->next = NULL;
    return start;
}

struct node *insert_before(struct node *start)
{
    int val, num;
    struct node *new_node, *ptr, *preptr;

    printf("Enter the element before which you want to insert: ");
    scanf("%d", &val);

    printf("Enter the element: ");
    scanf("%d", &num);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;

    while (ptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    preptr->next = new_node;
    new_node->next = ptr;
    return start;
}

struct node *insert_after(struct node *start)
{
    int num, val;
    struct node *new_node, *ptr, *preptr;

    printf("Enter the element after which you want to insert: ");
    scanf("%d", &val);

    printf("Enter the element to be inserted: ");
    scanf("%d", &num);

    ptr = start;
    preptr = ptr;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    while (preptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    preptr->next = new_node;
    new_node->next = ptr;
    return start;
}

struct node *delete_node(struct node *start)
{
    int val;
    struct node *ptr, *preptr, *temp;

    printf("Enter the element to be deleted: ");
    scanf("%d", &val);

    ptr = start;

    while (ptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
        temp = ptr;
    }

    temp = temp->next;
    free(ptr);
    preptr->next = temp;
    return start;
}

struct node *delete_beginning(struct node *start)
{
    struct node *ptr;
    ptr = start;
    start = start->next;
    free(ptr);
    return start;
}

struct node *delete_end(struct node *start)
{
    struct node *ptr, *preptr;
    ptr = start;

    while (ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    free(ptr);
    preptr->next = NULL;
    return start;
}

struct node *delete_after(struct node *start)
{
    int val;
    struct node *ptr, *preptr, *postptr;

    printf("Enter the element after which you want to delete: ");
    scanf("%d", &val);
    ptr = start;
    preptr = ptr;
    postptr = ptr;

    while (preptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
        postptr = ptr;
    }

    postptr = postptr->next;
    free(ptr);
    preptr->next = postptr;
    return start;
}

struct node *delete_list(struct node *start)
{
    struct node *ptr;
    ptr = start;

    while (ptr != NULL)
    {
        ptr = ptr->next;
        free(start);
        start = ptr;
    }

    return start;
}

struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;

    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }

    return start;
}