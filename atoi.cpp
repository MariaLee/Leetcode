#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Solution {
public:
    int atoi(string str) {
	if(str.length() == 0) {return 0;}
        int i=0;
	int sign = 1;
	long long out = 0;
	vector<int> vec;

	while(str[i] == ' '){
		i++;
	}
	if(str[i] == '-'){
		sign = -1;
		i++;
	}
	else if(str[i] == '+'){
		i++;
	}
	if(i == str.size()){ return 0;}

	while(i!= str.size() ){
		if(str[i] >'9' || str[i]<'0') break;
		vec.push_back(str[i] - '0');
		i++;
	}
	if(vec.size() == 0) return 0;
	if(vec.size() > 10){
		if(sign == 1){return INT_MAX;}
		else return INT_MIN;
	}

	long long time = 1;
	for(vector<int>::reverse_iterator it = vec.rbegin(); it!= vec.rend(); it++){
		out += *it *time;
		time = time*10;
	}
	out = out*sign;

	if(out > INT_MAX){ 
		return INT_MAX;
	}
	if(out < INT_MIN){ 
		return INT_MIN;
	}

	return (int)out;
    }
};

int main()
{
	Solution sol;
	cout <<sol.atoi("   9223372036854775809 ")<<endl;
	system("pause");
}