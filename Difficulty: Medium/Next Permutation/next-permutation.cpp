//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // Function to find the next permutation
    // vector<int> nextPermutation(vector<int> arr) {
    void nextPermutation(vector<int>& arr) {
        int N = arr.size();
        int ind = 0;

        // Finding the first decreasing element from right to left
        for (int i = N - 2; i >= 0; i--) {
            if (arr[i] < arr[i + 1]) {
                ind = i;
                break;
            }
        }

        // Finding the smallest element greater than the element at ind
        for (int i = N - 1; i > ind; i--) {
            if (arr[i] > arr[ind]) {
                swap(arr[i], arr[ind]);
                ind++;
                break;
            }
        }

        // Reversing the elements from ind to end
        for (int i = 0; i < (N - ind) / 2; i++)
            swap(arr[i + ind], arr[N - i - 1]);
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int n = arr.size();
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends