// *Skyline Real Estate Developers* is planning to demolish a number of old, unoccupied buildings and construct a shopping mall in their place. Your task is to find the largest solid area in which the mall can be constructed.

// There are a number of buildings in a certain two-dimensional landscape. Each building has a height, given by . If you join  adjacent buildings, they will form a solid rectangle of area .

// For example, the heights array . A rectangle of height  and length  can be constructed within the boundaries. The area formed is .

// **Function Description**

// Complete the function `largestRectangle` int the editor below. It should return an integer representing the largest rectangle that can be formed within the bounds of consecutive buildings.

// largestRectangle has the following parameter(s):

// - *h*: an array of integers representing building heights

// **Input Format**

// The first line contains , the number of buildings.The second line contains  space-separated integers, each representing the height of a building.

// **Constraints**

// - 1<n≤10^5
// - 1≤h[i]≤10^6

// **Output Format**

// Print a long integer representing the maximum area of rectangle formed.

// **Sample Input**

// `5
// 1 2 3 4 5`

// **Sample Output**

// `9`

// **Explanation**

// An illustration of the test case follows.

// ![](https://s3.amazonaws.com/hr-challenge-images/8136/1436794554-75e178e325-drawing47.svg)

// ## SOLUTION -

// [Maximum Rectangular Area in a Histogram | Practice | GeeksforGeeks](https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram/0)

#include<iostream> 
#include<stack> 
using namespace std; 
int getMaxArea(int hist[], int n) 
{  
	stack<int> s; 
	int max_area = 0; 
	int tp; 
	int area_with_top; 
	int i = 0; 
	while (i < n) 
	{ 
		if (s.empty() || hist[s.top()] <= hist[i]) 
			s.push(i++); 
		else
		{ 
			tp = s.top(); 
			s.pop(); 
			area_with_top = hist[tp] * (s.empty() ? i :	i - s.top() - 1); 
			if (max_area < area_with_top) 
				max_area = area_with_top; 
		} 
	}
	while (s.empty() == false) 
	{ 
		tp = s.top(); 
		s.pop(); 
		area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1); 
		if (max_area < area_with_top) 
			max_area = area_with_top; 
	} 
	return max_area; 
} 
int main() 
{ 
	int hist[] = {6, 2, 5, 4, 5, 1, 6}; 
	int n = sizeof(hist)/sizeof(hist[0]); 
	cout << "Maximum area is " << getMaxArea(hist, n); 
	return 0; 
}