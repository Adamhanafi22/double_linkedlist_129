#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int noMhs;
	string name;
	Node* next;
	Node* prev;

};

class DoubleLinkedlist {
private:
	Node* START;
public:
	DoubleLinkedlist();
	void addnode();
	bool search(int rollno, Node** previous, Node** current);
	bool deletenode(int ro11on);
	bool listEmpty();
	void traverse();
	void revtraverse();
	void hapus();
	void searchdata();
};

DoubleLinkedlist::DoubleLinkedlist() {
	START = NULL;
}

void DoubleLinkedlist::addnode() {
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student:";
	cin >> nim;
	cout << "\nEnter the name of the student:";
	cin >> nm;
	Node* newNode = new Node(); //step 1
	newNode->noMhs = nim; // step 2
	newNode->name = nm; // step 2

	//"insert a node in the beginner of a doubly - linked list"/
	if (START == NULL || nim <= START->noMhs) {
		if (START != NULL && nim == START->noMhs) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = START; //step 3
		if (START != NULL)
			START->prev = newNode; //stepp 4
		newNode->prev = NULL; //step 5
		START = newNode; // step 6
		return;
		
	}
	//*inserting a node between two Nodes in the list*
	Node* current = START; //step 1.a
	Node* previous = NULL; //step 1.b
	while (current->next != NULL && current->next->noMhs < nim) //step 1.c
	{
		previous = current; // 1.d
		current = current->next; //1.e
	}
	if (current->next != NULL && nim == current->next->noMhs) {
		cout << "\nDuplicate roll number not allowed" << endl;
		return;

	}
	newNode->next = current->next; //step 4
	newNode->prev = current; //step 5
			
}

bool DoubleLinkedlist::search(int rollNo, Node** previous, Node** current) {
	*previous = START; // step 1.a
	*current = START; // step 1.b
	while (*current != NULL && rollNo != (*current)->noMhs) { // step 1.c
		*previous = *current; // step 1.d
		*current = (*current)->next; //step 1.e
	}
	return (*current != NULL);
}

bool DoubleLinkedlist::deletenode(int rollNo) {
	Node* previous, * current;
	previous = current = NULL;
	if (search(rollNo, &previous, &current) == false)
		return false;
	if (current->next != NULL)
		current->next->prev = previous; //step 2
	if (previous != NULL)
		previous->next = current->next; //step 3
	else
		START = current->next;

	delete current; //step 4
	return true;
}
bool DoubleLinkedlist::listEmpty() {
	return (START == NULL);
}
void DoubleLinkedlist::traverse() {
	if (listEmpty())
		cout << "\nList is empty" << endl;
	else {
		cout << "\nRecords in ascending order or roll number are:" << endl;
		Node* currentNode = START;
		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
	}	
}
void DoubleLinkedlist::revtraverse() {
	if (listEmpty()) {
		cout << "\nList is empty" << endl;

	}
	else {
		cout << "\nRecords in descending order of roll number are:" << endl;
		Node* currentNode = START;
		while (currentNode->next != NULL)
			currentNode = currentNode->next;
		
		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->name << endl;
			currentNode = currentNode->prev;
		}
	}
}

void DoubleLinkedlist::hapus() {
	if (listEmpty()) {
		cout << "\nlist is empty " << endl;

	}
	cout << "\nEnter the roll number of the student record is to be deleted:";
	int rollNo;
	cin >> rollNo;
	cout << endl;
	if (DoubleLinkedlist::deletenode(rollNo) == false)
		cout << " Records with roll number" << endl;
	else
		cout << "Records with roll number " << rollNo << " deleted" << endl;
}
void DoubleLinkedlist::searchdata() {
	if (listEmpty() == true) {
		cout << "\nlist is empty" << endl;

	}
	Node* prev, * curr;
	prev = curr = NULL;
	cout << "\nEnter the roll number student whosse record you want to search : ";
	int num;
	cin >> num;
	if (DoubleLinkedlist::search(num, &prev, &curr) == false)
		cout << "\nRecord not found" << endl;

	else {
		cout << "\nRecord found" << endl;
		cout << "\nRoll number:" << curr->noMhs << endl;
		cout << "\nname:" << curr->name << endl;
	}
}
int main() {
	DoubleLinkedlist obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all records in the ascending order of roll numbers" << endl;
			cout << "4. View all records in the descending order of roll numbers" << endl;
			cout << "5. Search for a record in the list" << endl;
			cout << "6. Exit" << endl;
			cout << "\nEnter your choice (1-6): ";
			char ch;
			cin >> ch;

			switch (ch) {
			case '1':
				obj.addnode();
				break;
			case '2':
				obj.hapus();
				break;
			case '3':
				obj.traverse();
				break;
			case '4':
				obj.revtraverse();
				break;
			case '5':
				obj.searchdata();
				break;
			case '6':
				return 0;
			default:
				cout << "\nInvalid option" << endl;
				break;
			}
		}
		catch (exception& e) {
			cout << "Check for the values entered." << endl;
		}
	}
}