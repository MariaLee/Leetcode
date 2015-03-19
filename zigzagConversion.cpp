#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {

	    if(nRows == 0 || s.length() == 0 ){
		return "";
	    }

	    if(nRows == 1) {return s;}

	    string out;
	    int n = s.length();
	    int size = 2*nRows -2;
	    for(int i = 0; i< nRows; i++){
		    for(int j = i; j< n; j = j+size){
			    out.append(1,s[j]);
			    if( i!= 0 &&i!= nRows-1 && (j+size-2*i)<n){
				out.append(1,s[j+size-2*i]);
			    }
		    }
	    }
	    return out;
    }
};
int main()
{
	Solution sol;
	cout << sol.convert("ABX", 1) <<endl;

	system("pause");
}