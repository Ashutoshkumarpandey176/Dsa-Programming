class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string &ch : tokens) {
            if (ch != "+" && ch != "-" && ch != "*" && ch != "/") {
                st.push(stoi(ch));
            }
            else {
                int b = st.top();
                st.pop();

                int a = st.top();
                st.pop();

                if (ch == "+")
                    st.push(a + b);
                else if (ch == "-")
                    st.push(a - b);
                else if (ch == "*")
                    st.push(a * b);
                else if (ch == "/")
                    st.push(a / b);
            }
        }

        return st.top();
    }
};