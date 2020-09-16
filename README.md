# ShYy_Jianzhi
A personal Jianzhi Offer(剑指Offer) coding repository.

# 知识点+解决方案+个人重点
所有标有**重点**的都应该重点复习！  
直接使用CTRL+F搜索“重点”二字可快速定位。


## JZ1
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
### S1 暴力搜索
时间复杂度 O(n^2)
### S2 优化的搜索
在第一维上从大到小暴力搜索，确定开始点。  
在第二维上进行二分搜索（重点），搜到即true；未搜到则继续，直到false。  
[详解二分查找算法 - murphy_gb - 博客园](https://www.cnblogs.com/kyoner/p/11080078.html)  
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
### S 动态规划，填表（重点）
初始：[0] = 0，[1] = 1，[2] = 2。  
装填转移：从i = 3开始，[i] = [i - 1] + [i - 2]。


## JZ11
输入一个整数，输出该数32位二进制表示中1的个数。其中负数用补码表示。
### 前言：原码、反码、补码。计算机中均以补码表示。（重点）
[原码，补码和反码 - wqbin - 博客园](https://www.cnblogs.com/wqbin/p/11142873.html)
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
[std::copy, std::copy_if - cppreference.com](https://en.cppreference.com/w/cpp/algorithm/copy)
时间复杂度 O(n)
### S2 In-place
双下标从前到后扫描。扫到奇数的时候，令temp = [j]，将[i] -> [j - 1]的数向后移动一位，并将[i] = temp。  
时间复杂度 O(n^2)
### S3 std::stable_partition
std::partition()和std::stable_partition()的用法。（重点）  
[std::partition - cppreference.com](https://en.cppreference.com/w/cpp/algorithm/partition) 在此官方示例中给出了quicksort的实现。  
[std::stable_partition - cppreference.com](https://en.cppreference.com/w/cpp/algorithm/stable_partition)  
C++函数指针、Lambda表达式的用法（重点）。  
[c++ 基础（函数指针） - 简书](https://www.jianshu.com/p/a4840fb03c15)  
[c++基础(lambda) - 简书](https://www.jianshu.com/p/6482fbd3abdf)  
[C++11 Lambda表达式（匿名函数）详解](http://c.biancheng.net/view/433.html)  


## JZ14
输入一个链表，输出该链表中倒数第k个结点。  
### S1 两遍扫描笨方法
扫一次，确定链表总长度，以此确定第二次扫描的循环次数。
### S2 双指针一次扫描（重点）
设置前后指针，距离为(k - 1)，然后一起平移移动至后指针为nullptr为止。


## JZ15
输入一个链表，反转链表后，输出新链表的表头。
### S1 Stack暂存反转
扫描链表，利用一个stack储存，再全部pop以构建反转链表。
### S2 三指针一次扫描（重点）
初始：pre = nullptr，cur = pHead，rear = pHead->next。  
扫描：直到rear == nullptr为止，令cur->next = pre，然后顺次更改pre = cur，cur = rear，rear = rear->next。  
最终：不要忘了cur->next = pre。返回cur。


## JZ16
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
### S1 最笨的办法
依次扫描两个链表，存储所有的值，排序，再创建新链表。
### S2 一次扫描比较法
最朴素的办法。
### S3 递归方法（重点）
1. 首先，思考递归终结条件：如果任意一方为nullptr，返回另一方。  
2. 其次，思考递归过程（范围缩小过程）：如果pHead1->val小于另一方，则进行递归：pHead1->next = Merge(pHead1->next, pHead2);。反之，反之。  
3. 最后，我们要返回的链表头：返回小的那一方。


## JZ17
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
### S1 二叉树的前中后序遍历并比较（重点）
重点复习递归方法、非递归方法的二叉树的前中后序遍历：[ShYy_Jianzhi: JZ17. BinaryTreeTraversal.cpp](https://github.com/ShinoharaYuuyoru/ShYy_Jianzhi/blob/master/JZ17/BinaryTreeTraversal.cpp)  
Reference: [二叉树——前序遍历、中序遍历、后序遍历、层序遍历详解(递归非递归) - bigsai - 博客园](https://www.cnblogs.com/bigsai/p/11393609.html)  
比较的时候，使用了std::search方法：auto result = search(tree1.begin(), tree1.end(), tree2.begin(), tree2.end());。具体见：[std::search - cppreference.com](https://en.cppreference.com/w/cpp/algorithm/search)  
同时可以复习std::find方法：[std::find, std::find_if, std::find_if_not - cppreference.com](https://en.cppreference.com/w/cpp/algorithm/find)  
### S2 递归方法（重点）
1. 首先，思考递归终结条件：如果node1或node2为nullptr，则return false；否则进行递归。
2. 其次，思考递归过程（范围缩小过程）：node1和node2直接进行子树比较；node1的左子树和node2比较；或node1的右子树和node2比较。
3. 其中，子树比较过程也是一个递归过程。
    1. 思考递归终结条件：如果node1 == nullptr，则return false；如果node2 == nullptr，则return true。
    2. 递归过程：当前两节点node1和node2，其值应当相等，同时其左子树应当相等，同时其右子树应当相等。


## JZ18
操作给定的二叉树，将其变换为源二叉树的镜像。
### S1 递归
递归地遍历左右子树并交换。
### S2 非递归（队列，广搜）（重点）
维护队列。对队头节点，其左右节点进行交换，并将左右节点入队。直至队列为空。注意跳过nullptr。


## JZ19
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
### S 限制范围地进行遍历
限定上、右、下、左四个边界。  
每一次大循环包含四个小循环（即转一圈）。每一次小循环后都要进行大循环退出检查（边界检查）。


## JZ20
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
### S 最小栈（重点）
注意：本解法没有处理一些exception，例如当栈为空时的top()和pop()操作。  
维护两个栈。一个为普通的栈，另一个为最小值栈。  
最小值栈的入栈：如果为空，则入栈（初始化）；如果不为空，则比较栈顶值和入栈值的大小，如果入栈值 <= 栈顶值，则入栈。  
最小值栈的出栈：如果普通栈的出栈值 == 最小值栈的栈顶值，则出栈。  


## JZ21
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
### S 用一个栈进行模拟
入栈序列正常入栈。入栈后，如果查到目前的栈顶值 == 出栈序列目前的值，则循环出栈到不能出栈为止。  
最终，如果栈为空，则模拟成功；反之，反之。


## JZ22
从上往下打印出二叉树的每个节点，同层节点从左至右打印。  
### S 二叉树的层序遍历（重点）
重点同JZ17。  
Reference: [二叉树——前序遍历、中序遍历、后序遍历、层序遍历详解(递归非递归) - bigsai - 博客园](https://www.cnblogs.com/bigsai/p/11393609.html)  


## JZ23
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
### S 二叉搜索树的后序序列的性质（重点）
观察二叉搜索树，分别用前序、中序、后序输出之，我们发现：  
1. 前序：对于每一磕（子）树，其根节点总是对应此（子）树前序序列的第一个数。
2. 中序：会从小到大地输出该数。
3. 后序：对于每一颗（子）树，其根节点总是对应此（子）树后序序列的最后一个数。

Reference: [JZ23 - Jalr4ever的解决方案](https://www.nowcoder.com/questionTerminal/a861533d45854474ac791d90e447bafd?answerType=1&f=discussion)


## JZ24
输入一颗二叉树的根节点和一个整数，按字典序打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
### S1: 递归（深搜）
深搜树。如果当前节点为叶子节点，并且路径之和符合要求，则加入到结果路径中。
### S2: 循环（重点）
维护两个栈：节点栈、当前路径栈。每次同时操作两个栈，合规检查相同。


## JZ25
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针random指向一个随机节点），请对此链表进行深拷贝，并返回拷贝后的头结点。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
### S1: 笨方法
首先复制链表骨架，再依次确定random。复杂度O(n^2)。
### S2: 利用unordered_map进行映射（重点）
利用unordered_map，建立新旧节点的映射。  
遍历原链表，对next和random进行查表，找出新链表中对应的next和random节点，并建立新连接。
### S3: 原地复制分离法
复制：在原链表中，每个节点的后边复制一个相同的节点。同样地，复制出相同的random连接。  
分离：
1. 定好新的head。
2. 设原链表ptr，则新链表newNode = ptr->next。
3. 令ptr->next = ptr->next->next，还原原链表next连接。
4. 令newNode->next = (newNode->next != nullptr) ? newNode->next->next : nullptr，建立新链表next连接。


## JZ26
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
### S1: 中序遍历（二叉树遍历，重点）
[ShYy_Jianzhi: JZ17. BinaryTreeTraversal.cpp](https://github.com/ShinoharaYuuyoru/ShYy_Jianzhi/blob/master/JZ17/BinaryTreeTraversal.cpp)  
### S2: 优化：线索二叉树
用全局变量保存前一个节点，然后在遍历过程中创建双向链表关系。二叉树会被破坏。  
如果采用正常的中序遍历，最终会得到一个倒序的双向链表。那么不妨我们反向思考：以右-中-左来遍历，则会得到一个顺序的双向链表。


## JZ27
输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则按字典序打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
### S1: 递归（重点）
具体看代码。
### S2: C++: next_permutation()
可以直接使用C++自带的排列库。  
[std::next_permutation - cppreference.com](https://en.cppreference.com/w/cpp/algorithm/next_permutation)


## JZ28
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
### S1: 哈希找众数（重点）
一边扫描哈希，再扫描哈希表找出众数。
### S2: 排序后找众数。略。
### S3: 抵消法找多于1/2的数（不是众数）（重点）
设置preVal = numbers[0] 以及 cnt = 1。从第二个数开始遍历。  
遇到与preVal相同的，cnt++；  
遇到不同的，cnt--。当cnt == 0时，重置为numbers[i] 和 cnt = 1。  
最终，preVal一定有值。从头再遍历数组，与preVal比较并计数。


## JZ29
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4。
### S1: C++: priority_queue()（重点）
[std::priority_queue - cppreference.com](https://en.cppreference.com/w/cpp/container/priority_queue)  
注意greater<int>和less<int>所形成的堆，以及相应的top()和pop()的被操作元素。  
greater<int>下，top()为堆中最小元素；反之，反之。
### S2: 维护一个大小为k的数组，每次替换其中的最大的数。
### S3: 手写堆。略。


## JZ30
HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。今天测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)
### S1: 动态规划（重点）
状态转移方程：dp[i] = max(array[i], dp[i - 1] + array[i]);
### S2: 优化S1，只保留一个dp值。
### S3: 非DP，尝试当前值对最大和的影响。
维护并初始化temp = 0，max = array[0]。  
如果temp+array[i] < 0，说明array[i]不做贡献。使temp = 0。否则temp += array[i]。并且更新max值。  
最后if(temp == 0)，则数组内全是负数，遍历选取最大负数；否则直接return。  
新STL用法：max_element(array.begin(), array.end())。  
Reference: [std::max_element - cppreference.com](https://en.cppreference.com/w/cpp/algorithm/max_element)


## JZ31
求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。
### S1: 暴力遍历。TLE。略。
### S2: 递归（重点）
Reference: [1～n 整数中 1 出现的次数 - 递归](https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/solution/javadi-gui-by-xujunyi/)
将数n拆分为两部分：最高位数字high，其他位数字last。设pow = 10^high。
1. if(high == 1)
    1. 1 ~ (pow - 1)范围内1的个数是：f(pow - 1)
    2. 其他部分（考虑pow ~ n）
        1. high位1的个数为：(last + 1)
        2. 其他位1的个数：f(last)
    3. 因此，递推式为：f(n) = f(pow - 1) + (last + 1) + f(last)
2. else
将数按high的大小分为(high + 1)部分：1 ~ (pow - 1)，pow ~ (2 \* pow - 1)， ...，(high \* pow) ~ n（即last）
    1. 1 ~ (pow - 1)：f(pow - 1)
    2. pow ~ (2 \* pow - 1)：
        1. 与上边类似，(last + 1) = (pow - 1) + 1 = pow
        2. 其他位：f(last) = f(pow - 1)
    3. 2 \* pow ~ ...：因为high位不为1，所以均为f(pow - 1)
    4. (high \* pow) ~ n，即last：f(last)
    5. 因此，递推式为：f(n) = f(pow - 1) + pow + f(pow - 1) + (high - 2) \* (pow - 1) + f(last)。
即为：high \* f(pow - 1) + pow + f(last)。  

以上，写出代码即可。

### S3: 找规律，O(logn)
请直接查看以下Reference。  
Reference: [1～n 整数中 1 出现的次数 - 找规律](https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/solution/mian-shi-ti-43-1n-zheng-shu-zhong-1-chu-xian-de-2/)  


## JZ32
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
### S1: 暴力。全排列。回顾JZ27。
### S2: 贪心。自定义排序（重点）。
先将所有数转化为string。  
（重点）复习：[std::to_string](https://en.cppreference.com/w/cpp/string/basic_string/to_string)，[std::stoi](https://en.cppreference.com/w/cpp/string/basic_string/stol)。  
对于两个字符串a和b，如果a + b < b + a，则应当将a排在前边。  
那么这将是我们对字符串的排序方法。  
运用sort()，重写排序方法。有以下方法重写：（重点）
1. 仿函数
```
struct Com {
    bool operator() (string a, string b) {
     return a + b < b + a;
    }
};
sort(str.begin(), str.end(), Com());    // Com()为临时对象
```
2. lambda表达式
```
// 1. 匿名lambda表达式
sort(str.begin(), str.end(), [](string a, string b) {
     return a + b < b + a;
});
// 2. 非匿名lambda表达式
auto lam = [](string a, string b) {
     return a + b < b + a;
 };
sort(str.begin(), str.end(), lam);
```
3. 函数指针
```
bool static comp(const string a, const string b) {
    return a + b < b + a;
}
// 加static的原因：类成员函数有隐藏的this指针,static 可以去this指针
sort(str.begin(), str.end(), comp);
```


## JZ33
把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含质因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
### S: 穷举
每一个丑数，可以分解为2^x\*3^y\*5\*z。  
所以，从第0个丑数（1）开始，分别不断地乘2或3或5，得到最小的数放入当前位置中，并且分别记录2、3、5对应的乘数位置（并做相应的累加）。  
核心代码如下：  
```
for (int i = 1; i < index; i++) {
    result[i] = min(result[p2] * 2, min(result[p3] * 3, result[p5] * 5));
    if (result[i] == result[p2] * 2) {
        p2++;
    }
    if (result[i] == result[p3] * 3) {
        p3++;
    }
    if (result[i] == result[p5] * 5) {
        p5++;
    }
}
```


## JZ34
在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.（从0开始计数）
### S1: 一遍搜索填表  
略
### S2: 优化表格为bitset（重点），但会增加时间复杂度到2n
[std::bitset](https://en.cppreference.com/w/cpp/utility/bitset)


## JZ35
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007
### S1: 暴力，TLE（包括查询冒泡的交换次数）
### S2: 二路归并排序（重点）
1. 首先，我们要搞懂（2路）归并排序。  
与快速排序相似，归并排序也是一种分治，代码上也以分治函数为框架，内部使用归并函数进行排序归并。  
```
void mergeSort(vector<int>& array, int left, int right);
void merge(vector<int>& array, int left, int mid, int right);
```
2. 其次，这道题为什么要用归并排序。  
如S1提示，其实“逆序”就是把排序过程中，把大的数往后移动（交换）的次数。  
那么在归并过程中，首先复杂度从冒泡排序的n2下降到nlogn；其次我们可以不用一个一个地去数了（即ANS++）：对于二路归并时候的两个block，设左边block当前的数已经大于右边block当前的数，又因为两个block已经是排好序的，可以得知左边block当前数到最后一个数均大于右边block当前的数，那么对于右边block当前的数，可以产生[leftEndIdx - leftNowIdx + 1]个的逆序（也就是在冒泡排序过程中发生了这么多次的交换）。这也加速了计数过程。  
```
while(b1Idx <= mid && b2Idx <= right){
    // Here we will operate the counter.
    if(array[b1Idx] > array[b2Idx]){
        ANS += mid - b1Idx + 1;
        ANS = ANS % 1000000007;
        
        temp[tempIdx] = array[b2Idx];
        tempIdx++;
        b2Idx++;
    }
    else{
        temp[tempIdx] = array[b1Idx];
        tempIdx++;
        b1Idx++;
    }
    
    // Original merge sort code.
    //temp[tempIdx] = array[b1Idx] <= array[b2Idx] ? array[b1Idx] : array[b2Idx];
    //tempIdx++;
    //b1Idx++;
    //b2Idx++;
}
```


# JZ36
输入两个链表，找出它们的第一个公共结点。（注意因为传入数据是链表，所以错误测试数据的提示是用其他方式显示的，保证传入数据是正确的）
## S1: Hash
略
## S2: 同等长度搜索
在p1到nullptr时置为pHead2，在p2到nullptr时置为pHead1——使两个搜索长度等长。那么两指针一定会在第一个重叠节点相遇。


# JZ37
统计一个数字在升序数组中出现的次数。
### S: 二分查找（重点）
[详解二分查找算法 - murphy_gb - 博客园](https://www.cnblogs.com/kyoner/p/11080078.html)  
在此写下三种类型的核心代码
二分查找框架：
```
int binarySearch(int[] nums, int target) {
    int left = 0, right = ...;

    while (...) {
        int mid = (right + left) / 2;
        if (nums[mid] == target) {
            ...
        }
        else if (nums[mid] < target) {
            left = ...
        }
        else if (nums[mid] > target) {
            right = ...
        }
    }
    return ...;
}
```
关键概念：**搜索区间**的控制
1. 寻找特定的数
```
right = length - 1;
while(left <= right);
return mid;
left = mid + 1;
right = mid - 1;
```
2. 寻找左边界
```
right = length;
while(left < right);
right = mid;        // [mid] == target
left = mid + 1;
right = mid;
return array[left] == target? left : -1;
```
3. 寻找右边界
```
right = length;
while(left < right);
left = mid + 1;     // [mid] == target
left = mid + 1;
right = mid;
return left - 1;
if(left == 0){
    return -1;
}
else{
    return array[left - 1] == target? (left - 1) : -1;
}
```


# JZ38
输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
## S1: 层序遍历（重点）
[ShYy_Jianzhi: JZ17. BinaryTreeTraversal.cpp](https://github.com/ShinoharaYuuyoru/ShYy_Jianzhi/blob/master/JZ17/BinaryTreeTraversal.cpp)  
[二叉树——前序遍历、中序遍历、后序遍历、层序遍历详解(递归非递归) - bigsai - 博客园](https://www.cnblogs.com/bigsai/p/11393609.html)  
## S2: 分治（重点）
递归处理左子树和右子树，以当前节点为根节点的二叉树的深度为：max(leftVal, rightVal) + 1。有点像动态规划...


# JZ39
输入一棵二叉树，判断该二叉树是否是平衡二叉树。  
在这里，我们只需要考虑其平衡性，不需要考虑其是不是排序二叉树
## S: 分治
平衡二叉树（AVL）的概念：它是一棵空树或它的左右两个子树的高度差的绝对值不超过1，并且左右两个子树都是一棵平衡二叉树。  
从JZ38的树的深度引申，易得是否为平衡二叉树。


# JZ40
一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
## S1: Hash
略
## S2: 位运算（重点）
基础是异或运算。这个很容易。那么问题就成了如何找到这两个只出现一次的数。  
我们知道，异或运算后得到的结果中的“1”，一定是一个0和一个1的异或结果，而这个不相同的位肯定出自两个各出现一次的数。  
又因为，a & (-a) -> 得到第一个不相同的“1”位。（此处复习[原码，补码和反码 - wqbin - 博客园](https://www.cnblogs.com/wqbin/p/11142873.html)）而这一位，对数组使用与运算，可以将整个数组分成两部分。  
再次，对这两部分均使用异或运算，并且因为出现两次的数因为异或又抵消，那么最终分开的两部分就各只剩下一个数，便是各出现一次的数。
```
int res = 0;
for(int num : data){
    res ^= num;
}

*num1 = 0;
*num2 = 0;

res = res & (-res);
for(int num : data){
    if(num & res){
        *num1 ^= num;
    }
    else{
        *num2 ^= num;
    }
}
```