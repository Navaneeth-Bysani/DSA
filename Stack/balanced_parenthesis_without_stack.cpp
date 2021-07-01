#include<bits/stdc++.h>
using namespace std;

bool find(string s) {
    stack<char> st;
    char c;
    for(int i = 0; i<s.length(); i++) {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        } else {
            switch (s[i])
            {
                case ')':
                    c = st.top();
                    st.pop();
                    if(c != '(')
                        return false;
                    break;

                case '}':
                    c = st.top();
                    st.pop();
                    if(c != '{')
                        return false;
                    break;
                case ']':
                    c = st.top();
                    st.pop();
                    if(c != '[')
                        return false;
                        break;
                default:
                    continue;
            }
        }
    }

    if(st.empty() == 0) {
        return false;
    }

    return true;
}

bool find2(string s, int n) {
    if(n == 0)
        return true;
    if(n == 1)
        return false;
    if(s[0] == ')' || s[0] == '}' || s[0] == ']')
        return false;
    
    char closing;
    switch (s[0])
    {
        case '(':
            closing = ')';
            break;
        
        case '{':
            closing = '}';
            break;
        
        case '[':
            closing = ']';
            break;
        default:
            break;
    }

    int count = 0, i = 0;
    for(i = 1; i<n; i++) {
        if(s[i] == s[0]) {
            count++;
        } else if(s[i] == closing) {
            if(count == 0)
                break;
            count--;
        }
    }

    if(i == n)
        return false;
    if(i == 1)
        return find2(s.substr(2), n-2);
    
    return find2(s.substr(1,i-1), i-1) && find2(s.substr(i+1), n-i-1);
}
int main() {
    string s = "{[([([)])]}";
    bool balanced = find(s);
    cout << balanced << endl;

    bool balanced2 = find2(s, s.length());
    cout << balanced2 << endl;
}