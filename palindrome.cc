/*

回文字符串是指从左到右和从右到左相同的字符串，现给定一个仅由小写字母组成的字符串，
你可以把它的字母重新排列，以形成不同的回文字符串。 

输入：非空仅由小写字母组成的字符串，长度不超过100； 
输出：能组成的所有回文串的个数（因为结果可能非常大，输出对1000000007取余数的结果）。 

例如：输入"aabb" 输出为2（因为“aabb”对应的所有回文字符串有2个：abba和baab）


*/

#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <math.h>
//#include <sstream>

using namespace std;



//计算某个字符的个数，每次都是计算首字符的个数，计算完后将该字符从字符串中清除
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
	
	//cout << str << endl;
	
	return count;
}



/* 辅助函数，字符串四则运算和取模开始 */


int COMPARE(string number1, string number2)
{
	int j;
 
	int length1 = number1.size();
	int length2 = number2.size();
 
	if(number1.size() == 0) number1 = "0";
	if(number2.size() == 0) number2 = "0";
 
	j = 0;
	for(int i = 0; i < length1; ++i)
	{
		if(number1[i] == '0') ++j;
		else break;
	}
	number1 = number1.substr(j);
 
	j = 0;
	for(int i = 0; i < length2; ++i)
	{
		if(number2[i] == '0') ++j;
		else break;
	}
	number2 = number2.substr(j);
 
	length1 = number1.size();
	length2 = number2.size();
 
	if(length1 > length2)
	{
		return 1;
	}
	else if(length1 == length2)
	{
		if(number1.compare(number2) > 0)
		{
			return 1;
		}
		else if(number1.compare(number2) == 0)
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}
	else 
	{
		return -1;
	}
 
	return 0;
}
	
	
string PLUS(string number1,string number2)
{
	int i;
	int length1 = number1.size();
	int length2 = number2.size();
 
	string result="";
 
	reverse(number1.begin(), number1.end());
	reverse(number2.begin(), number2.end());
 
	for(i = 0; i < length1 && i < length2; i++)
	{
		char c = (char)(number1[i] + number2[i] - 48);
		result = result + c;
	}
 
	while(i < length1)
	{
		result = result + number1[i]; 
		++i;
	}
 
	while(i < length2)
	{
		result = result + number2[i]; 
		++i;
	}
    
	int carry = 0;
	for(i = 0; i < (int)result.size(); ++i)
	{
		int value = result[i] - 48 + carry;
		result[i] = (char)(value % 10 + 48);
		carry = value / 10;
	}
    
	if(carry !=0 ) 
	{
		result = result + (char)(carry + 48);
	}
 
	for(i = result.size() - 1; i >= 0; i--)
	{
		if(result[i] != '0') break;
	}
 
	result = result.substr(0, i + 1);
 
	reverse(result.begin(), result.end());
	if(result.length() == 0) result = "0";
	return result;
}
 
 
string MINUS(string number1,string number2)
{
	int i;
	string result = "";
 
	int length1 = number1.size();
	int length2 = number2.size();
 
	if(COMPARE(number2,number1) > 0)
	{
		return "-" + MINUS(number2, number1);
	}
 
	reverse(number1.begin(),number1.end());
	reverse(number2.begin(),number2.end());
     
	for(i = 0; i < length1 && i < length2; i++)
	{
		char c = number1[i] - number2[i] + 48;
		result = result + c;
	}
 
	if(i < length1)
	{
		for(; i < length1; i++)
		{
			result = result + number1[i];
		}
	}
    
	int carry = 0;
	for(i = 0; i < (int)result.length(); i++)
	{
		int value = result[i] - 48 + carry;
		if(value < 0)
		{
			value = value + 10;
			carry = -1;
		}
		else carry = 0;
		result[i]=(char)(value + 48);
	}
 
	for(i = result.size() - 1; i >= 0; i--)
	{
		if(result[i] != '0')break;
	}
 
	result = result.substr(0, i+1);
 
	reverse(result.begin(), result.end());
	if(result.length()==0) result = "0";
	return result;
}
	
	
string MULTIPLY(string number1, string number2)
{
	int i, j;
	int *iresult;
	int length1 = number1.size();
	int length2 = number2.size();
	string result = "";
 
	reverse(number1.begin(), number1.end());
	reverse(number2.begin(), number2.end());
 
	iresult = (int*)malloc(sizeof(int) * (length1 + length2 + 1));
	memset(iresult, 0, sizeof(int) * (length1 + length2 + 1));
 
	for(i = 0; i < length1; i++)
	{
		for(j = 0; j < length2; j++)
		{
			iresult[i+j] += ((number1[i] - 48) * (number2[j] - 48));
		}
	}
 
	int carry = 0;
	for(i = 0; i < length1 + length2; i++)
	{
		int value = iresult[i] + carry;
		iresult[i] = value % 10;
		carry = value / 10;
	}
    
	for(i = length1 + length2 - 1; i >= 0; i--)
	{
		if(iresult[i] != 0)break;
	}
 
	for(; i >= 0; i--)
	{
		result = result + (char)(iresult[i]+48);
	}
 
	free(iresult);
 
	if(result == "") result = "0";
	return result;
}
	
string DIVIDE(string number1, string number2, int floatpoint = 0)
{
	int i, j, pos;
	string result = "";
	string tempstr = "";
	int length1 = number1.size();
	int length2 = number2.size();
 
	if((COMPARE(number2, number1) > 0) && (floatpoint == 0))
	{
		return "0";
	}
 
	tempstr = number1.substr(0, length2);
	pos = length2 - 1;
    
	while(pos < length1)
	{
		int quotient = 0;
		while(COMPARE(tempstr, number2) >= 0)
		{
			quotient++;
			tempstr = MINUS(tempstr, number2);
		}
        
		result = result + (char)(quotient + 48);
		pos++;
		if(pos < length1)
		{
			tempstr += number1[pos];
		}
	}
 
	if(floatpoint > 0)
	{
		result += '.';
		string stmp = "1";
		int itmp = 0;
		for(int k = 0; k < floatpoint; ++k)
		{
			stmp += '0';
			if(COMPARE(MULTIPLY(MINUS(number1, MULTIPLY(DIVIDE(number1, number2), number2)), stmp), number2) < 0)
			{
				result += '0';
				++itmp;
			}
		}
 
		string temp = DIVIDE(MULTIPLY(MINUS(number1, MULTIPLY(DIVIDE(number1, number2), number2)), stmp), number2);
		if(temp[0] != '0') result += temp;
	}
 
	j = result.size();
	for(i = 0; i < j; i++) 
	{
		if(result[i] != '0') break;
	}
 
	result = result.substr(i, j);
 
	return result;
}
		
string MOD(string number1, string number2)
{
	if(COMPARE(number2, number1) > 0)
	{
		return number1;
	}
	else if(COMPARE(number2, number1) == 0)
	{
		return "0";
	}
	else
	{
		return MINUS(number1, MULTIPLY(DIVIDE(number1, number2), number2));
	}
}

/* 字符串四则运算和取模结束 */
			


//阶乘		
string fib(int x)
{
	string X;
	char t[256];
	sprintf(t, "%d", x);
	X = t;
				
	if(x==0)
		return "1";
	else
		return MULTIPLY(X,fib(x-1));
}


//计算组合数
string Combination(int m,int n)
{
	string res;
	vector<int> com;
	vector<int>::iterator it;
	for(int i=1;i<n;i++)
	{
		if(i>=(n-m))
			com.push_back(i);
	}
	
	//cout << "Combination "<< m <<" " << n << " is ";
	res=DIVIDE(DIVIDE(fib(n),fib(m),0),fib(n-m),0);
	//cout << res << endl;
	return res;
	
}


//入口函数
int palindrome(const string &s)
{
	string str=s;
	cout << str << endl;
	int count;
	int flag=0;
	int totel=0;
	vector<int> counts;

	string resStr;
	resStr="1";
	do
	{
		//cout << " Char [" << str[0] << "] has " ;
		//计算每个字符的个数
		count= howMany(str);
		//cout << count << endl;
		
		//判断奇数的个数
		if(count % 2 !=0)
		{
			if(flag==0)
			{
				totel=totel+(count-1)/2;
				counts.push_back(count/2);
				flag++;
			}else
			{
				flag++;
			}
			
		}else
		{
			totel=totel+count/2;
			counts.push_back(count/2);
		}
	}while(count!=0);
	
	if(flag == 1 || flag ==0 )
	{
		cout << "has palindrome string,totel is " << totel << endl;
	}else
	{
		cout << "no palindrome string" <<endl;
		return 0;
	}

	for(int i=0;i<counts.size();i++)
	{
		//cout << "count[" << i << "] :" << counts[i] << endl; 
		//计算组合数
		resStr=MULTIPLY(resStr,Combination(counts[i],totel));
		totel=totel-counts[i];
	}
	
	//cout <<"The Res is " <<  MOD(resStr,"1000000007") << endl;
	
	//结果对1000000007取余
	return atoi(MOD(resStr,"1000000007").c_str());//res%1000000007;
	


}


int main()
{
#if 1
	string str="aabbdccddjjkkiiuuyiijjqkkkkkk2222224444446666qqqqqqqqqqqqqqqqqqqqqjjkkqqooddmmffyyyllooppqq";

	cout << " the Res is "<< palindrome(str) << endl;
#endif
	
	return 0;
	
}
