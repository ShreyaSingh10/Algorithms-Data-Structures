// This is the text editor interface.
// Anything you type or change here will be seen by the other person in real time.

//CIRCULAR LINKED LIST IMPLEMENTATION AND DELETION OF FIRST ELEMENT
// ne->next=head
#include <bits/stdc++.h>

using namespace std;
struct linked {
    int data;
    struct linked *next;
};
struct linked *cur=NULL;
struct linked *head=NULL;
void insert(int x){
        struct linked *ne=(linked *)malloc(sizeof(struct linked));
        ne->data=x;
        ne->next=NULL;
        cur->next=ne;
        cur=ne;
        ne->next=head;
    }
void deleteFirst(){
    cur=head;
    struct linked *temp=head;
    while(cur->next!=head){
        cur=cur->next;
    }
    cur->next=head->next;
    head=head->next;
    free(temp);

}
void display(){
    cur=head;
    while(cur->next!=head){
        cout<<cur->data<<" ";
        cur=cur->next;
    }
}


int main(){
    head=(linked *)malloc(sizeof(struct linked));
    int x;
    cin>>x;
    head->data=x;
    head->next=NULL;
    cur=head;
    int y;
     for(int i=0;i<5;i++){
        cin>>y;
        insert(y);
     }

     display();
     cout<<endl;
     deleteFirst();
     display();
     cout<<endl;

}
