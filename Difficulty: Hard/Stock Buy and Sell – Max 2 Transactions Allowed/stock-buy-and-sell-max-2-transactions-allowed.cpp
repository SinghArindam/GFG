//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    //Back-end complete function Template for C++

    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        vector<int> profit(n, 0);

        // Get the maximum profit with only one transaction allowed
        int max_price = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > max_price)
                max_price = arr[i];

            // we can get profit[i] by taking maximum of:
            // a) previous maximum, i.e., profit[i+1]
            // b) profit by buying at arr[i] and selling at
            //    max_price
            profit[i] = max(profit[i + 1], max_price - arr[i]);
        }

        // Get the maximum profit with two transactions allowed
        int min_price = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] < min_price)
                min_price = arr[i];

            // Maximum profit is maximum of:
            // a) previous maximum, i.e., profit[i-1]
            // b) (Buy, Sell) at (min_price, arr[i]) and add
            //    profit of other trans. stored in profit[i]
            profit[i] = max(profit[i - 1], profit[i] + (arr[i] - min_price));
        }
        int result = profit[n - 1];
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends