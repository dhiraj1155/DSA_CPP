#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> nextGreatestElementII(vector<int>&arr){
    int n = arr.size();
    vector<int> nge(arr.size(),-1);
    stack<int> st;

    for(int i = 2*arr.size()-1; i >= 0; i--){
        while(!st.empty() && st.top() <= arr[i % n]){
            st.pop();
        }
        if(i<n){
            nge[i%n] = st.empty() ? -1 : st.top();
        }

        st.push(arr[i%n]);
    }
    return nge;

}

int main(){
    vector<int> arr ;
    arr.push_back(2);
    arr.push_back(10);
    arr.push_back(12);
    arr.push_back(1);
    arr.push_back(11);

    vector<int> result = nextGreatestElementII(arr);
    for(auto it : result){
        cout<< it <<" ";
    }

    return 0;
}