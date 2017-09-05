#include <bits/stdc++.h>

using namespace std;
struct linked {
    int data;
    struct linked *next;
};
struct linked *cur=NULL;
void insert(int x){

        struct linked *ne=(linked *)malloc(sizeof(struct linked));
        ne->data=x;
        ne->next=NULL;
        cur->next=ne;
        cur=ne;
    }
void deleteFirst(){
    cur=head;
    head=head->next;
    free(cur);

}
void display(){
    while(cur!=NULL){
        cout<<cur->data;
        cur=cur->next;
    }
}


int main(){
    struct linked *head= NULL;
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
     cur=head;
     display();
     deleteFirst();

}
