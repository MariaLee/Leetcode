#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
       int sum=0, num=0;
	int len=0;
	int tmp;
	num = x;
	while(num>0){
		num = num/10;
		len++;
	}
	num = x;
	while(num >0){
		len--;
		tmp = num%10;
		num = num/10;
		sum+= (int)(tmp*pow(10.0,(double)len));
	}
	if(sum == x){return true;}
	else return false;
    }
};

int main()
{
	Solution sol;
	cout<< sol.isPalindrome(1)<<endl;
	system("pause");
}