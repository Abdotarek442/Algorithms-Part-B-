#include <bits/stdc++.h>

using namespace std;

template<class T>
class Heap {
private:
    vector<T> arr;  
    int size;       

    int left(int node) {
        int pos = node * 2 + 1;
        return (pos < size) ? pos : -1;
    }

    int right(int node) {
        int pos = node * 2 + 2;
        return (pos < size) ? pos : -1;
    }

    int parent(int node) {
        return (node == 0) ? -1 : (node - 1) / 2;
    }

    void heapify_up(int pos) {
        int parentpos = parent(pos);
        if (pos == 0 || arr[pos] < arr[parentpos]) {
            return;
        }
        swap(arr[pos], arr[parentpos]);
        heapify_up(parentpos);
    }

    void heapify_down(int parentpos) {
        int Left = left(parentpos);
        int Right = right(parentpos);

        if (Left == -1)  
            return;

        int largerChild = Left;
        if (Right != -1 && arr[Left] < arr[Right]) {
            largerChild = Right;
        }
        if (arr[largerChild] > arr[parentpos]) {
            swap(arr[largerChild], arr[parentpos]);
            heapify_down(largerChild);  
        }
    }
    

public:
    Heap() {
        size = 0;
    };

    void push(T elem) {
        if (size == arr.size()) {
            arr.push_back(elem);  
        } else {
            arr[size] = elem;
        }
        size++;
        heapify_up(size - 1);
    }
    void pop() {
        if (size == 0) {
            throw out_of_range("Heap is empty");
        }
        arr[0] = arr[--size];  
        heapify_down(0);        
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
    int top(){
        assert(size);
        return arr[0];
    }
    int Get_min(){
        assert(size>=1);
        int mn = INT16_MAX;
        for (auto it : arr){
            mn = min ( mn , it);
        }
        return mn;
    }
    int Get_max(){
        assert(size>=1);
        return arr[0];
    }
    // void build_maxheap(vector<int>& Arr){
    //     for (int i = size / 2 - 1; i >= 0 ; i--){
    //         heapify_down(i);
    //     }
    // }

    // void Heapsort( vector<int> &givenarr ){
    //     arr = givenarr;
    //     build_maxheap(arr);
    //     int i = 0;
    //     givenarr.clear();
    //     while ( !arr.empty){
    //         cout << arr[0] << ' ';
    //         build_maxheap
    //     }
    // }
};

void Heapsort(vector<int>&v){
    Heap<int> heap;
    for (int i = 0 ; i < v.size() ; i++ ){
        heap.push(v[i]);
    }
    v.clear();
    while( !heap.isempty ( )){
        v.push_back(heap.top());
        heap.pop();
    }
    reverse(v.begin() , v.end());

}

int main() {
    Heap<int> heap;
    vector<int> vec = { 123,232, 1214,643,657,888};
    Heapsort(vec);
    // heap sort 
    for (auto it : vec){
        cout << it << ' ';
    }
    cout << endl;
    heap.push(1);
    heap.push(5);
    heap.push(12);
    heap.push(3);
    heap.push(100);
    heap.push(4);

    cout << "Max Element = " << heap.Get_max ()<< "\n" << "Min Element = "<< heap.Get_min()<< endl; 
    cout << endl;

    return 0;
}
