/*

有两个容器，容积分别为A升和B升，有无限多的水，现在需要C升水。
我们还有一个足够大的水缸，足够容纳C升水。起初它是空的，我们只能往水缸里倒入水，而不能倒出。
可以进行的操作是：
把一个容器灌满；
把一个容器清空（容器里剩余的水全部倒掉，或者倒入水缸）；
用一个容器的水倒入另外一个容器，直到倒出水的容器空或者倒入水的容器满。
    问是否能够通过有限次操作，使得水缸最后恰好有C升水。

输入：三个整数A, B, C，其中 0 < A , B, C <= 1000000000
输出：0或1，表示能否达到要求。

*/


#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;



int mod(int a,int b)    
{   
    return b?mod(b, a%b):a;     
}    
    
bool can(int a,int b,int c) {    
    int res;  
    res=mod(a,b);  
      
    if(c%res==0)  
        return true;    
    else   
        return false;    
}  



int main()
{
	
	cout << can(3,4,5) << endl;
	
	return 1;
}