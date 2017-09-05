//DELETING THE FIRST NODE -MAKE HEAD AND CURRENT GLOBAL
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
     cout<<endl;
     deleteFirst();
}
