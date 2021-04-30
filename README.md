单链表里length作用不大，可以不添加length成员


冒泡排序法：
时间复杂度：最差:O(n2), 平均O(n2),  最优O(n)
适用：元素个数小的情况

插入排序：
将第一个数作为有限数列，后面的数作为无序数列。
从头到尾遍历无序数列，将无序数key插入到有序数列中。
从后往前遍历有序数列，将大于key的数往后移，最后将key插入到空位。

带环单链表：单链表尾结点连接到自身某结点
入口点：一个指针从头结点出发，一个指针从相遇点出发，相同速度，当两指针相遇时，该相遇点就是环的入口点

求入口点算法：
我们假定链表头到环入口的距离是len，环入口到slow和fast交汇点的距离为x，环的长度为R。
slow和fast第一次交汇时，设slow走的长度为：d = len + x，而fast走的长度为：2d = len + nR + x，(n >= 1)
从而我们可以得知：2len + 2x = len + nR + x，
即len = nR - x，(n >= 1)，于是我们可以得到这样的算法：

len = nR - x = (n-1)R + (R - x) 	//fast指针从头结点出发，slow指针从相遇点出发，经过n-1圈的时候，两指针相遇，相遇点即入口点


判断两无环单链表是否相交：看两链表的尾结点是否相同

求两无环链表（l,r）的相交点：
让尾结点指向l的第一个结点，形成环，这样问题就变成求带环单链表的环入口点了

判断两有环单链表l，r是否相交：
两有环单链表相交，则它们共环
转化为：判断环l上一点（相遇点）是否在环r上


栈：
四则运算表达式求值 方法：（后缀表达式）（逆波兰）
1）将中缀表达式（正常数学符号）转为后缀表达式（没有括号，用于计算机运算）：
从左到右遍历，数字直接输出，遇到符号优先级低于栈顶符号符号或者右括号，则出栈并输出，并将当前符号压栈，直到输出完
2）将后缀表达式进行运算，得出结果

队列：
判断队列满的条件：
(rear+1)%queue_size == front
队列长度：
(rear-front+queue_size)%queue

rear向后移，使用%符号，就不用if-else分情况
	//if ((queue_size - 1) == rear) {
	//	rear = 0;
	//}
	//else {
	//	++rear;
	//}
	直接用%，当rear=queue_size-1时，rear重新赋值为0：
	rear = (rear + 1) % queue_size;
	
普通的sequence_queue的缺点：出队的时候，所有元素向前移，时间复杂度O(n)
而circular_sequence_queue没有这个缺点，因为出队只有rear指针移动，没有元素移动，时间复杂度O(n)
circular_sequence_queue的缺点和sequence_stack一样，可能会溢出
所以还需要link_queue


两个栈实现一个队列，两个队列实现一个栈；
思想：一个栈（队列）用来入队（入栈），一个栈用来出队（出栈）
两个栈实现一个队列：
队首元素在出栈，先考虑出栈不空的情况
两个队列实现一个栈：
栈顶元素在入队，先考虑入队不空的情况


二叉树或链表的创建/销毁：
在C++中，如果用非成员函数实现，则要传递二级指针（或一级指针的引用）
				   如果用成员函数实现，则直接使用一级指针（私有成员）或头结点的引用
				   

树：
高度：从ni（某节点）到叶子结点 （叶子结点高度都是0）
深度：从根节点到ni	（根结点深度是0）
层数：根节点为第0层

平衡二叉树：
左右两颗子数高度差的绝对值<=1
