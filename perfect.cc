/*

我们要给每个字母配一个1-26之间的整数，具体怎么分配由你决定，但不同字母的完美度不同， 
而一个字符串的完美度等于它里面所有字母的完美度之和，且不在乎字母大小写，也就是说字母
F和f的完美度是一样的。 现在给定一个字符串，输出它的最大可能的完美度。 

例如：dad，你可以将26分配给d，25分配给a，这样整个字符串最大可能的完美度为77。

*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

struct myclass {
  bool operator() (int i,int j) { return (i>j);}
} myobject;

int howMany(string &str)
{
	if(str.size()==1)
	{
		str.erase(0,1);
		return 1;
	}

	
	if(str.size()==0)
		return 0;
	
	string::iterator it;
	char  cmp=str[0];
	int count=0;
	
	for(int i=0;i<str.size();i++)
	{
		if(cmp==str[i])
		{
			count++;
			str.erase(i,1);
			i--;
		}
	}
	
	return count;
}


int perfect(const string &s)
{
	string str=s;
	vector<int> charCounts;
	int count,i,j;
	int perfectNum=0;
	
	transform(str.begin(), str.end(), str.begin(), ::toupper);
	
	do
	{
		count=howMany(str);
		charCounts.push_back(count);
	}while(count>0);
	
	sort(charCounts.begin(),charCounts.end(),myobject);
	
	for(i=0,j=26;i<charCounts.size();i++,j--)
	{
		perfectNum=perfectNum+j*charCounts[i];
		cout << charCounts[i] << " --- ";
	}
		
	
	cout << endl;
	cout << "perfect Num is " << perfectNum << endl;
	return perfectNum;

}



int main()
{
	perfect("DAddfdafdfhjfaodnDFESSDF");
}