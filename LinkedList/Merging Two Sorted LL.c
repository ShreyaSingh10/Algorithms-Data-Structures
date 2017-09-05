#include <bits/stdc++.h>

using namespace std;
struct linked {
    int data;
    struct linked *next;
};
struct linked *cur=NULL;
struct linked *head1= NULL;
struct linked *head2= NULL;
struct linked *head3= NULL;
void insert(int x){
    struct node *ne=(struct node *)malloc(sizeof(struct node));
	ne->data=x;
	ne->next=NULL;
	if(head==NULL){
		head=ne;
	}
	else{
		temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
	temp->next=ne;
	}
}
void display(){
    while(cur!=NULL){
        cout<<cur->data;
        cur=cur->next;
    }
}

void merge(){
    struct linked *cur1=NULL;
    struct linked *cur2=NULL;
    struct linked *cur3=NULL;
    struct linked *ne;
    head3=NULL;
    cur1=head1;cur2=head2;cur3=head3;

    while(cur1 && cur2){
        ne=(linked *)malloc(sizeof(struct linked));
        ne->next=NULL;
        if(cur1->data > cur2->data){
            ne->data=cur2->data;
            cur2=cur2->next;
        }
        else if(cur2->data > cur1->data){
            ne->data=cur1->data;
            cur1=cur1->next;
        }
        if(head3==NULL){
            cur3=head3=ne;
        }
        else if(head3!=NULL){
            cur3->next=ne;
            cur3=ne;
        }
    }
    if(cur1){
        cur3->next=cur1;
    }
    if(cur2){
        cur3->next=cur2;
    }
}

int main(){
    int x,n;
    cin>>x;
    cin>>n;
    cur=head1;
    for(int i=0;i<=n;i++){
        cin>>x;
        insert(x);
    }
    cur=head2;
    for(int i=0;i<=n;i++){
        cin>>x;
        insert(x);
    }
    merge();
    cur=head3;
    display();
    cout<<endl;
    }
