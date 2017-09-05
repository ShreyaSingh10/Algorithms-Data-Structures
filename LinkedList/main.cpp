#include <iostream>
#include <malloc.h>
#include <stdio.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
// defining a function, that returns 1, if the list is EVEN
int isLengthEven()
{
    // we need to traverse the List, until we reach the end
    // checking both conditions, NULL and the last Node
    while(head !=NULL && head -> next != NULL)
    {
        //advance 2 nodes at a time
        head = head -> next -> next;
    }

    // if we are at a NULL, means EVEN, return 1
    if(head == NULL)
        return 1;
    else
        return 0;
}

void addElement()
{
    struct node * temp = (struct node*)malloc(sizeof(struct node));
    int number;
    cout<"enter value\n";
    cin>>number;
    temp -> data = number;
    temp -> next = NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
    struct node * temp2 = head;
    while(temp2 -> next != NULL)
        temp2 = temp2 -> next;
    temp2 -> next = temp;
    }
}
int traverse()
 {
     int c=0;
     struct node *temp2=head;
     while(temp2->next!=NULL)
     {
         c++;
         temp2=temp2->next;
     }
     c=c+1;
     return c;
 }
int main()
{
    //creating a list
    while(1)
    {
        addElement();
    }
    int x=isLengthEven();
    if(x==1)
        printf("EVEN\n");
    else
        printf("ODD\n");
        int n=traverse();
        if(n%2==0)
            cout<<"yes even\n";
            else
                cout<<"no odd\n";
    return 0;
}
