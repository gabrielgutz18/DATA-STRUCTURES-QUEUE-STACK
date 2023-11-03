#include <iostream>
#include <string>
using namespace std;
struct Node {
    string data;
    Node* next;
    Node(const string& val) : data(val), next(nullptr) {}
};
class Queue {
public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(const string& item) {
        Node* newNode = new Node(item);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }
    string dequeue() {
        if (!isEmpty()) {
            string frontValue = front->data;
            Node* temp = front;
            front = front->next;
            delete temp;
            return frontValue;
        } else {
            cout << "Queue is empty" << endl;
            return ""; 
        }
    }
    bool isEmpty() {
        return front == nullptr;
    }

    void print() {
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
private:
    Node* front;
    Node* rear;
};
int main() {
    Queue queue;
    cout << "Queue Status: " << (queue.isEmpty() ? "Empty queue!" : "The queue is not empty") << endl;
    int numElements;
    cout << "Enter the number of elements to enqueue into the queue: ";
    cin >> numElements;
    cin.ignore();

    for (int i = 0; i < numElements; i++) {
        string element;
        cout << "Enter an Number for Element " << i + 1 << ": ";
        getline(cin, element);
        queue.enqueue(element);
    }
    cout << "Queue Status: " << (queue.isEmpty() ? "Empty queue" : "The queue is not empty") << endl;
    cout << "Queue elements number/s: ";
    queue.print();

    string frontElement = queue.dequeue();
    if (!frontElement.empty()) {
        cout << "Number '" << frontElement << "' removed from the queue." << endl;
        cout << "Do you want to return the element (press 1) or remove it (press 2)? ";
        int choice;
        cin >> choice;
        if (choice == 1) {
            queue.enqueue(frontElement);
            cout << "Number'" << frontElement << "' returned to the queue." << endl;
        } else if (choice == 2) {
            cout << "Number '" << frontElement << "' has been removed from the queue." << endl;
        } else {
            cout << "Invalid choice." << endl;

        }
    }
    cout << "Do you want to view the elements in the queue (press 3)? ";
    int viewChoice;
    cin >> viewChoice;
    if (viewChoice == 3) {
        cout << "Queue elements number/s: ";
        queue.print();
    }
    return 0;
}
