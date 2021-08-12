#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node 
{
    int data;
    struct Node * next;
};

void linkedListTraversal(struct Node*ptr)
{
    while(ptr!=NULL)
    {
        cout<<"ELEMENT:"<<ptr->data<<endl;
        ptr=ptr->next;
    }
}

struct Node * insertAtFirst(struct Node* head,int data)
{
    struct Node * ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=head;
    return ptr;
}


int main()
{
    int buffer;
    int element;

    struct Node * head=(struct Node *)malloc(sizeof(struct Node));
    struct Node * second=(struct Node *)malloc(sizeof(struct Node));
    struct Node * third=(struct Node *)malloc(sizeof(struct Node));

    head->data=13;
    head->next=second;

    second->data=17;
    second->next=third;

    third->data=19;
    third->next=NULL;

    linkedListTraversal(head);

    cout<<"Enter the element to be inserted at the first position:"<<endl;
    cin>>element;

    cout<<endl;
    cout<<endl;


    head=insertAtFirst(head,element);

    linkedListTraversal(head);


    cin>>buffer;
    return 0;
}

