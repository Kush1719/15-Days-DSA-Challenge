bool isValidParenthesis(string s) {
    stack<char> st; 
    char x; 
    for (int i = 0; i < s.length(); i++)  { 
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')  { 
            st.push(s[i]); 
            continue; 
        }
        if (st.empty()) {
            return false; 
        }
        x = st.top(); 
        st.pop();
        switch (s[i]) { 
        case ')': 
            if (x == '{' || x == '[') {
                return false; 
            }
            break; 
        case '}': 
            if (x == '(' || x == '[') {
                return false; 
            }
            break; 
        case ']': 
            if (x == '(' || x == '{'){
                return false;
            }
            break; 
        } 
    }
    return (st.empty()); 
}