//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int countPS(string &s) {
        int n = s.size();
        int count = 0;
        
        // Count odd length palindromes (single character center)
        for (int center = 0; center < n; center++) {
            int left = center, right = center;
            while (left >= 0 && right < n && s[left] == s[right]) {
                // Only count if the palindrome length is at least 2
                if (right - left + 1 >= 2) {
                    count++;
                }
                left--;
                right++;
            }
        }
        
        // Count even length palindromes (center between two characters)
        for (int center = 0; center < n - 1; center++) {
            int left = center, right = center + 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                // For even-length, the length is always at least 2 initially
                count++;
                left--;
                right++;
            }
        }
        
        return count;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends