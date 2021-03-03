// ListOfAvailableSpace.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "LinkList.h"

void testLinList() {
    List<int>* listTest = new LinkList<int>();
    listTest->append(0);
    listTest->insert(2);
    listTest->print();
}

int main()
{
    testLinList();
}
