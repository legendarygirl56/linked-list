#include<bits/stdc++.h>
using namespace std;
class node
{
	public:
	int data;
	node *next;
};
void insert(node ** head,int n)
{
	node *nn=new node();
	nn->data=n;
	node *t=*head;
	if(*head==NULL)
	{
	*head=nn;
	nn->next=nn;
//	t->data=n;
	//t->next=t;
	}
	else
	{
		while(t->next!=*head)
		{
			t=t->next;
		}
		t->next=nn;
		nn->next=*head;
		*head=nn;
	}
}
void display(node ** head)
{
	node *t=*head;
    do
	{
		cout<<(t->data)<<" ";
		t=t->next;
	}
	while(t!=*head);
}
void split(node ** head)
{
	node *sp=*head;
	node *fp=*head;
	while(fp->next!=*head && fp->next->next!=*head)
	{
		fp=fp->next->next;
		sp=sp->next;
	}
	if(fp->next!=*head)
	{
		fp=fp->next;
	}
	fp->next=sp->next;
	sp->next=*head;
	node *head1=*head;
	node *head2=fp->next;
	display(&head1);
	cout<<endl;
	display(&head2);
}
void sort_insert(node ** head,int l)
{
	node *w=new node();
	w->data=l;
	node *t=*head;
	if(*head==NULL)
	{
		*head=w;
		w->next=w;
	}
	else if((t->next->data)<l)
	{
		while((t->next->data)<l)
	{
		t=t->next;
	}
	w->next=t->next;	
	t->next=w;
	}
}
void count(node ** head)
{
	int c=0;
	node *t=*head;
	  do
	{
		c++;
		t=t->next;
	}
	while(t!=*head);
	cout<<"number of nodes are "<<c<<endl;
}
void del(node ** head,int o)
{
	node *t=*head;
	if(t->data==o)
	{
		*head=t->next;
	}
	else
	{
		while(t->next->data!=o)
	{
		t=t->next;
	}
	t->next=t->next->next;
	}

}
int main()
{
	int m,i,n;
	cout<<"Enter the size of circular ll"<<endl;
	cin>>m;
	node *head=NULL;
	for(i=0;i<m;i++)
	{
	cin>>n;
	insert(&head,n);	
	}
	display(&head);
	cout<<endl;
	cout<<"Enter the value to insert in sorted linked list"<<endl;
	int l,o;
	cin>>l;
	sort_insert(&head,l);
	display(&head);
	cout<<endl;
	count(&head);
	cout<<endl;
	cout<<"enter the value to be deleted"<<endl;
	cin>>o;
	del(&head,o);
	display(&head);
	cout<<endl;
	cout<<"the two splited linked list are:"<<endl;
	split(&head);
}
