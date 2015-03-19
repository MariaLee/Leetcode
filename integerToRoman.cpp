#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
	    int romNum[]={1,4,5,9,10, 40, 50,90,100,400,500,900,1000};
	    string romStr[]={"I","IV","V","IX","X","XL","L", "XC","C","CD","D","CM","M"};
	    int i = 12; //there are 13 numbers
	    int k;
	    string result;
	    while(num>0){
		k=num/romNum[i];
		while(k>0){
			result+=romStr[i];
			k--;
			num=num-romNum[i];
		}
		i--;
	    }
	    return result;
    }
};

int main(){
	Solution sol;
	cout<< sol.intToRoman(129)<<endl; 
	system("pause");
	return(0);
}