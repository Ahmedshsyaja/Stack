#include<iostream>
using namespace std;
class IntStack {
	int *stackArray;
	int stackSize;
	int top;
public:
	IntStack(int size) {
		this->top = -1;
		this->stackArray = new int[size];
		this->stackSize = size;
		for (int i = 0; i < size; i++) {
			stackArray[i] = -1;
		}
	}
	void Push(int data) {
		if (this->top != this->stackSize-1) {
			this->top = this->top + 1;
			this->stackArray[this->top] = data;
		}
		else {
			cout << "Your Stack is Full";
			cout << endl;
			cout << "---------------------------";
			cout << endl;
		}
	}
	int Pop() {
		int x = 0;
		if (this->top == -1) {
			cout << "Your Stack Empty  Can't pop";
			cout << endl;
			cout << "---------------------------";
			cout << endl;
		}
		else {
			x = this->stackArray[this->top];
			this->stackArray[this->top] = -1;
			this->top = this->top - 1;
			return x;
		}
	}
	bool isEmpty() {
		if (this->top == -1) {
			return false;
		}
		else {
			return true;
		}
	};
	bool isFull() {
		if (this->top == this->stackSize - 1) {
			return true;
		}
		else {
			return false;
		}
	}
	int Retrun_Top() {
		return this->stackArray[this->top];
	}
	void Dispaly() {
		for (int i = this->top; i >= 0; i--) {
			cout << this->stackArray[i];
			cout << endl;
		}
	}
};
int main() {
	int size=10;
	IntStack l1(size);
	while (1) {
		cout << "Enter 1 To for is Empty";
		cout << endl;
		cout << "---------------------------";
		cout << endl;
		cout << "Enter 2 To for is Full";
		cout << endl;
		cout << "----------------------------";
		cout << endl;
		cout << "Enter 3 To push";
		cout << endl;
		cout << "----------------------------";
		cout << endl;
		cout << "Enter 4  To pop";
		cout << endl;
		cout << "----------------------------";
		cout << endl;
		cout << "Enter 5  To return Top Element";
		cout << endl;
		cout << "----------------------------";
		cout << endl;
		cout << "Enter 6  To Display Content";
		cout << endl;
		cout << "----------------------------";
		cout << endl;
		cout << "Enter 7  To Break";
		cout << endl;
		cout << "----------------------------";
		cout << endl;
		int button;
		cin >> button;
		if (button == 1) {
			bool p=l1.isEmpty();
			if (p == true) {
				cout << "Your Stcak is not ";
				cout << endl;
				cout << "----------------------------";
				cout << endl;
			}
			else {
				cout << "Your Stack is  Empty";
				cout << endl;
				cout << "----------------------------";
				cout << endl;
			}
		}
		if (button == 2) {
			bool p = l1.isFull();
			if (p == true) {
				cout << "Your Stcak is full ";
				cout << endl;
				cout << "----------------------------";
				cout << endl;
			}
			else {
				cout << "Your Stack is  not full";
				cout << endl;
				cout << "----------------------------";
				cout << endl;
			}
		}
		if (button == 3) {
			cout << "Enter Data to Push";
			cout << endl;
			cout << "----------------------------";
			cout << endl;
			int data;
			cin >> data;
			l1.Push(data);
		}
		if (button == 4) {
			cout << "Data After pop";
			cout << endl;
			cout << "----------------------------";
			cout << endl;
			cout<<l1.Pop();
			cout << endl;
		}
		if (button == 5) {
			cout << "Data At Top";
			cout << endl;
			cout << "----------------------------";
			cout << endl;
			cout << l1.Retrun_Top();
			cout << endl;
		}
		if (button == 6) {
			cout << "Your Data";
			cout << endl;
			cout << "----------------------------";
			cout << endl;
			l1.Dispaly();
		}
		if (button == 7) {
			break;
		}
	}
	system("pause");
	return 0;
}
