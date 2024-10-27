#include <bits/stdc++.h>

using namespace std;

template<class T>
class Heap {
private:
    vector<T> arr;  
    bool maxheap ;
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

    void heapify_up_max(int pos) {
        int parentpos = parent(pos);
        if (pos == 0 || arr[pos] < arr[parentpos]) {
            return;
        }
        swap(arr[pos], arr[parentpos]);
        heapify_up_max(parentpos);
    }

    void heapify_down_max(int parentpos) {
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
            heapify_down_max(largerChild);  
        }
    }

    void heapify_down_min(int parentpos) {
        int Left = left(parentpos);
        int Right = right(parentpos);

        if (Left == -1)  
            return;

        int smaller = Left;
        if (Right != -1 && arr[Left] > arr[Right]) {
            smaller = Right;
        }
        if (arr[smaller] < arr[parentpos]) {
            swap(arr[smaller], arr[parentpos]);
            heapify_down_max(smaller);  
        }
    }
    void heapify_up_min(int pos) {
        int parentpos = parent(pos);
        if (pos == 0 || arr[pos] > arr[parentpos]) {
            return;
        }
        swap(arr[pos], arr[parentpos]);
        heapify_up_max(parentpos);
    }
    void build_min_heap(){
        for (int i = ( size - 1) / 2; i >= 0 ; i -- ){
            heapify_down_min(i);
        }
    }
    void build_max_heap(){
        for (int i = ( size - 1) / 2; i >= 0 ; i -- ){
            heapify_down_max(i);
        }
    }

public:
    Heap() {
        size = 0;
        maxheap = true;
    };

    void push(T elem) {
        if (size == arr.size()) {
            arr.push_back(elem);  
        } else {
            arr[size] = elem;
        }
        size++;
        heapify_up_max(size - 1);
    }
    void pop() {
        if (size == 0) {
            throw out_of_range("Heap is empty");
        }
        arr[0] = arr[--size];  
        heapify_down_max(0);        
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
    T top(){
        assert(size);
        return arr[0];
    }
    T Extract_min(){
        assert(size>=1);
        if (maxheap){
            build_min_heap();
            maxheap = false;
        }
        int mn = arr[0];
        arr[0] = arr[--size];
        heapify_down_min(0);
        return mn;
    }
    T Extract_max(){
        assert(size>=1);
        if (!maxheap){
            build_max_heap();
            maxheap = true;
        }
        int mx = arr[0];
        arr[0] = arr[--size];
        heapify_down_max(0);
        return mx;
    }
    void sort(vector<int>&v){
        arr = v;
        size = v.size();
        build_max_heap();
        v.clear();
        while( size){
            v.push_back(Extract_max()); // extracting the max element each time
        }
        reverse(v.begin() , v.end());
    }
};



int main() {
    Heap<int> heap;
    vector<int> vec = { 13,2322, 1114,20,15,30};   
    cout << "the vector before using the heapsort:\n";
    for (auto it : vec)
        cout << it << ' ';
    heap.sort(vec);
    cout << endl;
    cout << "he vector after using the heap sort:\n";
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
    /*
    for taking the input from the user 
    Heap<int> heap;
    int n;
    cout << "Enter the size for the heap: "
    cin >> n;
    while ( n ){
        int a ;
        cin >> a;
        heap.push(a);
    }
    */
    cout << "Max Element = " << heap.Extract_max ()<< "\n";
    cout << "Min Element = "<< heap.Extract_min ()<< endl; 
    cout << endl;
    return 0;
}
