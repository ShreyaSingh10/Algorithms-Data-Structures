#include <iostream>
#include <stdio.h>
#include <malloc.h>
using namespace std;
int maxi=INT_MIN,mini=INT_MAX,a[7]={6,10,14,20,24,28,32},i=0;
struct bst
{
    int data;
    struct bst *left,*right;
};
void bstconstruct(struct bst *t,int val)
{
    struct bst *n=(struct bst*)malloc(sizeof(struct bst));
    n->data=val;
    n->left=NULL;n->right=NULL;
    if(val<t->data)
    t->left=n;
    else if(val>t->data)
    t->right=n;
    //printf("%d ",val);
}
void inorder(struct bst *t)
{
    if(t)
    {
        inorder(t->left);
        printf("%d ",t->data);
        inorder(t->right);
    }
}
int preordersearch(struct bst *t,int num)
{
    if(t)
    {
        int l,r;
        if(t->data==num)
            return 1;
        else if(num<t->data)
        l=preordersearch(t->left,num);
        else
        r=preordersearch(t->right,num);
        if(l==1||r==1)
            return 1;
    }
}
void preordermax(struct bst *t)
{
    if(t)
    {
        if(t->data>maxi)
            maxi=t->data;
        preordermax(t->right);
    }

}
void preordermin(struct bst *t)
{
    if(t)
    {
        if(t->data<mini)
            mini=t->data;
        preordermin(t->left);
    }
}
int bstornot(struct bst *t)
{
    if(t)
    {
        if(t->left->data<t->data && t->right->data>t->data)
            return 1;
        bstornot(t->left);
        bstornot(t->right);
    }
}
void insertit(struct bst *root,int val)
{

     if(root)
     {
         if(val<root->data && root->left!=NULL)
            insertit(root->left,val);
         if(val<root->data && root->left==NULL)
            {
                struct bst *n=(struct bst*)malloc(sizeof(struct bst));
                n->data=val;n->left=NULL;n->right=NULL;
                root->left=n;
            }
         if(val>root->data && root->right!=NULL)
            insertit(root->right,val);
         if(val>root->data && root->right==NULL)
            {
                struct bst *n=(struct bst*)malloc(sizeof(struct bst));
                n->data=val;n->left=NULL;n->right=NULL;
                root->right=n;
            }
          //  printf("%d",val);
     }
}
void deleteit(struct bst *root,int val)
{
if(root)
{
    if(val<root->data && root->left->data!=val)
        deleteit(root->left,val);
    if(val<root->data && root->left->data==val)
    {
        if(root->left->right!=NULL)
        {
            struct bst *temp1=root->left->left;
            root->left=root->left->right;
            struct bst *temp2=root->left;
            while(temp2->left!=NULL)
            {
                temp2=temp2->left;
            }
            temp2->left=temp1;
        }
        else if(root->left->right==NULL)
        {
            root->left=root->left->left;
        }

    }
    if(val>root->data && root->right->data!=val)
        deleteit(root->right,val);
    if(val>root->data && root->right->data==val)
    {
        if(root->right->left!=NULL)
        {
            struct bst *temp1=root->right->right;
            root->right=root->right->left;
            struct bst *temp2=root->right;
            while(temp2->right!=NULL)
            {
                temp2=temp2->right;
            }
            temp2->right=temp1;
        }
    }
}
}
void sortbst(struct bst *root)
{
    if(root)
    {
        sortbst(root->left);
        a[i]=root->data;
        i++;
        sortbst(root->right);
    }
}
void find_kth_el(struct bst *t,int val)
{
    sortbst(t);
    printf("%d",a[val-1]);
}
int lca(struct bst *root,struct bst *a,struct bst *b)
{
    if(root)
    {
        int temp;
      if(root->data>a->data && root->data<b->data)
      {
          //printf("%d",root->data);
        return root->data;
      }
      if(a->data>root->data)
        temp=lca(root->right,a,b);
      if(b->data<root->data)
        temp=lca(root->left,a,b);
        return temp;
    }

}
void bsearch(struct bst *tt,int r,int l)
{
        if(r>l)
            return;
        int mid=(l+r)/2;
        insertit(tt,a[mid]);
        bsearch(tt,r,mid-1);
        bsearch(tt,mid+1,l);
}
void arraytobstbsrch(int r,int l)
{
    int mid=(r+l)/2;
    struct bst *t1=(struct bst*)malloc(sizeof(struct bst));
    t1->data=a[mid];
    t1->left=NULL;
    t1->right=NULL;
    bsearch(t1,r,l);
    inorder(t1);
}
void rangefromk1tok2(struct bst *t,int a,int b)
{
   if(t)
   {
       if(t->data>=a && t->data<=b)
        printf("%d ",t->data);
       rangefromk1tok2(t->left,a,b);
       rangefromk1tok2(t->right,a,b);
   }
}
int bstelementsame(struct bst *t1,struct bst *t2)
{
    if(t1==NULL && t2==NULL)
        return 1;
    if(t1==NULL ||t2==NULL)
        return 0;
    return(t1->data==t2->data ||(t1->left && t2->left)||(t1->right && t2->right))
}
void levelorder(struct node *root)
{
    struct Queue *q=CreateQueue();
    while(1)
    {
        if(!root)
            return;
        q.push(root);
        if(!q.empty())
        {
            int temp=q.front();
            q.pop();
            cout<<temp->data<<endl;
            if(temp->left)
            q.push(temp->left);
            if(temp->right)
            q.push(temp->right);

        }
        break;
    }
}
int main()
{
    struct bst *t=(struct bst*)malloc(sizeof(struct bst));
    t->data=20;
    t->left=NULL;t->right=NULL;
    bstconstruct(t,10);
    bstconstruct(t,28);
    bstconstruct(t->left,6);
    bstconstruct(t->left,14);
    bstconstruct(t->right,24);
    bstconstruct(t->right,32);
    inorder(t);
    //-----------------------------
    int n=preordersearch(t,3);
    if(n==1)
        printf("found");
    else
        printf("not found");
    //-----------------------------
    preordermax(t);
    printf("%d\n",maxi);
    //-----------------------------
    preordermin(t);
    printf("%d\n",mini);
    //-----------------------------
    int c=bstornot(t);
    if(c==1)
        printf("yes\n");
    else
        printf("no\n");
    //-----------------------------
    insertit(t,9);
    inorder(t);
    //inorder to see if the element is inserted
    //-----------------------------
    deleteit(t,10);
    //deleting the element from bst
    inorder(t);
    //checking if element is deleted
    //------------------------------
    sortbst(t);
    find_kth_el(t,3);
    int lc=lca(t,t->right->left,t->right->right);//finding least common ancestor of two elements
    printf("%d",lc);
    arraytobstbsrch(0,6);//converting array into binary search tree
    rangefromk1tok2(t,10,32);//printing elements between a to b inclusive
    bstelementsame(t1,t2);//check if two bst's have same structure
}
