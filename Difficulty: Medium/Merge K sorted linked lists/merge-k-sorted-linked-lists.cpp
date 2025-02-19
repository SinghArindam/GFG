//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print nodes in a given linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}


// } Driver Code Ends
/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/


class Solution {
public:
    Node* mergeKLists(vector<Node*>& arr) {
        // Custom comparator for the min-heap to order nodes based on their data.
        auto cmp = [](Node* a, Node* b) {
            return a->data > b->data;
        };
        
        // Priority queue (min-heap) to store the current heads of the lists.
        priority_queue<Node*, vector<Node*>, decltype(cmp)> pq(cmp);
        
        // Push the head of each list into the min-heap.
        for (auto head : arr) {
            if (head) {
                pq.push(head);
            }
        }
        
        // Dummy node to help build the result list.
        Node dummy(0);
        Node* tail = &dummy;
        
        // Extract the smallest node from the heap and add it to the result list.
        while (!pq.empty()) {
            Node* top = pq.top();
            pq.pop();
            tail->next = top;
            tail = tail->next;
            if (top->next != nullptr) {
                pq.push(top->next);
            }
        }
        
        return dummy.next;
    }
};



//{ Driver Code Starts.

// Driver program to test the above functions
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<Node*> v(n);

        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);

            Node* head = new Node(0);
            Node* temp = head;
            int x;
            while (ss >> x) {
                Node* newNode = new Node(x);
                temp->next = newNode;
                temp = temp->next;
            }
            v[i] = head->next;
        }

        Solution ob;
        Node* head = ob.mergeKLists(v);
        printList(head);
    }

    return 0;
}

// } Driver Code Ends