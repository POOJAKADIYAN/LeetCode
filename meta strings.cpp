// Check if two strings can become same after a swap in one string.

// Given two strings, the task is to check whether these strings are meta strings or not. Meta strings are the strings which can be made equal by exactly one swap in any of the strings. Equal string are not considered here as Meta strings.

// Examples:

// ```
// Input : str1 = "geeks" 
//         str2 = "keegs"
// Output : Yes
// By just swapping 'k' and 'g' in any of string, 
// both will become same.

// Input : str1 = "rsting"
//         str2 = "string
// Output : No

// Input :  str1 = "Converse"
//          str2 = "Conserve"
// ```

// ## SOLUTION -

#include<iostream> 
using namespace std;
bool areMetaStrings(string str1, string str2) 
{ 
	int len1 = str1.length(); 
	int len2 = str2.length(); 
	if (len1 != len2) 
		return false; 
	int prev = -1, curr = -1; 
	int count = 0; 
	for (int i=0; i<len1; i++) 
	{ 
		if (str1[i] != str2[i]) 
		{ 
			count++; 
			if (count > 2) 
				return false; 
			prev = curr;     //thisssssss
			curr = i; 
		} 
	}  
	return (count == 2 && 
			str1[prev] == str2[curr] && 
			str1[curr] == str2[prev]); 
} 
int main() 
{ 
	string str1 = "converse"; 
	string str2 = "conserve"; 
	areMetaStrings(str1,str2) ? cout << "Yes": cout << "No"; 
	return 0; 
}
