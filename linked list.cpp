#include<bits/stdc++.h>
using namespace std;
class node
{
	public:
	int data;
	node * next;
};
void insert(node ** head,int d)
{
	node*nnod=new node();
	nnod->data=d;
	nnod->next=NULL;
	node *l=*head;
	if(*head==NULL)
	{
		*head=nnod;
	}
	else
	{
		while(l->next!=NULL)
	{
		l=l->next;
	}
	l->next=nnod;	
	}	
}
void display(node **head)
{
	node *l=*head;
	while(l!=NULL)
	{
		cout<<l->data<<" ";
		l=l->next;
	}
}
void length(node ** head)
{
	node *l=*head;
	int c=0;
	while(l!=NULL)
	{
		c++;
		l=l->next;
	}
	cout<<c<<endl;
}
void search(node ** head,int m)
{
	node *l=*head;
	while(l->data!=m)
	{
	l=l->next;	
	}
	if(l->data==m)
	cout<<"yes element is present"<<endl;
	else
	cout<<"not present"<<endl;	
}
void mid_val(node ** head)
{
	node *sp=*head;
	node *fp=*head;
	while((fp->next->next!=NULL) && (fp->next!=NULL) )
	{
	fp=fp->next->next;
	sp=sp->next;	
	}
	cout<<"mid value is "<<sp->data<<endl;
}
void detect_loop(node**head)
{
	node *l=*head;
	set<node *> s;
	while(l!=NULL)
	{
	if(s.find(l)!=s.end())
	{
	cout<<"Yes loop is present"<<endl;	
	return;
	}
	else
		l=l->next;
	}
	cout<<"loop not present"<<endl;	
}
void palindrome(node ** head)
{
	stack<int> s;
	node *l=*head;
	while(l!=NULL)
	{
		s.push(l->data);
		l=l->next;
	}
	l=*head;
	while(l!=NULL)
	{
		if(s.top()!=l->data)
		{
		return;	
		}
		s.pop();
		l=l->next;
	}
	cout<<"yes palindrome"<<endl;
}
void rem_dupli(node ** head)
{
	int max=-1;
	node *l=*head;
	while(l!=NULL)
	{
		if((l->data)>max)
		{
			max=l->data;
		}
		l=l->next;
	}
	int a[max+1]={0};
	l=*head;
	node * prev=*head;
	while(l!=NULL)
	{
		if(a[l->data]==0)
		{
			a[l->data]=1;
			prev=l;
			l=l->next;
		}
		else
		{
			prev->next=l->next;
			free(l);
			l=prev->next;
		}
		
	}
}
void reverse(node ** head)
{
	node *prev=*head;
	node *current=prev->next;
	node *nex=current->next;
	node *l=*head;
	while (current != NULL) { 
            nex = current->next; 
            current->next = prev; 
            prev = current; 
            current = nex; 
        } 
	l->next=NULL;
	*head=prev;
}
void intersection(node ** head,node ** head1)
{
	node *l=*head;
	node *m=*head1;
	while(l!=NULL && m!=NULL)
	{
		if((l->data)==(m->data))
		{
			cout<<(l->data)<<" ";
			l=l->next;
			m=m->next;
		}
		else if((l->data)<(m->data ))
		{
			l=l->next;
		}
		else
		m=m->next;
	}
}
int main()
{
	int n,i,x;
	cin>>n;
	node *head=NULL;
	for(i=0;i<n;i++)
	{
		cin>>x;
		insert(&head,x);
	}
	display(&head);
//	cout<<endl;
//	length(&head);
//	int m;
//	cout<<"enter the element to be searched"<<endl;
//	cin>>m;
//	search(&head,m);
////	mid_val(&head);
//	detect_loop(&head);
//	palindrome(&head);
//	rem_dupli(&head);
//	display(&head);
//	reverse(&head);
//	display(&head);
//	cout<<endl;
	cout<<"enter the size of 2nd ll"<<endl;
	int p;
	cin>>p;
	node *head1=NULL;
	for(i=0;i<p;i++)
	{
		cin>>x;
		insert(&head1,x);
	}
	intersection(&head, &head1);
}
