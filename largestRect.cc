
/*

给定直方图，每一小块的height由N个非负整数所确定，每一小块的width都为1，请找出直方图中面积最大的矩形。

如下图所示，直方图中每一块的宽度都是1，每一块给定的高度分别是[2,1,5,6,2,3]：

      |
    | |
    | |
    | |   |
|   | | | |
| | | | | |

面积最大值是5和6那个矩形，面积为10

*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


int shortest(vector<int> arr,int start,int end)  
{  
    int shortest=arr[start];  
    int index=start;  
    int i;  
    if(start==end)  
    {  
        return index;   
    }  
          
      
    for(i=start;i<=end;i++)  
    {     
        if(shortest>=arr[i])  
        {  
            shortest=arr[i];  
            index=i;  
        }  
    }  
      
    return index;  
      
}  
  
int largestRectangleArea(vector<int> &height) {  
    //wirte your code hero  
    int area=0;  
    int max=0;  
    int height_index=0;  
    for(int i=0;i<height.size();i++)  
    {  
  
        for(int j=i;j<height.size();j++)  
        {  
  
            height_index=shortest(height,i,j);  
            area=(j-i+1)*(height[height_index]);  
            if(max < area)  
                max=area;  
  
        }  
    }  
      
    return max;  
} 


int main()
{
	vector<int> height;
	height.push_back(2);
	height.push_back(1);
	height.push_back(5);
	height.push_back(6);
	height.push_back(2);
	height.push_back(3);
	
	cout << largestRectangleArea(height) << endl;
	
	return 1;
	
}
