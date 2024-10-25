#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
//By Al-Hussain Abdo mohamed
// Id: 20220878
using namespace std;
int Sequential_Search(vector<int>&List,int Target){
    int flag=0;
for(int index=0;index<List.size();index++){
    if(List[index]==Target){
        flag=1;
        cout<<"The target is in the index :";
        return index;

    }
}
if(!flag){
    cout<<"\nThe target is not found.";
    return -1;
}
}
int Sequential_Search_recursiv(vector<int>&List,int Target,int index=0){
    int flag=0;
    if(index >= List.size()) {
        cout<<"\nThe target is not found.";
        return -1;
    }
    if (List[index] == Target) {
        flag=1;
        cout<<"The target is in the index :";
        return index;
    }
    return Sequential_Search_recursiv(List,Target,index+1);
}

int Binary_Search(vector<int>&List,int Target){
    int low=0, high=List.size()-1;
    sort(List.begin(),List.end());
    while(low<=high){
        int mid=low + (high-low) / 2;
        if(List[mid]==Target){
            cout<<"The target after sorting the list  in the index :";
            return mid;
        }
        else if(List[mid]<Target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    cout<<"\nThe target is not found.";
    return -1;

}
int main() {
    vector<int> list = {4,11,3,8,0,5,6,43,21,7};
    int target = 8;
    cout<<"=====USING Sequential_Search ======";
    cout<<"\n"<<Sequential_Search(list,target);
    cout<<"\n\n=====USING Sequential_Search_recursiv ======";
    cout<<"\n"<<Sequential_Search_recursiv(list,target);
    cout<<"\n\n=====USING Binary Search ======";
    cout<<"\n"<<Binary_Search(list,target);
    return 0;
}
