//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
class Solution {
  public:
    int maxSum(vector<int> &arr) {
        int n = arr.size();
        int cum_sum = 0;
        for (int i = 0; i < n; i++) {
            cum_sum += arr[i];
        }

        // calculating initial value and setting max as initial value
        int initial_val = 0;
        int max = 0;
        for (int i = 0; i < n; i++) {
            initial_val += i * arr[i];
            max = initial_val;
        }

        for (int i = 1; i < n; i++) {
            int temp = initial_val - (cum_sum - arr[i - 1]) + arr[i - 1] * (n - 1);
            initial_val = temp;
            if (temp > max)
                max = temp;
        }

        return max;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int ans = ob.maxSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends