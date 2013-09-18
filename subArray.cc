#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <math.h>
//#include <sstream>

using namespace std;




int run(const int *a,int n)
 {
	 long long  subArray[220];  
	 int lastSameIndex[220];  
	 int MOD=1000000007;
     
	 for(int i=0;i<220;i++)
	 {
		 lastSameIndex[i]=0;
		 subArray[i]=0;
	 }
	 
	 
	 for(int i=1;i<=n;i++)
	 {
	     subArray[i]=(subArray[i-1]*2)%MOD;  
	     if(lastSameIndex[a[i-1]] == 0 )
	     {
			 subArray[i]=subArray[i]+1;         
	     }
	     else 
	     {
			 subArray[i]=(subArray[i]-subArray[lastSameIndex[a[i-1]]-1]+MOD)%MOD;
	     }
	     lastSameIndex[a[i-1]]=i; 
	 }
     
	 //cout << subArray[n]%MOD << endl;
	 return subArray[n]%MOD ;
 }



 



 
 int main()
 {
	 //int a[6]={4,13,14,1,2,3};
 	int a[4]={1,2,7,2};
	 cout << run(a,4) << endl;
	
	
 }
 
 
 
 