/*

				1
			1	1	1
		1  	2	3	2	1
	1  	3  	6   7  	6  	3  1

以上三角形的数阵，第一行只有一个数1， 以下每行的每个数，是恰好是它上面的数，左上的数和右上数等3个数之和（如果不存在某个数，认为该数就是0）。

求第n行第一个偶数出现的位置。如果没有偶数，则输出-1。

例如

- 输入1，则输出-1
- 输入3，则输出2
- 输入4，则输出3。
- 输入n(n <= 1000000000)


*/

#include <iostream>



using namespace std;

int run(int n)
{
	if(n<2)
		return -1;
	if(n%2==1)
		return 2;
	if(n%4==0)
		return 3;
	if((n-2)%4==0)
		return 4;
	return 1;
}


int main (int argc, char const *argv[])
{
	
	//int a=1000000000;
	
	cout << run(14) << endl;
	/* code */
	
	return 0;
}