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
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin>>n>>m;

        Queue q;
        int prio[100]; //number of jobs at most 100, for each priority vals;
        int freq[10] = {0}; //freq of each priority val;

        for (int i = 0; i < n; i++) {
            cin >> prio[i];
            freq[prio[i]]++;
            q.push(i); //keeping track of indices of job
        }

        int timer = 0;

        while (!q.empty()) {
            int cur_idx = q.front();
            int cur_prio = prio[cur_idx];

            bool has_higher = false;
            for (int p = cur_prio + 1; p <= 9; p++) { //if more than cur prio exist - start w +1
                if (freq[p] > 0) {
                    has_higher = true;
                    break;
                }
                //continue to check till 9 until 1 higher val found
            }

            if (has_higher) {
                q.push(cur_idx);//for later processing
                q.pop();//move from top
            } 
            else {
                q.pop();
                freq[cur_prio]--;//reduce job with this prio
                timer++;

                if (cur_idx == m) break;//when m reached, break
            }
        }

        cout<<timer<<"\n";
    }
    
    return 0;
}