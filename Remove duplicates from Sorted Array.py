# Remove duplicates from Sorted ArrayGiven a sorted array, remove the duplicates in place such that each element appears only once and return the new length.

# **Note that even though we want you to return the new length, make sure to change the original array as well in place**

# Do not allocate extra space for another array, you must do this in place with constant memory.

# > Example: Given input array A = [1,1,2],Your function should return length = 2, and A is now [1,2].
# > 


def remove_duplicate(n, arr):
    if (n==0) or (n==1): 
        return n 
    b=[]
    j=0; 
    for i in range(n-1): 
        if arr[i]!=arr[i+1]: 
            b.append(arr[i])
    b.append(arr[n-1])
    for i in range(0,len(b)): 
        arr[i]=b[i] 
  
    return len(b)
