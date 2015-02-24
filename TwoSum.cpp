# include <iostream>
# include <stdlib.h>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> resultVec;
        int leftover = 0;
	map<int, int> mymap;
	mymap.empty();
	//store into map as <number, index>
	for(vector<int>::size_type st = 0; st < numbers.size(); st++){
		mymap[numbers[st]]= st;
	}
	for(vector<int>::size_type st = 0; st < numbers.size(); st++){
		leftover = target - numbers[st];
		if((mymap.find(leftover))!= mymap.end() && (mymap[leftover])!= (int)st){
			/*incase it finds the same number again*/
			resultVec.push_back((int)st+1);
			resultVec.push_back(mymap[leftover]+1);
			break;
		}
	}
	return resultVec;
    }
};

int main()
{
	vector<int> input;
	vector<int> output;
	Solution sol;
	input.push_back(3);
	input.push_back(2);
	input.push_back(4);
	/*input.push_back(0);*/
	output = sol.twoSum(input, 6);
	cout<<output[0]<<" "<<output[1]<<endl;

	system("pause");
}