//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        int n = arr.size();

        // Segregating positive and non-positive numbers.
        int shift = segregateArr(arr);

        // Find the smallest missing positive number in the positive subarray.
        return findMissingPositive(arr, shift);
    }

  private:
    // Function to segregate the array by moving non-positive (<= 0) numbers to the left
    // and return the index from where the positive numbers start.
    int segregateArr(vector<int> &arr) {
        int j = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            if (arr[i] <= 0) {
                swap(arr[i], arr[j]);
                j++;
            }
        }
        return j; // j is the count of non-positive numbers
    }

    // Function to find the smallest positive missing number in an array that contains
    // only positive numbers.
    int findMissingPositive(vector<int> &arr, int shift) {
        int n = arr.size() - shift;

        // Marking elements as visited by making the value at index abs(arr[i]) - 1
        // negative.
        for (int i = shift; i < arr.size(); i++) {
            if (abs(arr[i]) - 1 + shift < arr.size() &&
                arr[abs(arr[i]) - 1 + shift] > 0) {
                arr[abs(arr[i]) - 1 + shift] = -arr[abs(arr[i]) - 1 + shift];
            }
        }

        // Finding the first missing positive number.
        for (int i = shift; i < arr.size(); i++) {
            if (arr[i] > 0) {
                return i - shift + 1;
            }
        }
        return n + 1;
    }
};

//{ Driver Code Starts.

// int missingNumber(int arr[], int n);

int main() {

    // taking testcases
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
        int result = ob.missingNumber(arr);
        cout << result << "\n";
    }
    return 0;
}
// } Driver Code Ends