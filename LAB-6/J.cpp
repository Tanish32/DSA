#include <iostream>
#include <string>
#include <stack>
using namespace std;
void compute()
{
    stack<char> st;
    string bSeq;
    int fOpen = 0, ans = 0;
    cin >> bSeq;
    for (int i = 0; i < bSeq.length(); i++)
    {
        if ((!st.empty()) && st.top() == '(' && bSeq[i] == ')')
        {
            st.pop();
            ans--;
        }
        else if ((!st.empty()) && st.top() == ')' && bSeq[i] == '(')
        {
            st.pop();
            ans++;
        }
        else if (st.empty() && bSeq[i] == ')')
        {
            ans++;
        }
        else
        {
            st.push(bSeq[i]);
            ans++;
        }
    }
    cout << ans << endl;
}
int main()
{
    compute();
    return 0;
}
