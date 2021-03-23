# Data-Structure

* ### 线性表

  > - [x] #### 顺序表
  >
  > - [x] #### 链表
  >
  >   > - [x] #### 可利用空间表
  >   >
  >   > - [x] #### 基于可利用空间表的双向链表
  >   >
  >   > - [ ] #### 通过异或实现节点遍历
  >
  > - [ ] #### 规范化测试

* ### 字典

  > - [x] #### 基于顺序表的无序字典
  >
  > - [x] #### 基于顺序表的有序字典
  >
  > - [x] #### 基于链表的字典
  >
  > - [ ] #### 测试

* ### 栈

  > - [x] #### 顺序栈
  >
  > - [x] #### 链表栈
  >
  > - [ ] #### 测试

- ### 队列

  > - [x] #### 顺序队列
  >
  >   > - 判断是满队还是空队，采用存储n个元素，开辟n + 1个空间，通过(rear + 2) % maxSize == front来判断队满，初始时rear = 0, front = 1.
  >
  > - [x] #### 链式队列
  >
  > - [ ] #### 可变长顺序队列
  >
  > - [x] #### 测试
  
- ### 二叉树

  > - [x] #### 叶子节点与内部节点的数据结构定义及实现分离
  >
  >   > - [x] 外部函数访问树
  >   >- [x] 通过继承以方便扩展访问树节点方式(针对不同的节点子类，尤其是节点子类数目较多时，其优势很明显) 
  >   
  > - [x] #### 二叉搜索树
  >
  >   > - [x] #### 测试
  >   
  > - [x] #### 堆
  >
  >   > - [x] #### 测试
  >   
  > - [x] #### Huffman编码树
  >
  >   > - [x] #### 测试

- ### 树

  > - [x] #### 动态左子节点/右兄弟节点表示法
  >
  >   > 包含指向子节点、右兄弟、父节点指针
  >
  > - [x] #### 测试
  >
  > - [x] #### 并查集(Union/Find)
  >
  >   > - [x] #### 路径压缩
  >   >
  >   > - [x] #### 测试

- #### 内部排序

  > - [x] #### 插入排序
  >
  >   > - [x] #### 测试
  >
  > - [x] #### 冒泡排序
  >
  >   > - [x] #### 测试
  >
  > - [x] #### 选择排序
  >
  >   > - [x] #### 测试
  >
  > - [x] #### 希尔排序
  >
  >   > - [x] #### 测试
  >   >
  >   >   以增量为3的序列排序效果最好(1, 4, 13, 40, 121 .....)