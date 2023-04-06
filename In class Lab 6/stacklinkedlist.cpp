#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

struct Node {
    int data;
    Node* next;
};

struct Stack {
    Node* top;

    Stack() {
        top = nullptr;
    }

    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Error: stack underflow\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if (top == nullptr) {
            cout << "Error: stack underflow\n";
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return (top == nullptr);
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Elements in the stack: ";
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
   auto start = chrono::high_resolution_clock::now();

        Stack s;
        s.push(5);
        s.push(10);
        s.push(15);
        s.push(16);
        s.push(58);
        s.push(65);
        s.push(74);
        s.push(6);
        s.push(1);
        s.push(9);
        s.display();
        cout << "Current top of the stack: " << s.peek() << endl;
        s.pop();
        s.display();
        cout << "Current top of the stack: " << s.peek() << endl;
        s.pop();
        s.pop();
        s.pop();
        cout << "Is the stack empty? " << s.isEmpty() << endl;
        s.display();
        
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();

    cout << "Time taken : " << duration  << " microseconds" << endl;

    
    return 0;
}
