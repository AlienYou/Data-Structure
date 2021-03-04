// ListOfAvailableSpace.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "LinkList.h"
#include "ArrayList.h"

void testLinList() {
    List<int>* listTest = new LinkList<int>();
    listTest->append(0);
    listTest->insert(2);
    listTest->next();
    listTest->print();

    int value;
    listTest->getValue(value);
    cout << "get value: " << value << endl;
    int removeValue = 0;
    listTest->remove(removeValue);
    cout << "remove value: " << removeValue << endl;
    listTest->print();
}

void testArrayList() {
    ArrayList<int> array(10);
    array.append(1);
    array.insert(2);
    array.insert(3);
    array.next();
    array.print();

    int removeValue;
    array.remove(removeValue);
    cout << "remove value: " << removeValue << endl;
    array.print();
    array.prev();
    array.setStart();
    array.print();
}

int main()
{
    testArrayList();
}
