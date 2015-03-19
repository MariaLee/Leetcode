#include <iostream>
using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
	  if( s== NULL || p == NULL || *p == '*') return false;
	  if( *p == '\0') return *s=='\0';
	  
	  if(*(p+1) == '*'){
		  if(isMatch(s,p+2)) return true;
		  for(int i = 0; i<(int)strlen(s); i++){
			  if(*p !='.' && *p!=*(s+i)) return false;
			  if(isMatch(s+i+1,p+2)) return true;
		  }
		  return false;
	  }else{
		  if(*s == '\0' ) return false;
		if(*p!='.' && *p!=*s) 
		{return false;}
		return isMatch(s+1,p+1);
	  }
    }
};

int main(){
	const char* s = "aaa";
	const char*p = "a.a";

	Solution sol;
	cout <<sol.isMatch(s,p)<<endl;
	system("pause");
	return 0;
}