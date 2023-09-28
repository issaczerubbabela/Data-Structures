#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* link;
};

struct Head
{
	int count;
	Node* top;
};

struct qHead
{
	int count;
	Node* front;
	Node* rear;
};
class SLL
{
	private:
		Head* slink;
	public:
		SLL()
		{
			slink = new Head;
			slink->count=0;
			slink->top=nullptr;
		}
		bool insert(int n)
		{
			Node* newnode = new Node;
			if(newnode==nullptr)
			{
				cout<<"SLL full"<<endl;
				return false;
			}
			else
			{
				newnode->data = n;
				newnode->link = nullptr;
				Node* temp = slink->top;
				while(temp->link!=nullptr)
				{
					temp=temp->link;
				}
				temp->link=newnode;
				(slink->count)++;
				return true;
			}
		}
		void display()
		{
			if(slink->count==0)
			{
				cout<<"sll empty"<<endl;
			}
			else
			{
				Node* temp = slink->top;
				while(temp->link!=nullptr)
				{
					cout<<temp->data<<" ";
					temp=temp->link;
				}
			}
		}
};
			
		
class StackQueue
{
	private:
		Head* slink;
		qHead* qlink;
	public:
		StackQueue()
		{
			slink = new Head;
			slink->count=0;
			slink->top=nullptr;
			qlink = new qHead;
			qlink->count=0;
			qlink->front=nullptr;
			qlink->rear=nullptr;
		}
		bool Push(int n)
		{
			Node* snode = new Node;
			if(snode==nullptr)
			{
				cout<<"Linked list full"<<endl;
				return false;
			}
			else
			{
				snode->data = n;
				snode->link = slink->top;
				slink->top = snode;
				(slink->count)++;
				return true;
			}
		}
		
		bool enQueue(int n)
{
    Node* qnode = new Node;
    if (qnode == nullptr)
    {
        cout << "Linked list full" << endl;
        return false;
    }
    else
    {
        qnode->data = n;
        qnode->link = nullptr;
        if (qlink->count == 0)
        {
            qlink->rear = qnode;
            qlink->front = qnode;
        }
        else
        {
            qlink->rear->link = qnode;
            qlink->rear = qnode;
        }
        (qlink->count)++;
        return true;
    }
}

bool deQueue(int &n)
{
    if (qlink->count == 0)
    {
        return false;
    }
    else
    {
        n = qlink->front->data;
        Node* temp = qlink->front;
        qlink->front = qlink->front->link;
        delete temp;  // Free the memory
        (qlink->count)--;
        return true;
    }
}
bool Pop(int &n)
    {
        if (slink->count == 0)
        {
            return false;
        }
        else
        {
            n = slink->top->data;
            Node* temp = slink->top;
            slink->top = slink->top->link;
            delete temp;  // Free the memory
            (slink->count)--;
            return true;
        }
    }

void addFirstElement(SLL &sll)
{
    bool aend = true;
    bool bend = true;
    int sum = 0;

    while (aend && bend)
    {
        int a = 0, b = 0;
        aend = Pop(a);
        bend = deQueue(b);
        sll.insert(a + b);
    }
}
			};

int main()
{
	StackQueue sq;
	SLL sll;
	
	while(true)
	{
		int ch;
		cout<<"enter the operation to be performed : \n\t1. insert element into stack and queue\n\t2. Add first elements\n\t3. Display Linked List\n\t4. Exit"<<endl;
		cin>>ch;
		if (ch==1)
		{
			cout<<"Enter the integer to be pushed and queued : ";
			int n;
			cin>>n;
			bool success = sq.enQueue(n);
			if (success == true)
			{
			cout<<"element inserted succesfully"<<endl;
			}
			else
			{cout<<"element not inserted"<<endl;}
		}
		else if (ch==2)
		{
			int a,b;
			sq.addFirstElement(sll);
		}
		else if (ch==3)
		{
			sll.display();
		}
		else if (ch==4)
		{
			break;
		}
		else if (ch==5)
		{
			int m;
			cin>>m;
			bool success = sq.Push(m);
			if (success == true)
			{
			cout<<"element inserted succesfully"<<endl;
			}
			else
			{cout<<"element not inserted"<<endl;}
		}
		else
		{
			cout<<"Enter Valid Input"<<endl;
		}
	}
}
			
