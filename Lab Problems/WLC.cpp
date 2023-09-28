#include <iostream>
#include <cstdlib>  // for exit function
using namespace std;

struct Node {
    string data;
    Node* link;
};

struct Head {
    int count;
    Node* first;
};

class WordList {
private:
    Head* slink;

public:
    WordList() {
        slink = new Head();
        slink->count = 0;
        slink->first = nullptr;
    }

    bool InsertEnd(string word) {
        Node* newnode = new Node;
        if (newnode == nullptr) {
            cout << "Linked List is Full" << endl;
            return false;
        } else {
            newnode->data = word;
            newnode->link = nullptr;

            if (slink->count == 0) {
                slink->first = newnode;
            } else {
                Node* temp = slink->first;
                while (temp->link != nullptr) {
                    temp = temp->link;
                }
                temp->link = newnode;
            }

            slink->count++;
            return true;
        }
    }

    int DeleteWords() {
        int nwords = slink->count;
        Node* temp = slink->first;
        Node* next;

        while (temp != nullptr) {
            next = temp->link;
            delete temp;
            temp = next;
        }

        slink->count = 0;
        slink->first = nullptr;
        return nwords;
    }

    bool InsertListAfter(string word, WordList myList) {
    bool found = false;
    Node* temp = slink->first;

    while (temp != nullptr) {
        if (temp->data == word) {
            found = true;
            Node* next = temp->link;
            temp->link = myList.slink->first;

            Node* listLast = myList.slink->first;
            while (listLast->link != nullptr) {
                listLast = listLast->link;
            }

            listLast->link = next;
            slink->count += myList.slink->count;

            return found;
        }

        temp = temp->link;
    }

    return found;
}


    void Display() {
        if (slink->count == 0) {
            cout << "Linked list is empty" << endl;
        } else {
            Node* temp = slink->first;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->link;
            }
            cout << endl;
        }
    }

    ~WordList() {
        Node* temp = slink->first;
        Node* next;

        while (temp != nullptr) {
            next = temp->link;
            delete temp;
            temp = next;
        }

        delete slink;
    }
};

int main() {
    string word;
    WordList w1;
    WordList w2;
    bool success;

    while (true) {
        int ch;
        cout << "Enter Operation to be performed : \n\t1.InsertEnd1\n\t2.InsertEnd2\n\t3.DeleteWords\n\t4.InsertListAfter\n\t5.Display\n\t6.Exit";
        cin >> ch;
        if (ch == 1) {
            cout << "enter the word to be inserted : ";
            cin >> word;
            success = w1.InsertEnd(word);
            if (success) {
                cout << "inserted successfully." << endl;
            } else {
                cout << "not inserted" << endl;
            }
        } else if (ch == 2) {
            cout << "enter the word to be inserted : ";
            cin >> word;
            success = w2.InsertEnd(word);
            if (success) {
                cout << "inserted successfully." << endl;
            } else {
                cout << "not inserted" << endl;
            }
        } else if (ch == 3) {
            int nwords = w1.DeleteWords();
            cout << nwords << " words have been deleted from the WordList" << endl;
        } else if (ch == 4) {
            cout << "enter the word to insert the list 2 after : ";
            cin >> word;
            success = w1.InsertListAfter(word, w2);
            if (success) {
                cout << "inserted successfully." << endl;
            } else {
                cout << "not inserted" << endl;
            }
        } else if (ch == 5) {
            cout << "Word List 1: ";
            w1.Display();
            cout << "Word List 2: ";
            w2.Display();
        } else if (ch == 6) {
            exit(0);
        } else {
            cout << "enter valid input" << endl;
        }
    }

    return 0;
}
