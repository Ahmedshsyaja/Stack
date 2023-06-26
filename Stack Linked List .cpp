#include<iostream>
using namespace std;
struct node
{
	char data;
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
			this->top = this->top + 1;
		}
		return temp;
	}
	node* check(node* NODE) {
		node* Temp = head;
		node *Temp1 = current_ptr;
		Temp1 = Temp1->next;
		int check = this->top / 2;
		int count1 = 0;
		if (check % 2 == 0) {
			while (Temp != NULL) {
				if (Temp->data != Temp1->data) {
					return Temp;
				}
				if (count1 == check) {
					return NULL;
				}
				Temp = Temp->next;
				Temp1 = Temp1->prev;
				count1 = count1 + 1;
			}
		}
		else {
			while (Temp != NULL) {
				if (Temp->data != Temp1->data) {
					return Temp;
				}
				if (count1 == check-1) {
					return NULL;
				}
				Temp = Temp->next;
				Temp1 = Temp1->prev;
				count1 = count1 + 1;
			}
		}
	};
	void display_dlist() {
		node* Temp = this->current_ptr;
		Temp = Temp->next;
		cout << "Your Data is ";
		cout << endl;
		cout << "-------------------";
		cout << endl;
		while (Temp != NULL) {
			cout << Temp->data << " ";
			Temp = Temp->prev;
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
		cout << "Enter the 2 To Check \n";
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
			char data1;
			cin >> data1;
			NODE = a.insert_at_begin(data1, NODE);
		}
		if (in == 2) {
			if (a.check(NODE) != NULL) {
				cout << " NOT plandrome\n";
				cout << "-----------------------------------------------\n";
			}
			else {
				cout << " A plandrome\n";
				cout << "-----------------------------------------------\n";
			}
		}
		if (in == 4) {
			a.display_dlist();
			cout << endl;
		}
	}
	system("pause");
	return 0;
}

