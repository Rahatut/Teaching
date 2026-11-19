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
    
    while(true){
        int n;
        cin>>n;
        if(n==0) break;
        Queue q;
   
        for(int i=0; i<n; i++){
            q.push(i+1);
        }

        int discarded[n];
        int idx = 0;

        while(q.size()>1){
            discarded[idx++]=q.front();
            q.pop();
            q.push(q.front());
            q.pop();
        }

        cout<<"Discarded cards:";

        for(int i=0; i<idx; i++){
            if (i==0) cout<<" "<<discarded[i];
            else cout<<", "<<discarded[i];
        }
        cout<<"\n";
        cout<<"Remaining card: "<<q.back()<<"\n";

    }
    
    return 0;
}