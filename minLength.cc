/*
	字符串消除
	给定一个字符串，仅由a,b,c 3种小写字母组成。当出现连续两个不同的字母时，
	你可以用另外一个字母替换它，
	如 有ab或ba连续出现，你把它们替换为字母c； 
	有ac或ca连续出现时，你可以把它们替换为字母b；
	有bc或cb 连续出现时，你可以把它们替换为字母a。 
	你可以不断反复按照这个规则进行替换，你的目标是使得最终结果所得到的字符串尽可能短，
	求最终结果的最短长度。 
	输入：字符串。长度不超过200，仅由abc三种小写字母组成。 
	输出： 按照上述规则不断消除替换，所得到的字符串最短的长度。 
	
	例如：输入cab，输出2。因为我们可以把它变为bb或者变为cc。           
		  输入bcab，输出1。尽管我们可以把它变为aab -> ac -> b，
						   也可以把它变为bbb，但因为前者长度更短，所以输出1。 
						   
*/

#include <iostream>
#include <string>
#include <string.h>



using namespace std;


int firstIndex(string s)
{
	char head=s[0];

	for(int i=1;i<s.length();i++)
		{
			if(head != s[i])
				return i-1;
		}

	return -1;

}


int secondIndex(string s)
{
	char head=s[0];
	int flag=0;

	for(int i=1;i<s.length();i++)
		{
			if(head != s[i])
				{
					if(i<s.length()-1)
						return i;
					else
						return -1;
				}
		}

	return -1;


}


string replace(string s)
{

	if(s=="ab" || s =="ba")
		return "c";

	if(s=="ac" || s=="ca")
		return "b";

	if(s=="bc" || s=="cb")
		return "a";

	return s;

}


string change(string s,int flag)
{
	int firstPos=0;
	int secondPos=0;

	if(flag==1)
		{
			firstPos=firstIndex(s);
			//cout << " first pos : " << firstPos << endl;
			string newStr=s.substr(0,firstPos) + replace(s.substr(firstPos,2)) + s.substr(firstPos+2,s.length()-firstPos-2);
			cout << " first pos : " << firstPos << " String 1:" << newStr << endl;
			return newStr;

		}else
			{
				secondPos=secondIndex(s);
				if(secondPos==-1)
					return s;
				else
					{
						string newStr2=s.substr(0,secondPos) + replace(s.substr(secondPos,2)) + s.substr(secondPos+2,s.length()-secondPos-2);
						cout << " second pos : " << secondPos <<" String 2:" << newStr2 << endl;
						return newStr2;
						
					}
				
			}

	return "aaa";
}



int countSameChars(string s)
{
	
	char head=s[0];
	int count=0;

	for(int i=0;i<s.length();i++)
		{
			if(head != s[i])
				return count;

			count++;
		}
	return count;

}



int _minLength(string s)
{

	cout <<"String :" <<  s << endl;
	if(countSameChars(s)==s.length())
		return s.length();


	string ss1=change(s,1);	
	string ss2=change(s,2);

	if(countSameChars(ss1) <= countSameChars(ss2))
		return _minLength(ss1);
	else
		return _minLength(ss2);

	//return _minLength(ss1);
}


int minLength(const char *s)
{

	string destStr=string(s);

	return _minLength(destStr);
}




int main()
{

	//string s="abcabcabcabc";
	const char   *s="bcab";
	cout << minLength( s)<<endl;

}



