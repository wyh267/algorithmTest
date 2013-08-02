## 算法说明 ##

---

都是一些来自[庞果网](http://pongo.cn)的题目，具体算法说明参见[blog](http://blog.csdn.net/ygrx)

### largestRect.cc ###

---
给定直方图，每一小块的height由N个非负整数所确定，每一小块的width都为1，请找出直方图中面积最大的矩形。

如下图所示，直方图中每一块的宽度都是1，每一块给定的高度分别是[2,1,5,6,2,3]：

      	|	
    	| |
    	| |
    	| |   |
	|   | | | |
	| | | | | |

面积最大值是5和6那个矩形，面积为10

---

### minNum.cc ###

---

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
	
---

### palindrome.cc ###

---

回文字符串是指从左到右和从右到左相同的字符串，现给定一个仅由小写字母组成的字符串，你可以把它的字母重新排列，以形成不同的回文字符串。 

- 输入：非空仅由小写字母组成的字符串，长度不超过100； 
- 输出：能组成的所有回文串的个数（因为结果可能非常大，输出对1000000007取余数的结果）。 

例如：

- 输入"aabb" 
- 输出为2（因为“aabb”对应的所有回文字符串有2个：abba和baab）

---

### perfect.cc ###

---

我们要给每个字母配一个1-26之间的整数，具体怎么分配由你决定，但不同字母的完美度不同， 而一个字符串的完美度等于它里面所有字母的完美度之和，且不在乎字母大小写，也就是说字母F和f的完美度是一样的。 

现在给定一个字符串，输出它的最大可能的完美度。 

例如：dad，你可以将26分配给d，25分配给a，这样整个字符串最大可能的完美度为77。

---

### water.cc ###

---

有两个容器，容积分别为A升和B升，有无限多的水，现在需要C升水。

我们还有一个足够大的水缸，足够容纳C升水。起初它是空的，我们只能往水缸里倒入水，而不能倒出。

可以进行的操作是：

- 把一个容器灌满；
- 把一个容器清空（容器里剩余的水全部倒掉，或者倒入水缸）；
- 用一个容器的水倒入另外一个容器，直到倒出水的容器空或者倒入水的容器满。
    
**问是否能够通过有限次操作，使得水缸最后恰好有C升水。**

- 输入：三个整数A, B, C，其中 0 < A , B, C <= 1000000000
- 输出：0或1，表示能否达到要求。

---

### xmlParser.cc ###

---

本题来自蓝港在线技术团队的idea，详情如下：

XML-可扩展标记语言 ，用于标记电子文件使其具有结构性的标记语言，可以用来标记数据、定义数据类型，是一种允许用户对自己的标记语言进行定义的源语言，被广泛的运用于数据传输和存储。

请编写一段程序，不使用语言之外的开源库，解析对应的XML文件，并把输出结果打印出来。

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


- 本题输入：简化的一段xml文件，用字符串表示，如下（属性名字不包含引号和等号，也不包含大于小于等特殊字符，详细规则见下面的答题说明）

	`string in = "<?xml version=\"1.0\" ?><Books><Book><Name = \"The C++ Programming Language\" Author=\"Bjarne Stroustrup\" /></Book><Book><Name = \"Effective C++\" Author = \"Scott Meyers\" /></Book></Books>";`


- 本题输出：对输入的xml字符串解析，得到输出如下：

	`string out = "Books\r\n\tBook 1\r\n\t\tName:The C++ Programming Language\r\n\t\tAuthor:Bjarne Stroustrup\r\n\tBook 2\r\n\t\tName:Effective C++\r\n\t\tAuthor:Scott Meyers";`
	




