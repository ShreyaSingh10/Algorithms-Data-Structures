#include <bits/stdc++.h>
using namespace std;

struct node {
	int data;
	struct node *next;
};
struct node *head=NULL;
struct node *temp=head;
void insert(int x){
	struct node *ne=(struct node *)malloc(sizeof(struct node));
	ne->data=x;
	if(head==NULL){
		head=ne;
		ne->next=head;
	}
	else{
		temp=head;
		while(temp->next!=head){
			temp=temp->next;
		}
	temp->next=ne;
	ne->next=head;
	}

}
void display(){
	temp=head;
	while(temp->next!=head){
		cout<<temp->data<<endl;
		temp=temp->next;
	}
}
void loop(){
    int p=1;
	struct node *slow=NULL;
	struct node *fast=NULL;
	slow=fast=head;
	while(fast->next!=slow->next && fast->next!=NULL){
        if(p=1){
            fast=fast->next;
            p=0;
        }
        if(p==0){
            slow=slow->next;
            fast=fast->next->next;
            p=1;
		}
	}
	cout<<"Loop Exists"<<endl;
	slow=head;
	while(fast->next!=slow->next){
		slow=slow->next;
		fast=fast->next;
	}
	cout<<"beginning of loop:"<<slow->data<<endl;

}
int main() {
	// your code goes here
	struct node *head=(struct node *)malloc(sizeof(struct node));
	int x;
	for(int i=0;i<=10;i++){
		cin>>x;
		insert(i);
	}
	//temp->next=head;
	display();
	loop();
}
