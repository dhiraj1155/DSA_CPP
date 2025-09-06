#include<iostream>
#include<stack>
#include<string>
using namespace std;

string prefixToInfix(string s){
    stack<string> st;
    for(int i = s.size()-1; i>=0; i--){
        if(isalnum(s[i])){
            st.push(string(1, s[i]));
        }
        else{
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();
            string con = '(' + t1 + s[i] + t2 + ')';
            st.push(con);
        }
    }
    return st.top();
}

int main(){
    string prefix = "*+PQ-MN";
    string result = prefixToInfix(prefix);
    cout<<result;
    return 0;
}