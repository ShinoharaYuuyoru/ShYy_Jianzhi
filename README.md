# ShYy_Jianzhi
A personal Jianzhi Offer(剑指Offer) coding repository.

# 知识点整理及个人重点
所有标有**重点**的都应该重点复习！  
直接使用CTRL+F搜索“重点”二字可快速定位。


## JZ1
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
### S1 暴力搜索
时间复杂度 O(n^2)
### S2 优化的搜索
在第一维上从大到小暴力搜索，确定开始点。  
在第二维上进行二分搜索（重点），搜到即true；未搜到则继续，直到false。  
[https://www.cnblogs.com/kyoner/p/11080078.html](https://www.cnblogs.com/kyoner/p/11080078.html)  
时间复杂度 O(n * (logm))
### S3 二分搜索应用在有序二维数组中（重点）
从array[n - 1][0]开始搜索  
大于则i--，小于则j++。搜到即true；未搜到则false。
时间复杂度 O(n + m)


## JZ2
请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
### S 确定新字符串的长度，倒序扫描。


## JZ3
输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
### S 从头扫描链表装入Stack，再操作Stack，即可倒序输出链表。


## JZ4（重点）
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
### S 根据前序，在中序中寻找子树范围（同时也在前序中确定相同的子树范围），递归完成。
[ShYy_LeetCode: 105. Construct Binary Tree from Preorder and Inorder Traversal.cpp](https://github.com/ShinoharaYuuyoru/ShYy_LeetCode/blob/master/105.%20Construct%20Binary%20Tree%20from%20Preorder%20and%20Inorder%20Traversal/105.%20Construct%20Binary%20Tree%20from%20Preorder%20and%20Inorder%20Traversal.cpp)

## JZ5
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
### S 操作双栈实现FILO到FIFO的转变
stack1作为push接收。  
笨方法：每次pop都从stack1拷到stack2，确定pop数，再从stack2拷回stack1。  
优化（重点）：当pop时，若stack2为空（即没有积压的pop数），则将stack1拷贝到stack2；若stack2不为空，则直接return stack2.top()。


## JZ6
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。  
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。  
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。  
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
### S1 一遍扫描
从i = 1位开始扫描。  
if([i] > [i - 1])，继续；  
else if([i] == [i - 1])，记录[i]，继续；  
else([i] < [i - 1])，记录[i]并结束扫描。  
最后返回当前记录数。
### S2 应用二分搜索（重点）
问题在于[mid]与谁相比，以及怎么操作head和tail的位置。
if([head] < [tail])，则直接return[head]。  
else if([mid] > [head])，则表明[head -> mid]为递增序列，令head = mid + 1。  
else if([mid] < [tail])，则表明[mid -> tail]为递增序列，令tail = mid。
else(无法判断)，一步缩小范围，令head++。


## JZ7
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0，第1项是1）。
n<=39
### S1 爆炸递归
### S2 动态规划，填表（重点）
初始：[0] = 0，[1] = 1。  
状态转移：从i = 2开始，[i] = [i - 1] + [i - 2]。
### S3 动态规划，优化填表，只保留需要的两个数
初始：prepre = 0，pre = 1。  
状态转移：now = prepre + pre。prepre = pre，pre = now。


## JZ8
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
### S1 动态规划，填表（重点）
初始：[0] = 0，[1] = 1，[2] = 2。  
状态转移：从i = 3开始，[i] = [i - 1] + [i - 2]。
### S2 动态规划，优化填表，只保留需要的两个数


## JZ9
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
### S1 动态规划，填表（重点）
初始：[0] = 0，[1] = 1。  
状态转移：从i = 2，[i] = [i - 1] * 2。  
### S2 动态规划，优化填表，只保留需要的两个数


## JZ10
我们可以用2\*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2\*1的小矩形无重叠地覆盖一个2\*n的大矩形，总共有多少种方法？  
比如n=3时，2\*3的矩形块有3种覆盖方法。
### S1 动态规划，填表（重点）
初始：[0] = 0，[1] = 1，[2] = 2。  
装填转移：从i = 3开始，[i] = [i - 1] + [i - 2]。


## JZ11
输入一个整数，输出该数32位二进制表示中1的个数。其中负数用补码表示。
### 前言：原码、反码、补码。计算机中均以补码表示。（重点）
[https://www.cnblogs.com/wqbin/p/11142873.html](https://www.cnblogs.com/wqbin/p/11142873.html)
### S1 除2取模：错误，无法解决补码问题。
### S2 移位：与mark = 0x01比较，每次左移mark。（重点）
时间复杂度 O(32)。
### S3 数学方法
若num = 0x1101000，则num - 1 = 0x1100111。则num & (num - 1) = 0x1100000。  
我们发现，当num != 0时，我们可以直接ANS++，并且&的结果使得最左侧的1变为0。  
令num = num & (num - 1)，循环至结束。


## JZ12
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。  
保证base和exponent不同时为0。
### 前言：注意exponent可为负数，需要预处理。
base = 1/ base，exponent = -exponent。
### S1 暴力循环
### S2 快速幂：递归（重点）
if(exponent % 2 == 0)，return quickPow(base, exponent/2) \* quickPow(base, exponent/2)。  
else(exponent % 2 == 1)，return quickPow(base, exponent/2) \* quickPow(base, exponent/2) \* base。
优化：先求得double ret = quickPow(base, exponent/2)以作备用。
### S3 快速幂：非递归（重点）
以二进制表示exponent。
例：exponent = 6 = 0x110。  
X^6 = X^(0\*2^0 + 1\*2^1 + 1\*2^2) = X^0 \* X^(1\*2^1) \* X^(1*2^2)。  
即，在exponent的二进制表示中，遇到1则乘X^(2^n)。


## JZ13
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
### S1 利用多余vector
std::copy(arr.begin(), arr.end(), copy_to.begin());（重点）  
[https://en.cppreference.com/w/cpp/algorithm/copy](https://en.cppreference.com/w/cpp/algorithm/copy)
时间复杂度 O(n)
### S2 In-place
双下标从前到后扫描。扫到奇数的时候，令temp = [j]，将[i] -> [j - 1]的数向后移动一位，并将[i] = temp。  
时间复杂度 O(n^2)
### S3 std::stable_partition
std::partition()和std::stable_partition()的用法。（重点）  
[https://en.cppreference.com/w/cpp/algorithm/partition](https://en.cppreference.com/w/cpp/algorithm/partition) 在此官方示例中给出了quicksort的实现。  
[https://en.cppreference.com/w/cpp/algorithm/stable_partition](https://en.cppreference.com/w/cpp/algorithm/stable_partition)  
C++函数指针、Lambda表达式的用法（重点）。  
[https://www.jianshu.com/p/a4840fb03c15](https://www.jianshu.com/p/a4840fb03c15)  
[https://www.jianshu.com/p/6482fbd3abdf](https://www.jianshu.com/p/6482fbd3abdf)  
[http://c.biancheng.net/view/433.html](http://c.biancheng.net/view/433.html)  
