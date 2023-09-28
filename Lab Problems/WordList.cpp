#include<iostream>
using namespace std;

struct node
{
	string data;
	node* link;
};

struct head
{
	int count;
	node* first;
};

class WordList
{
	private:
		head* slink;
	public:
		WordList()
		{
			slink->count=0;
			slink->first=NULL;
		}

		bool InsertEnd(string word)
		{
			node* newnode = new node;
			if(newnode==NULL)
			{
				cout<<"Linked List is Full"<<endl;
				return false;
			}
			else
			{
				newnode->data = word;
				if(slink->count == 0)
				{
					slink->first = newnode;
					(slink->count)++;
				}
				else
				{
					node* temp = slink->first;
					while(temp->link!=NULL)
					{
						temp=temp->link;
					}
					temp->link = newnode;
					(slink->count)++;
				}
				return true;
			}
		}
		int DeleteWords()
		{
			if(slink->count==0)
			{
				return 0;
			}
			else
			{
				int nwords = slink->count;
				node* temp = slink->first->link;
				node* ppre = slink->first;
				while(ppre!=NULL)
				{
					ppre->link = temp->link;
					temp = temp->link;
				}
				(slink->count)=0;
				slink->first = NULL;
				return nwords;
			}
		}
		bool InsertListAfter(string word, WordList myList) 
		{ 
 			//The list of words from myList need to be inserted after “word” in invoking list
 			bool found = false;
 			node* temp = slink->first;
 			while(temp != NULL)
 			{
 				if(temp->data == word)
 				{	
 					found = true;
 					node* next = temp->link;
 					temp->link = myList.slink->first;
 					node* listLast = myList.slink->first;
 					while(listLast->link!=NULL)
 					{
 						listLast = listLast->link;
 					}
 					listLast->link=next;
 					slink->count= slink->count + myList.slink->count;
 					return found;
 				}
 				temp=temp->link;
 			}
 			return found;
		}
		void Display() 
		{ 
 			//Should display the words from the list, separated by a space
 			if(slink->count == 0)
 			{
 				cout<<"linked list is empty"<<endl;
 			}
 			else
 			{
 				node* temp=slink->first;
 				while(temp != NULL)
 				{
 					cout<<temp->data<<" ";
 					temp=temp->link;
 				}
 			}
		}  
};
int main()
{
	string word;
	WordList w1;
	WordList w2;
	bool success;

	while(true)
	{
		int ch;
		cout<<"Enter Operation to be performed : \n\t1.InsertEnd1\n\t2.InsertEnd2\n\t3.DeleteWords\n\t4.InsertListAfter\n\t5.Display\n\t6.Exit";
		cin>>ch;
		if (ch==1)
		{
			cout<<"enter the word to be inserted : ";
			cin>>word;
			success = w1.InsertEnd(word);
			if(success==true)
			{
				cout<<"inserted successfully."<<endl;
			}
			else{cout<<"not inserted"<<endl;}
		}
		if (ch==2)
		{
			cout<<"enter the word to be inserted : ";
			cin>>word;
			success = w2.InsertEnd(word);
			if(success==true)
			{
				cout<<"inserted successfully."<<endl;
			}
			else{cout<<"not inserted"<<endl;}
		}
		else if (ch==3)
		{
			int nwords = w1.DeleteWords();
			cout<<nwords<<" has been deleted from the WordList"<<endl;
		}
		else if (ch==4)
		{
			cout<<"enter the word to insert the list 2 after : ";
			cin>>word;
			success = w1.InsertListAfter(word, w2);
			if(success==true)
			{
				cout<<"inserted successfully."<<endl;
			}
			else{cout<<"not inserted"<<endl;}
		}
		else if (ch==5)
		{
			w1.Display();
			cout<<endl;
			w2.Display();
		}
		else if (ch==6)
		{
			exit(0);
		}
		else{cout<<"enter valid input"<<endl;}

	}
}