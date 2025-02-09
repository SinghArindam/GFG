//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        int n = a.size();
        int m = b.size();
        // Create a unordered map to store the frequency of elements in a
        unordered_map<int, int> mp;

        // Count the frequency of elements in a
        for (int i = 0; i < n; i++) {
            mp[a[i]]++;
        }

        int count = 0;

        // Iterate through the elements in b
        for (int i = 0; i < m; i++) {
            // If the element is present in a, increment the count
            if (mp[b[i]] > 0) {
                mp[b[i]]--;
            } else {
                return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a1, a2;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a1.push_back(number);
        }
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            a2.push_back(number);
        }
        Solution s;
        bool ans = s.isSubset(a1, a2);
        if (ans) {
            cout << "true"
                 << "\n";
        } else {
            cout << "false"
                 << "\n";
        }
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends