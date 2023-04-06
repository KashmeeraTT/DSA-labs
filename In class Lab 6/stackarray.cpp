#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;


class Stack {
private:
    int *arr;
    int MAX_SIZE;
    int top;

public:
    Stack(int size) {
        arr = new int[size];
        MAX_SIZE = size;
        top = -1;
    }

    void push(int x) {
        if (top >= MAX_SIZE - 1) {
            cout << "Error: stack overflow\n";
            return;
        }
        top++;
        arr[top] = x;
    }

    void pop() {
        if (top < 0) {
            cout << "Error: stack underflow\n";
            return;
        }
        top--;
    }

    int peek() {
        if (top < 0) {
            cout << "Error: stack underflow\n";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return (top < 0);
    }

    bool isFull() {
        return (top == MAX_SIZE - 1);
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Elements in the stack: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {

    auto start = chrono::high_resolution_clock::now();

        Stack s(100);
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
        // cout << "Is the stack full? " << s.isFull() << endl;
        s.display();
        
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();

    cout << "Time taken : " << duration  << " microseconds" << endl;

    
    return 0;
}
