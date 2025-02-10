//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int thirdLargest(vector<int> &arr) {
        int n = arr.size();
        // Base Case: if the array has less than 3 elements, return -1.
        if (n <= 2)
            return -1;

        // Initialize three variables to keep track of the three largest elements.
        int big1 = max(arr[0], arr[1]);
        int big2 = min(arr[0], arr[1]);
        int big3 = INT_MIN;

        // Traverse the array to find the third largest element.
        for (int i = 2; i < n; i++) {
            /* three way filtering */
            // If the current element is greater than the third largest element, update
            // the third largest element.
            if (arr[i] > big3) {
                big3 = arr[i];
            }
            // If the current element is greater than the second largest element, update
            // the third and second largest elements.
            if (arr[i] > big2) {
                big3 = big2;
                big2 = arr[i];
            }
            // If the current element is greater than the first largest element, update
            // all three largest elements.
            if (arr[i] > big1) {
                big2 = big1;
                big1 = arr[i];
            }
        }

        // Return the third largest element.
        return big3;
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
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.thirdLargest(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends