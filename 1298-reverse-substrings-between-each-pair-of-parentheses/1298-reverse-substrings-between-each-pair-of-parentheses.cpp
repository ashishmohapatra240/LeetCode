class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        string res = "";

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(res.size());
            }
           else if(s[i] == ')'){
            int start=st.top();
                st.pop();
                reverse(res.begin() + start, res.end());
            }
            else {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};