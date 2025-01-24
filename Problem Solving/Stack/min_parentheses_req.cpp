// minimum number of parentheses required to make the parentheses string valid
#include <bits/stdc++.h>
using namespace std;

int minAddToMakeValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty())
                st.push(s[i]);
            else if (st.top() == '(')
                st.pop();
            else
                st.push(s[i]);
        }
    }
    return st.size();
}

int main()
{
    string s = "())}";
    cout << minAddToMakeValid(s) << endl;
    return 0;
}