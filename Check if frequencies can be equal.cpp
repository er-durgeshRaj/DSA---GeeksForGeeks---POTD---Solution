// QUESTION
// Given a string s which contains only lower alphabetic characters, check if it is possible to remove at most one character from this string in such a way that frequency of each distinct character becomes same in the string. Return true if it is possible to do else return false.

// Note: The driver code print 1 if the value returned is true, otherwise 0.

// Example 1:

// Input:
// s = "xyyz"
// Output: 
// 1 
// Explanation: 
// Removing one 'y' will make frequency of each character to be 1.
// Example 2:

// Input:
// s = "xxxxyyzz"
// Output: 
// 0
// Explanation: 
// Frequency can not be made same by removing at most one character.
// Your Task:  
// You dont need to read input or print anything. Complete the function sameFreq() which takes a string as input parameter and returns a boolean value denoting if same frequency is possible or not.

// Expected Time Complexity: O(|s|) 
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= |s| <= 105
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SOLUTION
class Solution{
public:	
	bool sameFreq(string s)
	{
	    // code here 
	    unordered_map<char,int> mm;
	    for(auto x:s)mm[x]++;
	    int mn=INT_MAX,mx=INT_MIN,mxCount=0,mnCount=0;
	    for(auto x:mm){
	        mn=min(mn,x.second);
	        mx=max(mx,x.second);
	    }
	    for(auto x:mm){
	        if(x.second==mx)mxCount++;
	        else if(x.second==mn)mnCount++;
	    }
	    if(mn==mx or (mn==mx-1 and mxCount==1))return true;
	    if(mnCount==1 and mn==1 and mxCount+mnCount==mm.size())return true;
	    return false;
	}
};
