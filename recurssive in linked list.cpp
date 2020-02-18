#include<bits/stdc++.h>
using namespace std;
class node
{
	public:
	int data;
	node * next;
};
void push(node ** head,int x)
{
	node * nn=new node();
	nn->data=x;
	nn->next=NULL;
 node *t=*head;
 if(*head==NULL)
 {
 	*head=nn;
 }
 else
 {
 	while(t->next!=NULL)
 	{
 	t=t->next;	
	}
	t->next=nn;
 }
}
int recu_count(node * head)
{
	if(head==NULL)
	return 0;
	else
	return 1+recu_count(head->next);
}
void recu_reverse(node * head)
{
	if(head==NULL)
	return;
  recu_reverse(head->next);
 	cout<<(head->data)<<" ";
}
void recu_search(node * head,int y)
{
	if(head==NULL)
	{
	return;	
	}
	if(head->data==y)
	{
		cout<<"element found";
		return;
	}
 recu_search(head->next,y);
}
void recu_removedupli(node * head)//list is sorted
	{
		if(head==NULL)
		{
			return ;
		}
		if(head->next!=NULL)
		{
		if((head->data)==(head->next->data))
		{
			head->next=(head->next->next);
		     recu_removedupli(head);	
		}
		else
		{
		  recu_removedupli(head->next);		
		}
	   }
	}
	void display(node * head)
	{
	node *t=head;
	while(t!=NULL)
	{
		cout<<(t->data)<<" ";
		t=t->next;
	}
	}
	node * recu_rev(node * head,int k)//k element reverse and then skip k elements then again reverse k elements n so on
	{
		node * prev=NULL;
		node *current=head;
		node * nex;
		int c=0;
		while(c<k && current!=NULL)
		{
			nex=current->next;
			current->next=prev;
			prev=current;
			current=nex;
			c++;
		}
		if(head!=NULL)
		{
			head->next=current;
		}
		c=0;
		while(c<(k-1)&& current!=NULL)
		{
			current=current->next;
			c++;
		}
		if(current!=NULL)
	     current->next=recu_rev(current->next,k);
	     return prev;
	}
	node * add_two(node * head, node * head1)
	{
		node * headf=NULL;
		int carry=0;
		node * tem=head;
		node * temp1=head1;
		while(tem!=NULL && temp1!=NULL)
		{
			if((tem->data) + (temp1->data)+carry>=10)
			{
				
				push(&headf,(((tem->data) + (temp1->data)+carry)%10));
				carry=1;
			}
			else
			{
				push(&headf,((tem->data) + (temp1->data)+carry)%10);
				carry=0;
			}
			tem=tem->next;
			temp1=temp1->next;
		}
		return headf;
	}
void pair_wiseswap(node * head)
	{
		int t;
	  if(head!=NULL && head->next!=NULL )
	  {
	    t=head->data;
	    head->data=head->next->data;
	    head->next->data=t;
	  	pair_wiseswap(head->next->next);
	  }	
	}
int main()
{
	node *head=NULL;
	push(&head,5);
	push(&head,6);
	push(&head,1);
	push(&head,25);
//	push(&head,45);
	//push(&head,35);
	display(head);
//	cout<<endl;
//	cout<<recu_count(head)<<endl;
//	recu_search(head,25);
//	recu_removedupli(head);
//	display(head);
//	cout<<endl;
//	recu_reverse(head);
//	int k;
//	cout<<"enter a number till which ll needs to be reversed";
//	cin>>k;
//	head=recu_rev(head,k);
//	display(head);
	//pair_wiseswap(head);//recursive
//	display(head);
}
