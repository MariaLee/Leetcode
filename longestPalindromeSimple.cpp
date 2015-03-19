#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
	    int n = s.length();
	    if(n == 0){
		return "";
	    }
	    string maxSubstring = s.substr(0,1);//initialized to a single-character string
	    for(int i = 0; i< n-1; i++){
		string p1 = expandAroundCenter(s,i,i);
		if(p1.length() > maxSubstring.length()){
			maxSubstring = p1;
		}

		string p2 = expandAroundCenter(s,i,i+1);
		if(p2.length() > maxSubstring.length()){
			maxSubstring = p2;
		}
	    }

	    return maxSubstring;
    }
private:
	string expandAroundCenter(string s, int c1, int c2){
		int l = c1, r = c2;
		int n = s.length();
		while(l>=0 && r<=n-1 && s[l]==s[r]){
			l--;
			r++;
		}
		return s.substr(l+1,r-l-1);
	}
};

int main(){
	string s = "bababbaaaaa";
	Solution sol;
	cout<< sol.longestPalindrome(s)<<endl;

	system("pause");

}