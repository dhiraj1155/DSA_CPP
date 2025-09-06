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


string infixToPrefix(string s){

    // Step 1: Reverse infix expression
    reverse(s.begin(), s.end());

    // Step 2: Swap ( and )
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') s[i] = ')';
        else if (s[i] == ')') s[i] = '(';
    }

    string ans = "";
    stack<char> st;
    
    // Step 3: Convert reversed infix to postfix
    for(int i = 0; i < s.size(); i++){
        // Operand
        if(isalnum(s[i])){
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
            if(s[i] == '^'){ // right-associative
                while(!st.empty() && priority(s[i]) < priority(st.top())){
                    ans  += st.top();
                    st.pop();
                }
            }
            else{
                while(!st.empty() && priority(s[i]) <= priority(st.top())){
                    ans += st.top();
                    st.pop();
                }
            }
            st.push(s[i]);
        }
    }


    // Step 4: Pop remaining operators
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }

    // Step 5: Reverse postfix result → prefix
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    string infix = "(A+B)*C-D+F";
    string result = infixToPrefix(infix);
    cout<<result;
    return 0;
}