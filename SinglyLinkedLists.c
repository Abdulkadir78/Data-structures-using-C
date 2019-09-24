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
struct node *sort_list(struct node *);
struct node *display(struct node *);

int noElementSearch(int);

int main()
{
    int choice;
    printf("*****MENU*****\n1-Create list\n2-Insert at beginning\n3-Insert at end\n4-Insert before an element\n5-Insert after an element\n6-Delete a node\n7-Delete at beginning\n8-Delete at end\n9-Delete after an element\n10-Delete whole list\n11-Sort the list\n12-Display the list\n13-Exit\n");

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
            break;

        case 5:
            start = insert_after(start);
            break;

        case 6:
            start = delete_node(start);
            break;

        case 7:
            start = delete_beginning(start);
            break;

        case 8:
            start = delete_end(start);
            break;

        case 9:
            start = delete_after(start);
            break;

        case 10:
            start = delete_list(start);
            break;

        case 11:
            start = sort_list(start);
            break;

        case 12:
            start = display(start);
            break;

        case 13:
            break;

        default:
            printf("Invalid choice\n");
        }

    } while (choice != 13);

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

    if (start == NULL) //condition if there is no list created before trying to insert
    {
        start = insert_beginning(start);
    }

    else
    {
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
    }

    return start;
}

struct node *insert_before(struct node *start)
{
    int val, num;
    struct node *new_node, *ptr, *preptr;

    if (start == NULL) //condition if there is no list created before trying to insert
    {
        printf("No element to insert before\n");
    }

    else
    {

        printf("Enter the element before which you want to insert: ");
        scanf("%d", &val);

        if (val == start->data) //condition if user wants to insert before the starting(first) element
        {
            start = insert_beginning(start);
        }

        else
        {
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
            printf("Element inserted\n");
        }
    }
    return start;
}

struct node *insert_after(struct node *start)
{
    int num, val;
    struct node *new_node, *ptr, *preptr;

    if (start == NULL) //condition if there is no list created before trying to insert
    {
        printf("No element to insert after\n");
    }

    else
    {

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
        printf("Element inserted\n");
    }
    return start;
}

struct node *delete_node(struct node *start)
{
    int val, no_node;
    struct node *ptr, *preptr, *temp;

    if (start == NULL) //condition if user wants to delete before creating a list
    {
        printf("No element to delete\n");
    }

    else
    {

        printf("Enter the element to be deleted: ");
        scanf("%d", &val);
        ptr = start;

        no_node = noElementSearch(val); // when there is no such element in the list
                                        // function is defined below
        if (no_node == 0)
        {
            printf("Element not found\n");
        }

        else if (start->data == val) //condition if user wants to delete beginning(first) element
        {
            start = delete_beginning(start);
        }

        else
        {

            while (ptr->data != val)
            {
                preptr = ptr;
                ptr = ptr->next;
                temp = ptr;
            }

            temp = temp->next;
            free(ptr);
            preptr->next = temp;
            printf("Element deleted\n");
        }
    }
    return start;
}

int noElementSearch(int temp) //this function is written for when the user tries to delete an element which is not present in the list
{
    struct node *ptr;

    ptr = start;
    while (ptr != NULL)
    {
        if (ptr->data == temp)
        {
            return -1;
        }
        ptr = ptr->next;
    }

    if (ptr == NULL)
    {
        return 0;
    }
}

struct node *delete_beginning(struct node *start)
{
    if (start == NULL) //condition if user wants to delete before creating a list
    {
        printf("No element to delete\n");
    }

    else
    {
        struct node *ptr;
        ptr = start;
        start = start->next;
        free(ptr);
        printf("Beginning element deleted\n");
    }

    return start;
}

struct node *delete_end(struct node *start)
{
    struct node *ptr, *preptr;

    if (start == NULL) //condition if user wants to delete before creating a list
    {
        printf("No element to delete\n");
    }

    else if (start->next == NULL)
    {
        free(start);
        start = NULL;
        printf("Element deleted!\n");
    }

    else
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            preptr = ptr;
            ptr = ptr->next;
        }

        free(ptr);
        preptr->next = NULL;
        printf("Done!\n");
    }

    return start;
}

struct node *delete_after(struct node *start)
{
    int val, no_node;
    struct node *ptr, *preptr, *postptr;

    if (start == NULL) //condition if user wants to delete before creating a list
    {
        printf("No element to delete\n");
    }

    else
    {
        printf("Enter the element after which you want to delete: ");
        scanf("%d", &val);

        no_node = noElementSearch(val); // when there is no such element in the list

        if (no_node == 0)
        {
            printf("Element not found\n");
        }

        else
        {
            ptr = start;
            preptr = ptr;
            postptr = ptr;

            while (preptr->data != val)
            {
                preptr = ptr;
                ptr = ptr->next;
                postptr = ptr;
            }

            if (preptr->next == NULL) //condition if user wants to delete after the end(last) element
            {
                printf("No element to delete after %d\n", val);
            }

            else if (start->data == val) // if user wants to delete after the first element
            {
                ptr = ptr->next;
                postptr = ptr->next;
                free(ptr);
                preptr->next = postptr;
                printf("Element deleted\n");
            }
            else
            {
                postptr = postptr->next;
                free(ptr);
                preptr->next = postptr;
                printf("Element deleted\n");
            }
        }
    }
    return start;
}

struct node *delete_list(struct node *start)
{
    struct node *ptr;

    if (start == NULL) //condition if user wants to delete the list before creating one
    {
        printf("There is no list\n");
    }

    else
    {
        ptr = start;
        while (ptr != NULL)
        {
            ptr = ptr->next;
            free(start);
            start = ptr;
        }
        printf("List deleted\n");
    }
    return start;
}

struct node *sort_list(struct node *start)
{
    int temp;
    struct node *ptr1, *ptr2;

    if (start == NULL) //condition if there is no list created before
    {
        printf("There is no list\n");
    }

    else
    {
        ptr1 = start;
        ptr2 = ptr1;

        while (ptr1->next != NULL)
        {
            ptr2 = ptr1->next;

            while (ptr2 != NULL)
            {
                if (ptr1->data > ptr2->data)
                {
                    temp = ptr1->data;
                    ptr1->data = ptr2->data;
                    ptr2->data = temp;
                }

                ptr2 = ptr2->next;
            }

            ptr1 = ptr1->next;
        }

        printf("The list is sorted\n");
    }

    return start;
}

struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;

    if (start == NULL) //condition if there is no list created before
    {
        printf("There is no list\n");
    }

    else
    {
        while (ptr != NULL)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
    }

    return start;
}
