// Task2.cpp: определяет точку входа для приложения.
//
#include <iostream>
#include <chrono>
#include <algorithm>

#include <vector>
#include <array>
#include <list>
#include <deque>
#include <forward_list>

using namespace std;

const int N = 500000;

template<typename T>
void sorting(T& container)
{
	auto start = chrono::high_resolution_clock::now();
	//container.sort();
	sort(container.begin(), container.end()); //не работает для list
	auto end = chrono::high_resolution_clock::now();
	
	chrono::duration<double> diff = end - start;
	cout << endl << diff.count() << endl;
}
int main()
{
	//vector
	vector<int> vec;
	vec.resize(N);
	

	//array
	array<int, N> arr;
	//list
	list<int> ls;
	//deque
	deque<int> dq;
	//flist
	forward_list<int> fls;

	for (auto& e : arr)
		e = rand() % 100;

	int i = 0;
	auto itr = vec.rbegin();
	for (auto it = vec.begin(); it != vec.end(); it++)
	{
		arr.at(i) = *it;
		i++;
		ls.push_back(*it);
		dq.push_back(*it);
		fls.push_front(*itr);
		itr++;
	}

	

	cout << "VECTOR " << "ARRAY: " << "LIST: " << "DEQUE: " << "FLIST: "<<endl;
					//     N = 250 000				| N = 500 000
					//sort(cont)|Container.sort()	|sort(cont) |Container.sort()	
	sorting(vec);	//0.0400758 |					|0.085611  |					
	sorting(arr);	//0.0382219 |					|		   |					
	sorting(ls);	//-----		|0.187707			|		   |0.489279
	sorting(dq);	//0.222454  |					|0.549155  |					
	sorting(fls);	//-----		|0.131921			|		   |0.271607

	//Вывод на экран:
	// 
	//auto it_arr = arr.begin();
	//auto it_ls = ls.begin();
	//auto it_dq = dq.begin();
	//auto it_fls = fls.begin();

	/*for (auto it = vec.begin(); it != vec.end(); it++)
	{
		cout <<  *it << "\t" << *it_arr << "\t" << *it_ls << "\t" << *it_dq << "\t" << *it_fls << endl;
		it_arr++;
		it_ls++;
		it_dq++;
		it_fls++;
	}*/


	return 0;
}
