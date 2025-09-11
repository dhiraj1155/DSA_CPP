#include<iostream>
#include<vector>
using namespace std;

int longestSubarray(vector<int>&arr, int k){
    int n = arr.size();
    int left = 0;
    
    int sum = 0;
    int maxLen = 0;

    for(int right = 0; right < n; right++){

        sum += arr[right];

        // shrink window if sum > k
        while(left <= right && sum > k){
            sum -= arr[left];
            left++;
        }

        if(sum == k){
            maxLen = max(maxLen, right-left+1);
        }
    }
    return maxLen;
}

int main(){
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(7);

    int k = 14;

    int result = longestSubarray(arr,k);
    cout<<"length of longest subarray with sum equal to k is: "<<result;

    return 0;
}