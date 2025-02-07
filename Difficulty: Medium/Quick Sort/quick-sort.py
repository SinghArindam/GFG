#User function Template for python3

class Solution:
    #Function to sort a list using quick sort algorithm.
    def quickSort(self, arr, low, high):

        if low < high:
            #pi is partitioning index, arr[pi] is now at right place.
            pi = self.partition(arr, low, high)

            #Separately sorting elements before and after partitioning index.
            self.quickSort(arr, low, pi - 1)
            self.quickSort(arr, pi + 1, high)

    #Function that takes last element as pivot, places the pivot element at
    #its correct position in sorted list, and places all smaller elements
    #to left of pivot and all greater elements to right of pivot.
    def partition(self, arr, low, high):

        #Index of smaller element and indicates the right position of
        #pivot found so far.
        i = (low - 1)
        #Picking the pivot.
        pivot = arr[high]

        for j in range(low, high):
            #If current element is smaller than or equal to pivot we increment
            #the value of i and swap the values at ith and jth index.
            if arr[j] <= pivot:
                i = i + 1
                #Swapping of values at ith and jth index.
                arr[i], arr[j] = arr[j], arr[i]

        #At last, swapping of value at ith and the last index which was
        #selected as pivot.
        arr[i + 1], arr[high] = arr[high], arr[i + 1]

        #returning the partitioning index.
        return (i + 1)
    


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for i in range(t):

        arr = list(map(int, input().split()))
        n = len(arr)
        Solution().quickSort(arr, 0, n - 1)
        for i in range(n):
            print(arr[i], end=" ")
        print()
        print("~")

# } Driver Code Ends