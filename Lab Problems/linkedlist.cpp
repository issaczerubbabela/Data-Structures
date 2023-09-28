#include<iostream>
using namespace std;

struct node
{
	int data;
	node* link;
};

struct head
{
	int count;
	node* link;
};

bool insertNode(int x)
{
	node* newnode = new node();
	if(newnode==NULL)
	{
		return false;
	}
	else
	{

	}
}