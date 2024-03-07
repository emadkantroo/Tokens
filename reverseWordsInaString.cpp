class Solution {
public:
    string reverseWords(string s) {
        int N = s.size();
        int n = 0, ind = 0;

        //First clean up extra spaces
        while(ind < N){
            while(ind < N && s[ind] == ' ') ind++;

            if(ind >= N) break;

            while(ind<N && s[ind] != ' '){
                s[n] = s[ind];
                n++; ind++;
            }

            if(n<N){
                s[n] = ' '; n++;
            }
        }

        s = s.substr(0, n);

        if(s[n-1] == ' '){
            s = s.substr(0, n-1);
            n--;
        }

        //Now reverse words
        int i=0, j=0;
        while(j<n){
            while(j<n && s[j] != ' ') j++;
            if(j != n-1) j--;

            for(int k=i; k<=(i+j)/2; k++) swap(s[k], s[i+j-k]);

            j += 2;
            i = j;
        }

        //Reverse whole string
        for(int i=0; i<n/2; i++) swap(s[i], s[n-i-1]);

        return s;
    }
};
/*
Time complexity: O(n)O(n)O(n) or little more
Space complexity: O(1)O(1)O(1)
*/

class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.split()
        reversed_words = words[::-1]
        result = ' '.join(reversed_words)
        return result