#include <iostream>
#include <stdlib.h>

using namespace std;

struct ListNode {
    int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
	    if(l1 == NULL){
		    if(l2 == NULL){ return NULL;}
		    return l2;
	    }
	    int carry = 0, num1 = 0, num2 = 0;
	    int sum = 0;
	    ListNode *ret =NULL ;
	    ListNode *result = NULL; 

	    while(l1!= NULL || l2!=NULL ||carry!=0){
		
		     num1 =( l1== NULL)? 0: l1->val;
		     num2 =( l2== NULL)? 0: l2->val;
		    sum =  num1+num2+carry;
		    if(sum >9){
			carry = sum/10;	
			sum = sum%10;
		    }else{
			carry = 0;
		    }
		    if(ret == NULL){ 
			    result = new ListNode(sum);
			    ret = result ;
		    }else{
			 result->next = new ListNode(sum);
			 result = result->next;
		    }
		    
		    l1 =( l1 ==NULL)?NULL: l1->next;
		    l2 =( l2 ==NULL)?NULL: l2->next;  
	    }/* end of while loop*/

	    return ret;
    }
};

int main(){
	Solution sol;
	ListNode *out;

	ListNode a1 = ListNode(0);
	/*ListNode a2 = ListNode(8);
	ListNode a3 = ListNode(3);

	a1.next = &a2;
	a2.next = &a3;
*/

	ListNode b1 = ListNode(0);
/*	ListNode b2 = ListNode(3);
	b1.next = &b2;*/


	out = sol.addTwoNumbers(&a1,&b1);
	 
	system("pause");
}