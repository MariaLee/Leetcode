#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
#define MAX  2147483646 
class Solution {
public:
    int reverse(int x) {
	if(x == 0) return 0; 
        int num = (x>0)? x:-x;
	int rem;
	long long out = 0,time=1;
	vector<int> vec;
	while(num >0){
		rem = num%10;
		num = num/10;
		vec.push_back(rem);
	}
	for(vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++){
		out += *it *time;
		time = time*10;
	}
	if(out > MAX) return 0;
	out = (x>0)? out: -out;
	return (int)out;
    }
};

int main()
{
	Solution sol;
	cout <<sol.reverse( -2147483648)<<endl;
	system("pause");
}