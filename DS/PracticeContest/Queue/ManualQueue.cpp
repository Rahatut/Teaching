#include <bits/stdc++.h>
using namespace std;

class Queue { //using class and methods for manually implementing
private:
    int* arr;
    int capacity;
    int front_idx;
    int back_idx;

public:
    Queue() {
        capacity = 2; 
        arr = new int[capacity];
        front_idx = 0;
        back_idx = 0;
    } //constructor - initialize vals

    ~Queue() {
        delete[] arr;
    } //delete

    bool empty() {
        return front_idx == back_idx;
    }

    int size() {
        return back_idx - front_idx;
    }

    void push(int val) {
        if (back_idx == capacity) { //capacity increase then push in array
            capacity *= 2;
            int* new_arr = new int[capacity];
            for (int i = 0; i < back_idx; i++) {
                new_arr[i] = arr[i]; //copy
            }
            delete[] arr;
            arr = new_arr;
        }
        arr[back_idx++] = val;//push and increment back idx
    }

    void pop() {
        if (!empty()) front_idx++; //simply move 
    }

    int front() {
        return empty() ? -1 : arr[front_idx]; //if empty, returns -1, if not, front idx element
    }

    int back() {
        return empty() ? -1 : arr[back_idx - 1]; //if empty, returns -1, if not, back idx element
    }
    
};

int main(){
    Queue q; 

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: "<< q.front()<< "\n";
    cout << "Back:  "<< q.back()<< "\n";
    cout << "Size:  "<< q.size()<< "\n";

    q.pop();
    cout <<"Front after pop: "<< q.front() << "\n";

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}