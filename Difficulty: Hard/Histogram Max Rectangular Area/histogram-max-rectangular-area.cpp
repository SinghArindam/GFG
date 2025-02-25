//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        int n = arr.size();
        stack<int> s;  // Stack to store indices
        int maxArea = 0;
        int i = 0;
        
        while (i < n) {
            // If this bar is higher than the bar at stack top or stack is empty, push it.
            if (s.empty() || arr[i] >= arr[s.top()]) {
                s.push(i++);
            } else {
                // Calculate area with the stack's top element as the smallest bar
                int tp = s.top();
                s.pop();
                // If the stack is empty, width is i, otherwise width is i - s.top() - 1
                int width = s.empty() ? i : i - s.top() - 1;
                maxArea = max(maxArea, arr[tp] * width);
            }
        }
        
        // Now pop the remaining bars from stack and calculate area
        while (!s.empty()) {
            int tp = s.top();
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, arr[tp] * width);
        }
        
        return maxArea;
    }
};




//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends