
#include <iostream>

using namespace std;

int run(const int *a,int n)
{
	int *b=(int *)malloc(sizeof(int)*n);
	int count=0;
	int temp;
	for(int i=0;i<n;i++)
		b[i]=a[i];
	
	
	for(int i=0;i<n;i++)
	{
		for(int k=i;k<n;k++)
		{
			if(b[k]==i+1 && k!=i)
			{
				count++;
				temp=b[k];
				b[k]=b[i];
				b[i]=temp;
			}
		}
	}
	
	return count;
}



int main()
{
	const int a[5]={4,5,3,2,1};
	
	
	cout << run(a,5) << endl;
	
	return 0;
}

