#include <string>
#include <iostream>
#include <stdlib.h>
#include <map>
#include <math.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
	    if(s.length() == 0){
		  return 0;
	    }
	    int start =0, end=0, maxlen=0;
	    int table [256] = {0};
	    while(end < (int)s.length()){
		    if(table[s[end]]!= 0){ /* if duplicate letter appears*/
			maxlen = max(maxlen, end - start );
			while(s[start]!=s[end]){ 
				table[s[start]] = 0;
				start ++;
			}
			start ++;
			end++;
		    }else{
			table[s[end]] = 1;
			end++;
		    }
	    }
	    maxlen = max(maxlen, (int)s.length() - start);
	    return maxlen;
    }
};

int main(){
	string s = "myname";
	Solution sol;
	cout<<sol.lengthOfLongestSubstring(s);

	system("pause");
}