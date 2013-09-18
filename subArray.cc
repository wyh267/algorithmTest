/*

	本题同样来自caopengcs，只要你有兴趣，每个人都可以出题（出题入口在主页右侧边栏“贡献题目”->“我要发布”内），以下是题目详情： 

	子序列的定义：对于一个序列a=a[1],a[2],......a[n]，则非空序列a'=a[p1],a[p2]......a[pm]为a的一个子序列
	
		- 其中1<=p1<p2<.....<pm<=n。 例如：4,14,2,3和14,1,2,3都为4,13,14,1,2,3的子序列。 
		- 对于给出序列a，有些子序列可能是相同的，这里只算做1个
	
	要求输出a的不同子序列的数量。 

	输入:
		长度为n的数组1<=n<=100,数组元素0<=a[i]<=110 

	输出:
		子序列 的个数对1000000007取余数的结果(由于答案比较大，输出Mod 1000000007的结果即可)


*/


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
 
 
 
 