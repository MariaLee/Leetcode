#include <iostream>
#include <math.h>
using namespace std;
/* HARD*/
/*There are two sorted arrays A and B of size m and n respectively.
Find the median of the two sorted arrays. 
The overall run time complexity should be O(log (m+n)).*/

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
	    if((m+n)%2 == 0){ /* even number*/
		return 1.0 * (kthNum(A,m,B,n,(m+n)/2) + kthNum(A,m,B,n,(m+n)/2+1))/2;
	    }else{ /* odd number*/
		    return 1.0* kthNum(A,m,B,n,(m+n)/2+1);
	    }
    }
private :
	double kthNum(int A[], int m, int B[], int n, int k){
		if(m>n){/* let A be the array with less numbers*/
			return kthNum(B,n,A,m,k);
		}
		if(m == 0){
			return B[k-1];
		}
		if(k == 1){
			return min(A[0],B[0]);
		}

		int aa = k/2;
		if(aa > m){
			aa = m;
		}
		int bb = k-aa;

		if(A[aa-1]< B[bb-1]){
			return kthNum(A+aa,m-aa,B,n,k-aa);
		}else if(A[aa-1]> B[bb-1]){
			return kthNum(A,m,B+bb,n-bb,k-bb);
		}else{
			return A[aa-1];
		}
	}

};

int main(){
	int A[]= {1,3,4,4};
	int B[] = {2,2,4,5};

	Solution sol;
	cout<< sol.findMedianSortedArrays(A, 2,B,4)<<endl;

	system("pause");

}