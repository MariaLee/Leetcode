#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 1;
	int maxLenBegin = 0;
	int n = s.length();
	bool table[1000][1000] = {false};

	for(int i = 0; i< n; i++){
		table[i][i] = true;
	}
	for(int i = 0; i< n-1; i++){
		if(s[i] == s[i+1]){
			table[i][i+1] = true;
			maxLen = 2;
			maxLenBegin = i;
		}
	}
	
	for(int len = 3; len <= n; len++){
		for(int i = 0; i < n-len+1; i++){
			int j = i+len-1;
			if(s[i] == s[j] && table[i+1][j-1] == true){
				maxLen=len;
				maxLenBegin = i;
				table[i][j] = true;
			}
		}
	}

	return s.substr(maxLenBegin, maxLen);

    }
};

int main(){
	string s = "bbabcbaaaa";
	Solution sol;
	cout<< sol.longestPalindrome(s)<<endl;

	system("pause");

}