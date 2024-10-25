#include<bits/stdc++.h>

using namespace std;


int BinarySearch(const vector<int>& v , int target , int l , int r ){
    if ( r < l  )
        return -1;
    int mid =  l + (r - l) /2;
    if ( v[mid ] == target)
        return mid;
    else if ( v[mid] > target)
        return BinarySearch(v, target, l , mid -1 );
   
    else
        return BinarySearch(v, target, mid + 1 , r);
}

int main ( ){
    vector<int> v = { 1, 2, 3 ,4,5,6,7,8};
    cout << BinarySearch(v,11 , 0 , 7);

}