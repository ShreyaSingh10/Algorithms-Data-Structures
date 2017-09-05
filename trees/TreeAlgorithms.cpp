#include <iostream>
#include <stdio.h>
#include<malloc.h>
using namespace std;

struct tree
{
    int data;
    struct tree *left,*right;
};
void left(struct tree *t, int val)
{
    t->left=(struct tree*)malloc(sizeof(struct tree));
    t->left->data=val;
    t->left->left=NULL;
    t->left->right=NULL;
}
void right(struct tree *t, int val)
{
    t->right=(struct tree*)malloc(sizeof(struct tree));
    t->right->data=val;
    t->right->left=NULL;t->right->right=NULL;
}
void preorder(struct tree *root)
{
    if(root)
    {
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);

    }
}
void structtree()
{
    struct tree *t=(struct tree*)malloc(sizeof(struct tree));
    t->data=1;
    left(t,2);
    right(t,3);
    left(t->left,4);
    right(t->left,5);
    left(t->right,6);
    right(t->right,7);

    preorder(t);
}

int main()
{
    structtree();
    return 0;
}
