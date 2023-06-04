#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<math.h> 
#include<string.h> 
#include<iomanip> 
using namespace std; 
class node
{
public:
int data;
node * lptr;
node * rptr;
};
class BST
{
public:
node * create_root(int key)
{
node * root = new node; root->data=key; root->lptr=NULL; root->rptr=NULL;
return root;
}
void insert(int key,node * root) {
node * newnode = new node; newnode->data=key; newnode->lptr=NULL; newnode->rptr=NULL; if(key<root->data)
{
if(root->lptr==NULL)
{
root->lptr=newnode;
}
else
{
insert(key,root->lptr);
}
}

else if(root->data<key) {
if(root->rptr==NULL)
{
root->rptr=newnode; }
else
{ insert(key,root->rptr); }
}
else
{
cout<<"Duplicate data not allowed"<<endl; }
}
void search(int key,node * root)
{
if(key==root->data)
{
cout<<"Search Found!!!!"<<endl;
}
else if(key<root->data)
{
if(root->lptr==NULL)
{
cout<<"Search Not Found!!!!"<<endl;
}
else
{
search(key,root->lptr);
}
}
else if(root->data>key)
{
if(root->rptr==NULL)
{
cout<<"Search Not Found!!!!"<<endl;
}
else
{
search(key,root->rptr);
}
}

}
void inorder(node * root)
{
if(root!=NULL)
{
inorder(root->lptr);
cout<<root->data<<" ";
inorder(root->rptr);
}
}
void preorder(node * root)
{
if(root!=NULL)
{
cout<<root->data<<" ";
preorder(root->lptr);
preorder(root->rptr);
}
}
void postorder(node * root)
{
if(root!=NULL)
{
postorder(root->lptr);
postorder(root->rptr);
cout<<root->data<<" ";
}
}
void descorder(node * root)
{
if(root!=NULL)
{
postorder(root->rptr);
cout<<root->data<<" ";
postorder(root->lptr);
}
}
void find_min(node * root)
{
while(root->lptr!=NULL)
{
root=root->lptr;
}
cout<<"Minimum Value is "<<root->data<<endl;

}
void swap_nodes(node * root)
{
if(root==NULL)
return;
node * temp;
temp=root->lptr; root->lptr=root->rptr; root->rptr=temp; swap_nodes(root->lptr); swap_nodes(root->rptr);
}
int long_path(node * root)
{
if(root==NULL)
return 0;
int lptr = long_path(root->lptr);
int rptr = long_path(root->rptr); if(lptr>rptr)
{
return (lptr+1);
}
else
{
return (rptr+1);
}
}
};
using namespace std;
int main()
{
node * root = NULL;
BST bst;
int choice;
int key,skey;
while(1)
{
cout<<"1) Insert"<<endl;
cout<<"2) Search"<<endl;
cout<<"3) Inorder"<<endl;
cout<<"4) Preorder"<<endl; 
cout<<"5) Postorder"<<endl; 
cout<<"6) Descending Order"<<endl;
cout<<"7) Find minimum value"<<endl; 
cout<<"8) Swap left and right nodes"<<endl; 
cout<<"9) Longest path"<<endl; 
cout<<"10) exit"<<endl;
cout<<"Enter your Choice: ";
cin>>choice;
switch(choice)
{
case 1:
cout<<"Enter the Number to be added in BST"<<endl; cin>>key;
if(root==NULL)
{
root=bst.create_root(key);
}
else
{
bst.insert(key,root);
}
break;
case 2:
cout<<"Enter the Number to be searched in BST"<<endl; cin>>skey;
bst.search(skey,root);
break;
case 3:
bst.inorder(root);
break;
case 4:
bst.preorder(root);
break;
case 5:
bst.postorder(root);
break;
case 6:
bst.descorder(root);
break;
case 7:
bst.find_min(root);
break;
case 8:
bst.swap_nodes(root);
break;
case 9:
cout<<"Longest Path is"<<bst.long_path(root);

break;
case 10:
exit(1);
break;
default:
cout<<"Invalid Choice"; }
}
return 0; }