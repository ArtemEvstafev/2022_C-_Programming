#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
    vector<int> v;
    int n;
    cin >> n;
    v.resize(10);
    cout << "size: " << v.size() << ", " << "capacity: " << v.capacity() << endl;
    for (int i = 0; i < n; i++)
    {
        v.push_back(i);
        cout << "size: " << v.size() << ", " << "capacity: " << v.capacity() << endl;
    }
    /*for (int i = 0; i < 13; ++i)
        cout << i+1 << " ";
    for (int i = 0; i < 13; ++i)
        cout << pow(2, i+1) << " ";
    */
    return 0;
}
/*
    1) Без задания начального размера
    capacity = колв-во всех элементов; delta = изменение capacity
    Если компилировать через VisualStudio           Если компилировать через Ubuntu:
    Для  capacity < 4, capacity увеличивается на 1  capacity будет изменяться по степеням двойки 1,2,4,8,16,...2^i
    capacity = 4, delta = 2                         Функция по которой меняется capacity имеет вид y = 2^x
    capacity = 6, delta = 3
    capacity = 9, delta = 4
    capacity = 13, delta = 6
    capacity = 19, delta = 9
    capacity = 28, delta = 14                       Вывод: VisualStudio экономит память тем, что выделяет память для вектора
    capacity = 42, delta = 21                       по экспоненте, а не по показательной функции 
    capacity = 63, delta = 31
    capacity = 94, delta = 47
    capacity = 141, delta = 70
    capacity = 211, delta = 105
    capacity = 316, delta = 158
    capacity = 474, delta = 237
    Функция по которой меняется capacity имеет вид y = exp(1+0.4x)
    2) С заданием начального размера
    Начальный размер вектора = 10
    Если компилировать через VisualStudio       Если компилировать через Ubuntu:
    capacity = 10                               capacity будет изменяться по степеням двойки 1,2,4,8,16,...2^i * size_0
    capacity = 15                               В нашем случае 10, 20, 40, 80, 160, 320, 640
    capacity = 22                               Функция по которой меняется capacity имеет вид y = 2^x*size, где size это начальный размер вектора
    capacity = 33
    capacity = 49
    capacity = 73
    capacity = 109                              Вывод: оказалось, что vector с заданым размером расширяется в 2 раза
    capacity = 163
    capacity = 244
    capacity = 366
    capacity = 549(конечный size = 510)
    Функция по которой меняется capacity имеет вид y = exp(1.9+0.4x)
*/

//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода,
//   или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.

