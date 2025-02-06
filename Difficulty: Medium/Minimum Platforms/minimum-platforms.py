#User function Template for python3

class Solution:
    #Function to find the minimum number of platforms required at the
    #railway station such that no train waits.
    def minimumPlatform(self, arr, dep):
        n = len(arr)
        order = []
        #inserting all the values of time(arrival and departure)
        for i in range(n):
            #if the time is of arrival then we keep second value
            #of pair as 'a' else 'd'.
            order.append([arr[i], 'a'])
            order.append([dep[i], 'd'])

        #sorting order, first according to time and if time is
        #same for two events, then arrival comes first followed by departure.
        order.sort(key=lambda x: x[1])
        order.sort()
        result = 1
        plat_needed = 0

        for i in order:
            #if the second value of vector element is 'a' which stands
            #for arrival then we add 1 to platform needed else we
            #subtract 1 from platform needed.
            if (i[1] == 'a'):
                plat_needed += 1
            else:
                plat_needed -= 1
            #we keep updating the value of result.
            result = max(result, plat_needed)
        #returning the minimum number of platforms required.
        return result


#{ 
 # Driver Code Starts
#Initial Template for Python 3
import atexit
import io
import sys

#Contributed by : Nagendra Jha

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        arrival = list(map(int, input().strip().split()))
        departure = list(map(int, input().strip().split()))
        ob = Solution()
        print(ob.minimumPlatform(arrival, departure))
        print("~")

# } Driver Code Ends