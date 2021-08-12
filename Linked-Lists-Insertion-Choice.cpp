#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != 0)
    {
        cout << "ELEMENT:" << ptr->data << endl;
        ptr = ptr->next;
    }
}

struct Node *insertAtFirstIndex(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

struct Node *insertAtanyIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;

    int i = 0;
    while (i != index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct Node *insertAtLastIndex(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    ptr->data = data;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

int main()
{
    int buffer = 0;

    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    int headdata, seconddata, thirddata;
    int choice;
    int n;

    cout << "Enter the data of the head position:";
    cin >> headdata;

    cout << "Enter the data of the second position:";
    cin >> seconddata;

    cout << "Enter the data of the third position:";
    cin >> thirddata;

    cout << endl;

    head->data = headdata;
    head->next = second;

    second->data = seconddata;
    second->next = third;

    third->data = thirddata;
    third->next = NULL;

    linkedListTraversal(head);

    cout << "Enter the number of new elements you want to insert in the list:";
    cin >> n;

    while (n != 0)
    {
        cout << "---------------------MENU--------------------" << endl;

        cout << "1-Insert at the first Index:" << endl;
        cout << "2-Insert at an index in between the first and last Index:" << endl;
        cout << "3-Insert at the last Index:" << endl;
        cout << endl;
        cout << "Where do you want to insert new data:";
        cin >> choice;

        switch (choice)
        {

        case 1:
        {
            int element;
            cout << "Enter the element to be inserted at the first index:";
            cin >> element;
            head = insertAtFirstIndex(head, element);
            linkedListTraversal(head);
        }
        break;
        case 2:
        {
            int element;
            int index;
            cout << "Enter the element to be inserted:";
            cin >> element;
            cout << "Enter the index to be inserted at:";
            cin >> index;
            head = insertAtanyIndex(head, element, index);
            linkedListTraversal(head);
        }
        break;
        case 3:
        {
            int element;
            cout << "Enter the element to be inserted at the last index:";
            cin >> element;
            head = insertAtLastIndex(head, element);
            linkedListTraversal(head);
        }
        break;
        default:
        {
            cout << "Choose a provided option:" << endl;
        }
        }
        n--;
    }


    cin >> buffer;
    return 0;
}