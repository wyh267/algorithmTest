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