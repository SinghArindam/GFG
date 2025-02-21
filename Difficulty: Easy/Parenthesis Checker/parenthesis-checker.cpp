//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    bool isBalanced(string &s) {
        stack<char> st;
        for (char ch : s) {
            // If it's an opening bracket, push onto the stack.
            if (ch == '(' || ch == '{' || ch == '[')
                st.push(ch);
            else { // It must be a closing bracket.
                // If stack is empty, there's no corresponding opening bracket.
                if (st.empty())
                    return false;
                char top = st.top();
                st.pop();
                // Check for the correct matching pair.
                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '['))
                    return false;
            }
        }
        // If the stack is empty, every opening bracket had a matching closing bracket.
        return st.empty();
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends