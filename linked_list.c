// Write a program to implement linked list operation(creation,insertion,deletion,reversing)

#include <stdio.h>
#include <stdlib.h>
typedef struct ListItem // node definition
{
    int data;
    struct ListItem *link;

} ListItem;
typedef struct List
{
    ListItem *root;

} List;

ListItem *createNode(int data)
{
    ListItem *node;
    node = malloc(sizeof(ListItem));
    node->data = data;
    node->link = NULL;
    return node;
}

void inserItem(List *l1, int item)
{
    ListItem *temp, *traverse;
    temp = createNode(item);
    if (temp == NULL)
    {
        printf("\n\nmemory error");
        return;
    }
    if (l1->root == NULL)
    {
        l1->root = temp;
        return;
    }
    else
    {
        traverse = l1->root;
        while (traverse->link != NULL)
            traverse = traverse->link;
        traverse->link = temp;
    }
}
void insertAt(List *l1, int pos, int item)
{
    ListItem *temp, *traverse;
    int i = 1;
    temp = createNode(item);
    if (temp == NULL)
    {
        printf("\n\nMemory error");
        return;
    }
    if (pos < 1)
    {
        printf("\n\nInvalid position");
    }
    else if (pos == 1)
    {
        temp->link = l1->root;
        l1->root = temp;
    }
    else
    {
        traverse = l1->root;
        while (traverse->link != NULL && i < pos - 1)
        {
            traverse = traverse->link;
            i++;
        }
        if (i != pos - 1)
        {
            printf("\n\ninvalid position ");
            return;
        }
        temp->link = traverse->link;
        traverse->link = temp;
    }
}

void deletionItem(List *l1)
{
    ListItem *temp, *traverse;
    if (l1->root == NULL)
    {
        printf("\n\nEMPTY LIST");
        return;
    }
    traverse = l1->root;
    if (traverse->link == NULL)
    {
        temp = traverse;
        printf("\n\n Deleted Item: %d ", temp->data);
        l1->root = NULL;
        free(temp);
        return;
    }
    while (traverse->link->link != NULL)
    {
        traverse = traverse->link;
        temp = traverse->link;
        traverse->link = NULL;
        printf("\n\ndeleted items: %d", temp->data);
        free(temp);
    }
}
void display(List *l1)
{
    ListItem *traverse;
    traverse = l1->root;
    printf("\n\nROOT");
    while (traverse != NULL)
    {
        printf("%d ", traverse->data);
        traverse = traverse->link;
    }
    printf("END");
}

void reversePrint(List *l1)
{
    ListItem *traverse = NULL, *temp = NULL;
    temp = l1->root;
    while (temp != traverse)
    {
        while (temp->link != traverse)
            temp = temp->link;
        printf("%d", temp->data);
        traverse = temp;
        temp = l1->root;
    }
}
void reverseList(List *l1)
{
    ListItem *trav, *temp, *newroot;
    if (l1->root == NULL || l1->root->link == NULL)
    {
        return;
    }
    trav = l1->root;
    while (trav->link != NULL) // find the new root
        trav = trav->link;
    newroot = trav;
    while (trav != l1->root)
    {
        temp = l1->root;
        while (temp->link != trav)
        {
            temp = temp->link;
        }
        trav->link = temp;
        trav = temp;
    }
    trav->link = NULL;
    l1->root = newroot;
    printf("\n\n\n%d", newroot->data);
}

int main()
{
    List l1;
    int opt;
    int x, pos;
    l1.root = NULL;
    while (1)
    {
        printf("\n\n\t\t\tLINKED LIST OPERATIONS\n\n");
        printf("\n\n\t\t\t1.ADD ITEM");
        printf("\n\n\t\t\t2.DELETE ITEM");
        printf("\n\n\t\t\t3.REVERSE ITEM");
        printf("\n\n\t\t\t4.SHOW ITEMS");
        printf("\n\n\t\t\t5.REVERSE PRINT");
        printf("\n\n\t\t\t6.INSERT ITEMS");
        printf("\n\n\t\t\t7.EXIT");
        printf("\n\n select the operation:");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("\\n\n enter the element to insert into list:");
            scanf("%d", &x);
            inserItem(&l1, x);
            break;
        case 2:
            deletionItem(&l1);
            break;
        case 3:
            reverseList(&l1);
            break;
        case 4:
            display(&l1);
            break;
        case 5:
            reversePrint(&l1);
            break;
        case 6:
            printf("\n\n enter the element to insert into list:");
            scanf("%d", &x);
            printf("\n\n enter the position:");
            scanf("%d", &pos);
            insertAt(&l1, pos, x);
            break;
        case 7:
            return 0;
                }
    }
}
