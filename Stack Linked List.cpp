#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node* next;
	struct node* prev;
}
*start;
class double_llist
{
private:
	node* head = NULL;
	int top = 0;
	node* current_ptr = NULL;
	int count;
public:
	node* insert_at_begin(int value, node* temp) {
		if (head == NULL) {
			temp = new node;
			temp->data = value;
			head = temp;
			current_ptr = temp;
			temp->next = NULL;
			temp->prev = NULL;
		}
		else {
			current_ptr = temp;
			temp = new node;
			temp->data = value;
			current_ptr->next = temp;
			temp->prev = current_ptr;
			temp->next = NULL;
		}
		return temp;
	}
	node* Pop(node* NODE) {
		node* temp = NODE;
		if (temp == NULL) {
			head = NULL;
			return head;
		}
		temp = temp->prev;
		cout << "Your Data Deleted";
		cout << endl;
		cout << "-----------------";
		cout << endl;
		cout<<NODE->data;
		cout << endl;
		delete NODE;
		if (temp == NULL) {
			head = NULL;
			current_ptr = NULL;
			return head;
		}
		temp->next = NULL;
		return temp;
	};
	void display_dlist() {
		node* Temp = head;
		cout << "Your Data is ";
		cout << endl;
		cout << "-------------------";
		cout << endl;
		while (Temp != NULL) {
			cout << Temp->data << " ";
			Temp = Temp->next;
		}
	}
	bool Empty_Link() {
		if (current_ptr == NULL) {
			return true;
		}
		else {
			return false;
		}
	}
	bool is_empty();
	double_llist()
	{
		head = NULL;
		current_ptr = NULL; //constructor for my class
		count = 0;
	}
	~double_llist() {
		current_ptr = head;
		while (current_ptr != NULL)
		{
			node* next = current_ptr->next;
			delete current_ptr;
			current_ptr = next;
		}
	}
};
int main() {
	node* NODE = NULL;
	double_llist a;
	while (true) {
		cout << "Enter the 1 To push The Data\n";
		cout << "-------------------------------\n";
		cout << "Enter the 2 To Pop \n";
		cout << "-----------------------------------------------\n";
		cout << "Enter the 3 To Check is Empty or not \n";
		cout << "-----------------------------------------------\n";
		cout << "Enter the 4 To Display \n";
		cout << "-----------------------------------------------\n";
		cout << "Enter the 5 To Break \n";
		cout << "-----------------------------------------------\n";
		int in;
		cin >> in;
		if (in == 1) {
			cout << "Enter the Data you want to Insert\n";
			cout << "-----------------------------------------------\n";
			int data1;
			cin >> data1;
			NODE = a.insert_at_begin(data1, NODE);
		}
		if (in == 2) {
			NODE = a.Pop(NODE);
		}
		if (in == 3) {
			bool k = a.Empty_Link();
			if (k == true) {
				cout << "Your Link List is Empty\n";
				cout << "-----------------------------------------------\n";
			}
			else {
				cout << "Your Link List is not Empty\n";
				cout << "-----------------------------------------------\n";
			};
		}
		if (in == 4) {
			a.display_dlist();
			cout << endl;
		}
		if (in == 5) {
			break;
		}
	}
	system("pause");
	return 0;
}
