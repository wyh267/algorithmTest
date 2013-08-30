


/*

要建立一个信号基站服务n个村庄，这n个村庄用平面上的n个点表示。
假设基站建立的位置在(X,Y)，则它对某个村庄(x,y)的距离为max{|X – x|, |Y – y|}，其中| |表示绝对值，我们的目标是让所有村庄到信号基站的距离和最小。 
基站可以建立在任何实数坐标位置上，也可以与某村庄重合。 

输入： 给定每个村庄的位置x[],y[]，x,y都是整数，
	满足：-1000000000 < x,y < 1000000000 
	村庄个数大于1，小于101。 

输出： 所有村庄到信号基站的距离和的最小值。 

关于精度： 因为输出是double。我们这样判断对错，如果标准答案是A,你的答案是a，如果|Ａ – a| < 1e-3 我们认为是正确的，否则认为是错误的。 

样例： 假设有4个村庄位置分别为 （1，4） （2，3） （0，1） （1，1） 
我们的结果是5。
因为我们可以选择（1.5，2.5）来建立信号基站。 
bestDistance = max(|1.5-1|, |2.5-4|) + max(|1.5-2|,|2.5-3|) + max(|1.5-0|,|2.5-1|) + max(|1.5-1|,|2.5-1|)
			 = max(0.5, 1.5) + max(0.5,0.5) + max(1.5,1.5) + max(0.5,1.5) 
			 = 1.5 + 0.5 + 1.5 + 1.5 = 5 
			 

*/
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

struct myclass {
  bool operator() (int i,int j) { return (i<j);}
} myobject;



double bestDistance(int n, const int *x, const int *y)
{

	double sum=0;
	long long sumX=0,sumY=0,sumXX=0,sumYY=0;
	int k;
	vector<int>X;
	vector<int>Y;

	
	
	for(int i=0;i<n;i++)
	{
		X.push_back(x[i]+y[i]);
		Y.push_back(x[i]-y[i]);
		
	}



	sort(X.begin(),X.end(),myobject);
	sort(Y.begin(),Y.end(),myobject);


	for(int i = 0; i <= n / 2 - 1; i++)   
	{        
		sumX = sumX + X[i];  
		sumY = sumY + Y[i];   
	}   
	 

	if(n % 2 == 0)   
		k = n / 2 ;   
	else   
	 	k = n / 2 + 1;
	
	for(int i  = k; i <= n - 1; i++)   
	{        
		sumXX = sumXX + X[i];  
		sumYY = sumYY + Y[i]; 
	}   

 	sum = (sumXX - sumX + sumYY - sumY) / 2.0;

	return sum;
}



int main()
{
	//const int x[4]={1,2,0,1};
	//const int y[4]={4,3,1,1};
	const int x[19] = {858442934,-161749718,-55910439,347569202,-660170269,-982075453,-860790164,947179323,312298821,-285196111,967545126,-777105315,-630974471,-713895350,745616673,840630174,-597730146,-205693089,24677872};   
	const int y[19] = {449535070,160026431,705809990,121634879,648304545,-392329548,-447666131,-829918127,926665890,943182185,601133076,-848803337,89719473,-586785144,832132969,-111884761,-556530757,65860874,978639057};   
		
	//cout << bestDistance( 19, x,  y) <<endl;
	 printf("\nthe result is %lf\n",bestDistance(19 , x , y));   
	return 0;
} 




