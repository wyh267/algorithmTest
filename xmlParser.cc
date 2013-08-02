/*


本题来自蓝港在线技术团队的idea，详情如下：
XML-可扩展标记语言 ，用于标记电子文件使其具有结构性的标记语言，可以用来标记数据、定义数据类型，
是一种允许用户对自己的标记语言进行定义的源语言，被广泛的运用于数据传输和存储。请编写一段程序，
不使用语言之外的开源库，解析对应的XML文件，并把输出结果打印出来。

举个例子如下，当给定下述XML文件时（注：不需要将输入输出格式话，只是举个例子）：
<?xml version="1.0" ?>
<Books>
<Book>
<Name = “The C++ Programming Language” Author=”Bjarne Stroustrup” />
</Book>
<Book>
<Name = “Effective C++” Author = “Scott Meyers” />
</Book>
</Books>
它应该输出：
Books
 Book 1
     Name:The C++ Programming Language
     Author:Bjarne Stroustrup
 Book 2
     Name:Effective C++
     Author:Scott Meyers

本题输入：简化的一段xml文件，用字符串表示，如下（属性名字不包含引号和等号，也不包含大于小于等特殊字符，详细规则见下面的答题说明）

string in = "<?xml version=\"1.0\" ?><Books><Book><Name = \"The C++ Programming Language\" Author=\"Bjarne Stroustrup\" /></Book><Book><Name = \"Effective C++\" Author = \"Scott Meyers\" /></Book></Books>";


本题输出：对输入的xml字符串解析，得到输出如下：

string out = "Books\r\n\tBook 1\r\n\t\tName:The C++ Programming Language\r\n\t\tAuthor:Bjarne Stroustrup\r\n\tBook 2\r\n\t\tName:Effective C++\r\n\t\tAuthor:Scott Meyers";



*/


#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>

using namespace std;

string ParsingProper(string proper)
{
    string properDic="";
    string res="";
    int sybFlag=1;
    int start=0;
    bool searchKey=true;
    bool searchValue=false;
    string::iterator it=proper.begin();
    for(;it<proper.end();it++)
    {
        if((*it)=='\"')
        {
            sybFlag=0-sybFlag;
        }
        
        if(sybFlag==1 && (*it)==' ')
        {
            proper.erase(it);
            it--;
        }
    }
    string key;
    string value;
    for(int i=0;i<proper.size();i++)
    {
        if(searchKey==true)
        {
            if(proper[i]=='=')
            {
                
                key=proper.substr(start,i-start);
                start=i;
                searchKey=false;
            }
        }else
        {
            if(proper[i]=='\"')
            {
                if(searchValue==false)
                {
                    start=i+1;
                    searchValue=true;
                }else
                {
                    
                    value=proper.substr(start,i-start);
                    start=i+1;
                    searchValue=false;
                    searchKey=true;
                    properDic=properDic+"\t\t" + key +":"+value+"\r\n";
                }
                
            }
            
        }
        
    }
    
    //cout << properDic << endl;
    
    return properDic;
    
    
    
}

vector<string> ParsingPropers(vector<string> &propers)
{
    vector<string> res;
    //res.resize(0);
    if(propers.size()<1)
        return res;
    
    for(int i=0;i<propers.size();i++)
    {
         
         res.push_back(ParsingProper(propers[i]));
    }
    
    return res;
}

string ParsingSubNodes(vector<string> &nodes)
{
    if(nodes.size()<2)
        return "";
    int count=1;
    string node="/" + nodes[0];
    vector<string> proper;
    vector<string> resProper;
    string res="";
    for(int i=1;i<nodes.size();i++)
    {
        
        if(nodes[i]==node)
        {
            //cout << "catch node : " << node << endl;
            char buf[10];
            sprintf(buf, "%d", count);
            string b = buf;
            res += "\t" + node.substr(1,node.size()-1) + " " + b +"\r\n";    
            count++;    
            resProper=ParsingPropers(proper);            
            proper.clear();

            for(int k=0;k<resProper.size();k++)
            {
                res = res + resProper[k] ;
            }
            
            if(i+1 < nodes.size())
            {
                node="/" + nodes[i+1];
                i++;
            }            
            else
                return res;
        }else
        {
            
            proper.push_back(nodes[i]);
        }
    }
    
    return "";
    
    
}


string ParsingRoot(vector<string> &nodes)
{
    
    if(nodes.size()<2)
        return "";
    
    string root="/" + nodes[0];
    
    for(int i=1;i<nodes.size();i++)
    {
        if(nodes[i]==root && i==nodes.size()-1)
        {
            //cout << "catch root : " << nodes[0] << endl;
            root=nodes[0];
            nodes.pop_back();
            nodes.erase(nodes.begin());
            return root;
        }
    }
    
    
    return "";
}

string ParsingNode(string in,int pos)
{
    string subStr;
    for(int i=pos;i<in.size();i++)
    {
        if(in[i]=='>')
        {
            subStr=in.substr(pos,i-pos);
            break;
        }
    }
    //cout << subStr <<endl;
    return subStr;
}


bool parseHead(string &in)
{
    bool res=false;
    bool flag=false;
    
    for(int i=0;i<in.size();i++)
    {
        if(flag==false)
        {
            if(in[i]=='<')
            {
                flag=true;
            }
        }else
        {
            if(in[i]=='>' && in[i-1]=='?')
            {
                in=in.substr(i+1,in.size());
                //cout << in << endl;
                return true;
            }
        }
    }
    return res;
}


string ParsingXML(string str)
{
    vector<string> Nodes;
    string Root;
    string subStr;
    string Res="";
    
    if(str.size()<1)
        return Res;
    
    if(parseHead(str)==false)
        return Res;
    
    
    for(int i=0;i<str.size();i++)
    {
        //cout << str[i];
        if(str[i]=='<')
        {
            subStr=ParsingNode(str,i+1);
            i=i+subStr.size();
            Nodes.push_back(subStr);
        }
    }
    
    
    Res= Res + ParsingRoot(Nodes) + "\r\n";
    
    Res+=ParsingSubNodes(Nodes);
    
    //for(int i=0;i<Nodes.size();i++)
    //    cout << Nodes.at(i) << endl;
    
    return Res;
    //return "Books\r\n\tBook 1\r\n\t\tName:The C++ Programming Language\r\n\t\tAuthor:Bjarne Stroustrup\r\n\tBook 2\r\n\t\tName:Effective C++\r\n\t\tAuthor:Scott Meyers";
}



//start 提示：自动阅卷起始唯一标识，请勿删除或增加。
int main()
{   
    string out;
    
    out=ParsingXML("<?xml version=\"1.0\" ?><Books><Book><Name = \"The C++ Programming Language\" Author=\"Bjarne Stroustrup\" /></Book><Book><Name = \"Effective C++\" Author = \"Scott Meyers\" /></Book></Books>");
    
    
    cout << out << endl;
    
    cout << "Books\r\n\tBook 1\r\n\t\tName:The C++ Programming Language\r\n\t\tAuthor:Bjarne Stroustrup\r\n\tBook 2\r\n\t\tName:Effective C++\r\n\t\tAuthor:Scott Meyers"<<endl;
    return 1;

} 