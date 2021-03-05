// ## **3 - POSSIBLE HOTEL BOOKING**

// A hotel manager has to process `N` advance bookings of rooms for the next season. His hotel has `K`rooms. Bookings contain an arrival date and a departure date. He wants to find out whether there are enough rooms in the hotel to satisfy the demand. Write a program that solves this problem in time O(N log N) .

// `First list for arrival time of booking.
// Second list for departure time of booking.
// Third is K which denotes count of rooms.`

// Input:

// Output:

// `A boolean which tells whether its possible to make a booking.
// Return 0/1 for C programs.87
// O -> No there are not enough rooms for N booking.
// 1 -> Yes there are enough rooms for N booking.`

// **Example :**

// `Input : Arrivals : [1 3 5] Departures : [2 6 8] K : 1
// Return : False / 0
// At day = 5, there are 2 guests in the hotel. But I have only one room.`

// ## SOLUTION -

// ### **using unordered map -**

//                           I counted the number of maximum occurrences of a date, if it exceeds K(no. of rooms) then return 0 else return 1. Space inefficient approach.

//                                                       TC- O(n^2)

//                                                         SC- O(a hash of size=maximum value in the array)


bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) 
{
    unordered_map <int,int> mp;
    int n=arrive.size();
    for(int i=0;i<n;i++)
    {
        int s=arrive[i];
        int e=depart[i];
        for(int j=s;j<e;j++)
        {
            if(mp.find(j)==mp.end())
                mp[j]=1;
            else
            {
                mp[j]=mp[j]+1;
                if(mp[j]>K)
                    return 0;
            }
        }
    }
    return 1;
}


// ## By finding the maximum number of overlapping intervals -


bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) 
{
    int n = arrive.size();
    int j=0;
    int i=1;
    if(n==0&&n>0)
        return 0;
    while(i<n)
    {
        if(depart[j]<=arrive[i])
        {
            continue;
            i+=1;
            j+=1;
        }
        while((arrive[i]>arrive[j])&&(arrive[i]<depart[j]))
        {
            count+=1;
            i+=1;
            if(count>K)
                return 0;
        }
    }
    return 1;
}


// [Semaphore (programming)](https://en.wikipedia.org/wiki/Semaphore_(programming))


bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) 
{
    int n = arrive.size();
    sort(arrive.begin(),arrive.end());
    sort(depart.begin(),depart.end());
    int i=0;
    while(K+i<n)
    {
        if(arrive[K+i]<depart[i])
            return 0;
        i++;
    }
    return 1;
}
