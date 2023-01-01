class Solution {
public:
int evalRPN(vector<string> &tokens)
{
    int n = tokens.size();
    stack<long long> st;
    long long res = 0;
    for (auto it : tokens)
    {
        if (it == "*" || it == "-" || it == "+" || it == "/")
        {
            long long second = st.top();
            st.pop();
            long long first = st.top();
            res = 0;
            st.pop();
            if (it == "*")
            {
                res += first * second;
            }
            else if (it == "-")
            {
                res += first - second;
            }
            else if (it == "+")
            {
                res += first + second;
            }
            else
            {
                res += first / second;
            }
            st.push(res);
        }
        else
        st.push(stoi(it));
    }
    return st.top();
}

};
