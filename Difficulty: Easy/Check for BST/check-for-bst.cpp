//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


// } Driver Code Ends

#include <climits>

// Assume Node structure is defined as follows:
// struct Node {
//     int data;
//     Node *left, *right;
// };

class Solution {
public:
    // Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) {
        // Start with the widest possible range.
        return isBSTUtil(root, LONG_MIN, LONG_MAX);
    }
    
private:
    // Helper function that checks if the tree rooted at 'node' is a BST
    // with all values strictly between minVal and maxVal.
    bool isBSTUtil(Node* node, long minVal, long maxVal) {
        // An empty node is valid.
        if (node == nullptr)
            return true;
            
        // The current node must be strictly between minVal and maxVal.
        if (node->data <= minVal || node->data >= maxVal)
            return false;
            
        // Recursively check left and right subtrees with updated bounds.
        return isBSTUtil(node->left, minVal, node->data) &&
               isBSTUtil(node->right, node->data, maxVal);
    }
};




//{ Driver Code Starts.

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void inorder(Node* root, vector<int>& v) {
    if (root == NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        // if (s[0] == '9') {
        //     cout << "false\n";
        //     return 0;
        // }
        Node* root = buildTree(s);
        Solution ob;
        if (ob.isBST(root))
            cout << "true\n";

        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends