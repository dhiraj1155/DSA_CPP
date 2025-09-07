#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// Brute Force Approach
// vector<int> nextGreatestElement(vector<int> &arr){
//     vector<int> nge(arr.size(),-1);

//     for(int i = 0; i < arr.size(); i++){
//         for(int j = i+1; j < arr.size(); j++){
//             if(arr[j] > arr[i]){
//                 nge[i] = arr[j];
//                 break;
//             }

//         }
//     }
//     return nge;
// }

// Optimal using monotonic stack

vector<int> nextGreatestElement(vector<int> &arr){
    vector<int> nge(arr.size(),-1);
    stack<int> st;

    for(int i = arr.size()-1; i >= 0; i--){
       while(!st.empty() && st.top() <= arr[i]){
            st.pop();
       }
       //if stack is empty means no ele on right is greater so put -1 in nge.
       if(st.empty()){
            nge[i] = -1;
       }
       //if stack is not empty after popping means we have got a top element greater than curr ele.
       else{
        nge[i] = st.top();
       }

       //push the current element in stack
       st.push(arr[i]);
    }
    return nge;

}

int main(){
    vector<int> arr ;
    arr.push_back(4);
    arr.push_back(12);
    arr.push_back(5);
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(5);
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(6);

    vector<int> result = nextGreatestElement(arr);
    for(auto it : result){
        cout<<it<<" ";
    }
    return 0;

}