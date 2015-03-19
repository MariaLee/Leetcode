#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int i = 0;
	int j = height.size()-1;
	int area = 0;
	while(i<j){
		area = max(area,(j-i)*(min(height[i],height[j])));
		if(height[i]>height[j]){
			j--;
		}else{
			i++;
		}
	}
	return area;
    }
};

int main(){
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	Solution sol;
	cout <<sol.maxArea(vec)<<endl;
	system("pause");
}