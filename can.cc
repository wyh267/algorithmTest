#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

struct myclass {
  bool operator() (int i,int j) { return (i>j);}
} myobject;


bool dg(int sum,vector<int> v,int c)
{
	vector<int> v1=v;
	if(v.size()==1)
	{
		for(int i=0;i<=c/v.front();i++)
		{
			if(i*v.front()+sum==c)
			{
				cout << i << " - " << v.front() << " ==>" ;
				return true;
			}
		}
		return false;
	}
	
	vector<int>::iterator it = v1.begin();
	v1.erase(it);
	for(int i=0;i<=c/v.front();i++)
		if(dg(i*v.front(),v1,c)==true)
	{
		cout << i << " - " << v.front() << " ==>" ;
		return true;
	}
			
	
	return false;
	
}


bool can(int a,int b,int c)
{
	int d;
	int e;
	int min;
	int max;

	vector<int> list;
	
	if(a == 0 && b == 0)
		return false;
	
	
	
	list.push_back(a);
	list.push_back(b);
	max = a > b ? a : b;
	min = a > b ? b : a;
	int x=min;
	while(1)
	{
		//cout << x % max << endl;
		if(c % (x%max) == 0)
			return true;
		x=x+min;
	}
	
	d=max;
	while(d>min)
	{
		d=d-min;
	}
	
	list.push_back(d);
	
	e=0;
	do
	{
		e=e+min;
	}while(e<max);
	e=e-min;
	e=min-(max-e);
	list.push_back(e);
	
	cout << " A: " << a << endl;
	cout << " B: " << b << endl;
	cout << " D: " << d << endl;
	cout << " E: " << e << endl;
	cout << " C: " << c << endl;
	
	
	for(int i=0;i<list.size();i++)
	{
		cout << list[i] << "---";
	}
	cout << endl;
	
	vector<int>::iterator it = list.begin();
	while (it != list.end()) {
	    if (*it == 0) {
	        it = list.erase(it);
	    } else {
			if(c >= *it && c%(*it)==0)
				return true;
	        it++;
	    }
	}
	
	
	int flag=0;
	for(it = list.begin();it != list.end();it++)
	{
		if(c < (*it))
			flag++;
	}
	if(flag==list.size())
		return false;
	
	
	sort(list.begin(),list.end(),myobject);
#if 0
	sort(list.begin(),list.end(),myobject);
	int mod;
	for(int i=0;i<list.size();i++)
	{
		cout << list[i] << "---";
		mod=c%list[i];
		if(mod==0)
			return true;
		
	}
	return false;
	cout << " AFT " <<endl;
#endif
	return dg(0,list,c);	
	
	
	
}


int mod(int a,int b)  
{ 
	cout << a << " " << b << endl; 
	
    if(a<b)
		return mod(b,a);  
    if(b==0)
		return a;  
    
	return mod(b,a%b);   
}  
  
  
bool can1(int a,int b,int c) {  
    int m=mod(a,b);
	cout << " m " << m <<endl;
    if(c%m==0)return true;  
    else return false;  
}


int main()
{
	
	cout << 3%6 << endl;//8807,6997,5000081
	if(can1(4,6,19)==true)
		cout << " YES " << endl;
	else
		cout << "NO" << endl;
	
	
	return 1;
}