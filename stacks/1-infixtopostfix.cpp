#include<iostream>
#include<stack>
#include<string>
using namespace std;

int priority(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

string infixToPostfix(string s){
    string ans = "";
    stack<char> st;
    
    for(int i = 0; i < s.size(); i++){
        // Operand
        if((s[i] >= 'A' && s[i] <= 'Z')||
           (s[i] >= 'a' && s[i] <= 'z')||
           (s[i] >= '0' && s[i] <= '9')){

            ans = ans + s[i]; 
        }
         // Opening bracket
        else if(s[i] == '('){
            st.push(s[i]);
        }
        // Closing bracket
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            if(!st.empty()) st.pop(); // pop '('
        }
        // Operator
        else{
            while(!st.empty() && priority(s[i]) <= priority(st.top())){
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    // Once iteration done, pop remaining operators
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    return ans;
}

int main(){
    string infix = "a+b*(c^d-e)";
    string result = infixToPostfix(infix);
    cout<<result;
    return 0;
}