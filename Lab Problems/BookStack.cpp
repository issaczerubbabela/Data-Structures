#include<iostream>
using namespace std;
class Book
{
	string bookName;
	string authorName;
	int bookNumber;
public:
	Book()
	{}
	Book(string bn, string an, int no)
	{
		bookName = bn;
		authorName =an;
		bookNumber = no;
	}

	void Display()
	{
		cout<<"\nBook name : "<<bookName<<"\nAuthor Name : "<<authorName<<"\nBook number : "<<bookNumber<<endl;
	}

};

struct node
{
	Book book;
	node* link;
};

struct Head
{
	int count;
	node *top;
};


class BookStack
{
	Head* blink;
	public :
	BookStack()
	{
		blink->count = 0;
		blink->top = NULL;
	}

	bool Push(Book newBook)
	{
		node* newnode = new node;
		if(newnode==NULL)
		{
			cout<<"Stack Full\n";
			return false;
		}
		else
		{
			newnode->book = newBook;
			(blink->count)++;
			newnode->link=blink->top;
			blink->top=newnode;
			return true;
		}
	}
	bool Pop(Book &poppedBook)
	{
		if (blink->count == 0)
		{
			return false;
		}
		else
		{
			poppedBook=blink->top->book;
			blink->top=blink->top->link;
			poppedBook.Display();
			(blink->count)--;
			return true;
		}
	}
};

class BookList
{
	private:
		Head* slink;
	public:
		BookList()
		{
			slink->count=0;
			slink->top=NULL;
		}

		bool InsertFrontBook(Book newBook)
		{
			node* newnode = new node;
			if(newnode==NULL)
			{
				cout<<"SLL Full\n";
				return false;
			}
			else
			{
				newnode->book = newBook;
				(slink->count)++;
				newnode->link=slink->top;
				slink->top=newnode;
				return true;
			}
		}

		void display()
		{
			node* temp = slink->top;
			while(temp!=NULL)
			{
				temp->book.Display();
				temp = temp->link;
			}
		}

		void PrintInReverse()
		{
			cout<<"\nPrinting in reverse order\n\n ";
			Book poppedBook;
			BookStack b1;
			node* temp = slink->top;
			while(temp!=NULL)
			{
				b1.Push(temp->book);
				temp = temp->link;
			}
			int t = slink->count;
			while(b1.Pop(poppedBook))
			{
				
			}
		}
};
int main()
{
	
	string bkn;
	string akn;
	int bn;
	BookStack bs;
	BookList bl;
	Book b1;
	Book b;
	
	while(true)
	{
		int ch;
		cout<<"ENTER THE OPERATION TO BE PERFORMED : \n\t1.Push\n\t2.Pop\n\t3. SLLInsert\n\t4.SLLDiplay\n\t5.SLL Reverse\n6.Exit"<<endl;
		cin>>ch;

		
		if(ch == 1)
		{
			cout<<"Enter BookName, AuthorNAme, BookNumber";
			cin>>bkn>>akn>>bn;
			Book b3(bkn,akn,bn);
			bs.Push(b3);
		}
		else if(ch == 2)
		{
			bs.Pop(b);
			
		}
		else if(ch == 3)
		{
			cout<<"Enter BookName, AuthorNAme, BookNumber";
			cin>>bkn>>akn>>bn;
			Book b2(bkn,akn,bn);
			bl.InsertFrontBook(b2);
			
		}
		else if(ch == 4)
		{
			bl.display();
			break;
		}
		else if(ch==5)
		{
			bl.PrintInReverse();
		}
		else if(ch == 6)
		{
			break;
		}
		else
		{
			cout<<"invalid choice"<<endl;
		}
		
	}
}