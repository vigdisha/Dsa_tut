#include <stdio.h>
#include <stdlib.h>
struct Node
{
 int data;
 struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;
//third->head of merged linkedlist
void Display(struct Node *p)
{
 while(p!=NULL)
 {
 printf("%d ",p->data);
 p=p->next;
 }
}
void create(int A[],int n)
{
 int i;
 struct Node *t,*last;
 //head node of the 1-ll
 first=new Node;
 first->data=A[0];
 first->next=NULL;
 last=first;

 for(i=1;i<n;i++)
 {
 t=new Node;
 t->data=A[i];
 t->next=NULL;
 last->next=t;
 last=t;
 }
}
void create2(int A[],int n)
{
 int i;
 struct Node *t,*last;
 second=new Node;
 second->data=A[0];
 second->next=NULL;
 last=second;//now last points at the head

 for(i=1;i<n;i++)
 {
 t=new Node;
 t->data=A[i];
 t->next=NULL;
 last->next=t;
 last=t;
 }
}
void Merge(struct Node *p,struct Node *q)
{
 struct Node *last;
 //first we will create a merged linkedlist
 //whose firts node will be sammler node among both
 if(p->data < q->data)
 {
 third=last=p;
 p=p->next;
 third->next=NULL;
 }
 else
 {
 third=last=q;
 q=q->next;
 third->next=NULL;
 }
//now comapre the nodes
//simulatneously add the new nodes

 while(p && q)
 {
 if(p->data < q->data)
 {
 last->next=p;
 last=p;
 p=p->next;
 last->next=NULL;

 }
 else
 {
 last->next=q;
 last=q;
 q=q->next;
 last->next=NULL;

 }
 }
 if(p)last->next=p;
 if(q)last->next=q;

}
int main()
{

 int A[]={10,20,40,50,60};
 int B[]={15,18,25,30,55};
 create(A,5);
 create2(B,5);


 Merge(first,second);
 Display(third);

 return 0;
}