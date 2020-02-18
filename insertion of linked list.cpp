#include<bits/stdc++.h>
using namespace std;
class node
{
	public:
	int data;
	node *next;
};
void add_node(node ** head,int n)//inserts at the front
{
	node *temp=new node;
	temp->data=n;
	temp->next=*head;
	*head=temp;
}
void add(node ** head,int n)
{
	node *temp=new node();
	node *l=*head;
	temp->data=n;
	temp->next=NULL;
	if(*head==NULL)
	{
		*head=temp;
	}
	else
	{
		while(l->next!=NULL)
      {
	   l=l->next;
      }	
      l->next=temp;
	}
}
void display(node ** k)
{
	while((*k)!=NULL)
	{
		cout<<(*k)->data<<" ";
		(*k)=(*k)->next;
	}
}
void display2(node * k)//another way to display(pass only head)
{
	while((k)!=NULL)
	{
		cout<<(k)->data<<" ";
		(k)=(k)->next;
	}
}
int main()
{
int n,i,x;
node *head=NULL;
cin>>n;	
for(i=0;i<n;i++)
{
	cin>>x;
	add(&head, x);
}
display(&head);
int y;
cin>>y;
//del(&head,y);
display(&head);
//display2(head);(another way)
}
