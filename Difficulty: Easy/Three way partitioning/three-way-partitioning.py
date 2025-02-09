#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends
#User function template for Python

class Solution:
    #Function to partition the arr around the range such
    #that arr is divided into three parts.
    def threeWayPartition(self, arr, a, b):
        n = len(arr)

        #Using two pointers which help in finding the index with which
        #the elements need to be swapped if they are not in correct position.
        s = i = 0
        e = n - 1

        while (i <= e):

            #If current element is smaller than lower range, we swap
            #it with value on next available smallest position.
            if arr[i] < a:
                arr[i], arr[s] = arr[s], arr[i]
                i += 1
                s += 1

            #If current element is greater than higher range, we swap
            #it with value on next available greatest position.
            elif arr[i] > b:
                arr[i], arr[e] = arr[e], arr[i]
                e -= 1

            #Else we just move ahead in the arr.
            else:
                i += 1

#{ 
 # Driver Code Starts.
#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    while t > 0:
        arr = list(map(int, input().split()))
        a = int(input())
        b = int(input())
        ob = Solution()
        ob.threeWayPartition(arr,a,b)
        ia = 0
        ib = 0
    
        for i in range(len(arr)):
            if arr[i] >= a:
                ia = i
                break
    
        for i in range(len(arr)):
            if arr[i] > b:
                ib = i
                break
    
        f = 0
    
        for i in range(ia):
            if arr[i] >= a:
                f = 1
                break
    
        for i in range(ia, ib):
            if arr[i] > b or arr[i] < a:
                f = 1
                break
    
        for i in range(ib, len(arr)):
            if arr[i] < b:
                f = 1
                break
    
        if f == 1:
            print("false")
        else:
            print("true")
        print("~")
        t -= 1


# } Driver Code Ends