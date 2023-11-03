#include <iostream>
#include <string>
using namespace std;

struct Node {
    string lifo;
    Node* next;
    Node(const string& val) : lifo(val), next(nullptr) {}
};

class Stack {
public:
    Stack() : top(nullptr) {}
    void push(const string& item) {
        Node* newNode = new Node(item);
        newNode->next = top;
        top = newNode;
    }
    string pop() {
        if (!isEmpty()) {
            string topValue = top->lifo;
            Node* temp = top;
            top = top->next;
            delete temp;
            return topValue;
        } else {
            cout << "Stack is empty" << endl;
            return "";
        }
    }
    bool isEmpty() {
        return top == nullptr;
    }
    void print() {
        Node* current = top;
        while (current != nullptr) {
            cout << current->lifo << " ";
            current = current->next;
        }
        cout << endl;
    }
private:
    Node* top;
};
int main() {
    Stack stack;
    cout << "Stack Status: " << (stack.isEmpty() ? "Empty stack!" : "The stack is not empty") << endl;
    int numElements;
    cout << "Enter the number of elements to push onto the stack: ";
    cin >> numElements;
    cin.ignore();

    for (int i = 0; i < numElements; i++) {
        string element;
        cout << "Enter a String for Element " << i + 1 << ": ";
        getline(cin, element);
        stack.push(element);
    }
    cout << "Stack Status: " << (stack.isEmpty() ? "Empty stack" : "The stack is not empty") << endl;
    cout << "Stack elements: ";
    stack.print();
    string topElement = stack.pop();
    if (!topElement.empty()) {
        cout << "Popped element: " << topElement << endl;
        cout << "Do you want to remove the element (press 1) or return it (press 2)? ";
        int choice;
        cin >> choice;
        if (choice == 1) {
            cout << "Element removed from the stack." << endl;
        } else if (choice == 2) {
            stack.push(topElement);
            cout << "Element returned to the stack." << endl;
        } else {
            cout << "Invalid choice." << endl;
        }
    }
    cout << "Do you want to view the elements in the stack (press 3)? ";
    int viewChoice;
    cin >> viewChoice;
    if (viewChoice == 3) {
        cout << "Stack elements: ";
        stack.print();
    }
    return 0;
}
