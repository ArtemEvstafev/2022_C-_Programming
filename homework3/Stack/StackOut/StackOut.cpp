// StackOut.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stack>
using namespace std;

void printStack(stack<int>& s2)
{

    stack<int> s1(s2);
    for (; !s1.empty(); s1.pop())
        std::cout << s1.top() << ' ';
    cout << endl;
}
int main()
{
    stack<int> s;
    for (int i = 0; i < 10; i++)
    {
        s.push(i);
    }   
    cout << "First print: "; printStack(s);
    cout << "Second print: "; printStack(s);
    return 0;

}

