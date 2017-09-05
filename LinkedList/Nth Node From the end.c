// NTH node from the end in Linked List
//-------------------------------
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
    }
struct linked* nodeFromEnd(int n){
    struct linked* slow=head;
    struct linked* fast=head;
    int count=0;
    while(count!=n){
        fast=fast->next;
        count++;
        cout<<"count:"<<count<<endl;
    }
    while(fast!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    return slow;
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
     int n;
     cin>>n;
     cur=nodeFromEnd(n);
     cout<<cur->data;
     cout<<endl;


}
