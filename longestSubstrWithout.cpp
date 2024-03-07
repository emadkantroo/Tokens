#include<iostream>
#include<vector>
#include<unordered_map>
//Length of the longest substring without repeating characters
//There will be n*(n+1)/2 substrings

int lengthOfLongestSubStr(string s)
{
    unordered_map<char,int> charMap; //Maps characters to their latest indices
    int maxLength=0 ; // maximum length of substring found so far
    int start=0;

    for(int end = 0; end < s.length(); ++end){
        char currentChar = s[end];

        // If the character is in the map and its index is within the current window
        if(charMap.find(currentChar) != charMap.end() && charMap[currentChar]>=start){
            //Move the start to the next character of the duplicate's last occurence
            start = charMap[currentChar]+1;
        }
        //update the characters latest index
        charMap[currentChar]= end;

        //update the maximum length found so far
        maxLength = max(maxLength,end - start +1);
    }
    return maxLength;
}
