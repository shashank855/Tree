#include<stdio.h>
#include<malloc.h>
#define null NULL
int flag;
struct node
{
int data;
struct node *left;
struct node *right;
}*root=NULL,*temp=NULL;

void insert();
void traverse(struct node*);
void search(struct node*);
void infix(struct node*);
void prefix(struct node*);
void postfix(struct node*);
void search_data(struct node*,int);
void search_max(struct node*);
void search_min(struct node*);
int height(struct node*);

void main()
{
int a,n,h;

do
{
printf("\nEnter your Options:");
printf("\n1:insert:");
printf("\n2:traverse:");
printf("\n3:Search Data");
printf("\n4:Search Maximum Element:");
printf("\n5:Search Minimum Element:");
printf("\n6:Height of Tree:");
printf("\n7:Exit");

scanf("%d",&a);
switch(a)
{
case 1:
insert();
break;
case 2:
traverse(root);
break;
case 3:
printf("\nEnter data to search:");
scanf("%d",&n);
search_data(root,n);
if(flag==0)
{
printf("\nData not present");
}
break;
case 4:
search_max(root);
break;
case 5:
search_min(root);
break;
case 6:
h=height(root);
printf("\nHeight of tree is %d",h);
break;
}
}while(a!=7);
}

void insert()
{
int a;
temp=(struct node*)malloc(sizeof(struct node));
printf("\nEnter your Data:");
scanf("%d",&a);
	temp->left=null;
	temp->right=null;
	temp->data=a;
	if(root==null)
	{
	root=temp;
	}
	else
	{
		search(root);
	}
}

void search(struct node* t)
{
	if((temp->data>t->data)&&(t->right==null))
	{
	t->right=temp;
	}
	else if((temp->data>t->data)&&(t->right!=null))
	{
	search(t->right);
	}
	else if((temp->data<t->data)&&(t->left==null))
	{
	t->left=temp;
	}
	else if((temp->data<t->data)&&(t->left!=null))
	{
	search(t->left);
	}
}

void traverse(struct node* t)
{
int a;
	if(root==null)
	{
	printf("\n No elements to display");
	}
	else{
printf("\nEnter your options:");
printf("\n1:prefix");
printf("\n2:postfix");
printf("\n3:infix");
scanf("%d",&a);
switch(a)
{
	case 1:
	prefix(t);
	break;
	case 2:
	postfix(t);
	break;
	case 3:
	infix(t);
	break;
}
		}
}

void prefix(struct node* t)
{
printf("\n%d",t->data);
	if(t->left!=null)
	{
	prefix(t->left);
	}
	if(t->right!=null)
	{
	prefix(t->right);
	}
}

void postfix(struct node* t)
{
	if(t->left!=null)
	{
	postfix(t->left);
	}
	if(t->right!=null)
	{
	postfix(t->right);
	}
printf("\n%d",t->data);
}

void infix(struct node* t)
{
if(t->left!=null)
	{
	infix(t->left);
	}
printf(" \n%d",t->data); //prints the root node
	if(t->right!=null)
	{
	infix(t->right);
	}
}

void search_data(struct node* t, int a)
{
int z=a;
if(root==NULL)
{
printf("\nNo Data to search");
}
else 
{
	if(t!=NULL){
	if((root!=null)&&(t->data==z))
	{
		flag=1;
		printf("\nData Found");
	}
	else if((root!=null)&&(t->data>z))
	{
	search_data(t->left,z);
	}
	else if((root!=null)&&(t->data<z))
	{
	search_data(t->right,z);
	}
	}
	
}
}

void search_max(struct node* t)
{
	if(t==null)
	{
	printf("\nNo data present:");
	}
	else
	{
		while((t->right)!=null)
		{	
			t=t->right;
		}
		printf("\nMaximum Element is %d",t->data);
	}
}

void search_min(struct node* t)
{
	if(root==null)
	{
		printf("\nNo Data Present:");

	}
	else
	{
		while(t->left!=null)
		{
			t=t->left;
		}
		printf("\nMinimum Element is %d",t->data);
	}
}

int height(struct node* t)
{
	int a,b,c;
	if(t==null)
	{
		return -1;
	}
	else
	{
		a=height(t->left);
		b=height(t->right);
		if(a>b)
		{
			c=a;
		}
		else{
			c=b;
		}
		return c+1;
	}
}
