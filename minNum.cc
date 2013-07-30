
/*

给了A、B两个单词和一个单词集合Dict，每个的长度都相同。
我们希望通过若干次操作把单词A变成单词B，每次操作可以改变单词中的一个字母，同时，新产生的单词必须是在给定的单词集合Dict中。
求所有行得通步数最少的修改方法。    



举个例子如下： 
Given:    
A = "hit"    
B = "cog"    
Dict = ["hot","dot","dog","lot","log"] 

Return  
[["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]     

即把字符串A = "hit"转变成字符串B = "cog"，有以下两种可能： 

"hit" -> "hot" ->  "dot" ->  "dog" -> "cog"
"hit" -> "hot" ->  "lot" ->  "log" -> "cog"

*/

#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


class Solution
{
public:
Solution(){};
    
	
	//比较函数，比较两个字符串的差别是否为1，如果不唯一，返回-1
    int cmp(string a,string b)
    {
        int flag=0;
    
        for(int i= 0; i< a.size(); i++ )
            {
                if(a[i]!=b[i])
                    flag++;
                if(flag==2)
                    return -1;
            }
	   if(flag==1)	
       		return 0;
	   else
		    return -1;
    
    }

	
	//辅助函数，返回向量中最后一个元素的索引
    int last(string str,vector<string> strv)
    {
        for(int i=0;i<strv.size();i++)
            if(str == strv.at(i))
                return i;

        return -1;
    }

 
	//计算路径
    int Size(int a)
        {
            int b=a;
            if(a==0)
                return 9999;
            else
                return b;
        }


		//辅助函数，显示
 	void display(vector< vector< string > > wayList)
     {
         for(int i=0;i<wayList.size();i++)
             {
                 for(int j=0;j<wayList[i].size();j++)
                    cout << wayList[i].at(j) << "-->";

                cout << endl;
             }
     }
	 
	 //主函数
    vector< vector<string> > findLadders(string start, string end, set<string>& dict)
    {
        vector< vector < string > > Res;    //返回值
        set <string>::iterator si;      
        int max_len=dict.size()+2;          //向量的长度，+2表示起始字符串和结束字符串
        /*
		二维向量保存各个路径，第一行表示start字符串，第二行表示end字符串，后面各行表示dict的各个字符串
		"hit"-->"hot"...
		"hit"-->"dot"
		...
		...
		*/
		vector< vector< string > > wayList; //路径的二维向量，
        vector<string> str;                 //保存所有字符串的向量


		if(start == end)
		    return Res;

		/*将数据添加到字符串向量中*/
    	str.push_back(start);
    	str.push_back(end);
     	for (si=dict.begin(); si!=dict.end(); si++) 
         {
         	str.push_back(*si);
         }

		 //构造二维向量列的长度
    	 wayList.resize(max_len);


		 //如果有向量和start只相差一个字符，就将向量添加到二维向量表中
     	for(int i=0;i<max_len;i++)
        {
            if(cmp(str.at(0),str.at(i))==0)
                {
                    wayList[i].push_back(str.at(i));
                }
        }  


		int flag=0;
		while(flag==0)
		{    
			//检索所有向量
    		for(int i=0;i<max_len;i++)
        	{
			//不检索1式因为1保存的是end
            if(i!=1)
            {
				//检查所有向量
              for(int j=0;j<max_len;j++)
               {
				   //如果该列的向量大于0，表示有一条路径
                 if(wayList[i].size()>0)
                 {
					//比较该列最后一个元素是否有相邻的元素                  
                  if(cmp(wayList[i].back(),str.at(j))==0)
                  {
					  //如果有，比较这条路径的长度和已知的路径长度的大小
                   if(Size(wayList[j].size())>=Size(wayList[last(wayList[i].back(),str)].size())+1)
                    {
						//如果这条路径长度小于已知路径，那将已知路径删除，变成这条路径
						wayList[j].clear();
                        for(int t=0;t<wayList[last(wayList[i].back(),str)].size();t++)
                            wayList[j].push_back(wayList[last(wayList[i].back(),str)].at(t));
                        wayList[j].push_back(str.at(j));
  
  					  	//如果索引为1，表示已经检索到end字符串，表示已经找出来一条路径了
                        if(j==1)
                        {
						  //检查路径是否重复	
                         for(int m=0;m<Res.size();m++)
                         {
                           if(Res.at(m)==wayList[j])
                               flag=1;
                                                            
                          }
						  
						  //如果不重复，表示路径正确，添加到返回值中
                         if(flag==0)
                         {
                             vector <string> res;
                             for(int t=0;t<wayList[j].size();t++)
                                 {
                                     res.push_back(wayList[j].at(t));
                                  }
                             Res.push_back(res);
                          }
                         }//end if(j==1)

                     }//end if(Size(wayList[j].size())>=Size(wayList[last(wayList[i].back(),str)].size())+1)
                    }// end if(cmp(wayList[i].back(),str.at(j))==0)
                   }// end if(wayList[i].size()>0)
                  }//end for   
                }// end if(i!=1)
        	}//end for
			//找到重复路径，表示已经检索完毕，结束循环
    		if(flag==1)
        		break;
		}//end while
		for(int i=0;i<Res.size();i++)
		 {
		  Res[i].insert(Res[i].begin(),start);           
		 }
        return Res; 
    }
};


//start 提示：自动阅卷起始唯一标识，请勿删除或增加。
int main()
{   
    //
	vector < vector <string> > res;
    set <string> strset;
    strset.insert("hot");
    strset.insert("dot");
    strset.insert("dog");
    strset.insert("lot");
    strset.insert("log");
    std::cout << "cog" <<std::endl;
    Solution *s=new Solution();
    res=s->findLadders("hit","cog",strset);
	
	for(int i=0;i<res.size();i++)
	{
		for(int j=0;j<res[i].size();j++)
			cout << res[i].at(j) << "-->";
		cout << " " << endl;
	}
	
	
	
    return 0;
}