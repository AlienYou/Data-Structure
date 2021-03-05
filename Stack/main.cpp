#include "ArrayStack.h"
#include "LinkStack.h"
#include <iostream>
using std::cout;
using std::endl;

void testArrayStack() {
    Stack<int>* arrSt = new ArrayStack<int>(10);
    int top;
    cout << "top value: " << arrSt->topValue(top) << endl;
    arrSt->push(2);
    arrSt->push(3);
    arrSt->topValue(top);
    cout << "top Value: " << top << endl;
    arrSt->pop(top);
    cout << "pop value: " << top << endl;
    arrSt->topValue(top);
    cout << "top value: " << top << endl;
    
}

void testLinkStack() {
    Stack<int>* linkSt = new LinkStack<int>();
    int top;
    cout << "top value: " << linkSt->topValue(top) << endl;
    linkSt->push(10);
    linkSt->push(2);
    linkSt->topValue(top);
    cout << "top value: " << top << endl;
    linkSt->pop(top);
    cout << "pop value: " << top << endl;
    linkSt->pop(top);
    cout << "pop value: " << top << endl;
    linkSt->clear();
}

int main()
{
    testLinkStack();
}
