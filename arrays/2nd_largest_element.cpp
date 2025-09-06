#include<iostream>
#include "vector"
#include "set"
using namespace std;

int secondLargest(vector<int> &arr, int n){
    set <int> s(arr.begin(),arr.end());

    if(s.size()<2){
        return -1;
    }

    auto it = s.rbegin();
    ++it;

    return *it;

}

int main(){
    vector<int> arr;
    int n;
    cout<<"enter how many number of elements you want to insert in an array: ";
    cin>>n;
    for(int i = 0; i<n; i++){
        int num;
        cin>>num;
        arr.push_back(num);
    }
    cout<<secondLargest(arr,n);
}