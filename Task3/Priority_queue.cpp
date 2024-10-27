#include <bits/stdc++.h>

using namespace std;

template<class T>

class Priority_queue {
private:
    vector<T>arr;
    int size ;
    int left (int parent){
        int pos = parent * 2 + 1;
        if (pos >= size)
            return -1;
        return pos;
    }
    int right ( int parent){
        int pos = parent * 2 + 2;
        if ( pos >= size)
            return -1;
        return pos;
    }
    int parent(int node){
        return ( node == 0 ? -1 : ( node - 1) / 2);
    }
    void heapfiy_up(int node ){
        int parentpos = parent(node);
        if ( parentpos == -1 || node == 0 ){
            return;
        }
        if ( arr[parentpos] < arr[node] ){
            swap(arr[parentpos] , arr[node]);
            heapfiy_up(parentpos);
        }
    }
    void heapfiy_down(int parent){
        int Left = left( parent);
        int Right = right ( parent);
        if ( Left == -1 )
            return ;
        int larger = Left;
        if ( Right != -1 && arr[Right ] > arr[Left]){
            Left = Right ;
        }
        if ( arr[Left] > arr[parent]){
            swap(arr[Left] , arr[parent]);
            heapfiy_down(Left);
        }
    }

public :

    Priority_queue() {
        size = 0;
    };

    void push(T elem){
        if (size == arr.size()) {
            arr.push_back(elem);  
        }
        else {
            arr[size] = elem;
        }
        size++;
        heapfiy_up(size - 1);
    }
    void pop(){
        assert(size);
        arr[0] = arr[--size];
        heapfiy_down(0);
   }
    int top(){
        assert(size);
        return arr[0];
   }
    bool isempty() {
        return size == 0;
    }
    void print() const {
        for (const T& elem : arr) {
            cout << elem << " ";
        }
        cout << endl;
    }

};


int main (){

    Priority_queue<int> pq;
    // insertion
    pq.push(123);
    pq.push(13);
    pq.push(555);
    pq.push(12323);
    // Getting the highest priority
    cout << pq.top() << endl;
    // Poping
    pq.pop();
    cout << pq.top();

}