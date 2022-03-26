// CMakeProject1.cpp: определяет точку входа для приложения.
//

#include "CMakeProject1.h"

using namespace std;
using namespace std::chrono;

int main()
{
	set<int> st;
	vector<int> vec;
	duration<double> diff;
	cout << "First column is an insertance in ms, second sorting in ms\n";

	for (int n = 10; n <= 100000; n *= 5) {
		vec.resize(n);

		auto start = high_resolution_clock::now();
		for (int i = 0; i < n; i++) {
			st.insert(i);
		}
		auto end = high_resolution_clock::now();
		diff = end - start;
		cout<< diff.count() <<" ";

		for (int i = 0; i < n; i++) {
			vec.push_back(n - i);
		}

		auto start1 = high_resolution_clock::now();
		sort(vec.begin(), vec.end());
		auto end1 = high_resolution_clock::now();
		diff = end1 - start1;
		cout << diff.count() << "\n";

		// Сортировка происходит быстрее, график прикрепил, логарфимический масштаб и аппркосимацию не делал,
		// потому что по графику все ясно

	}
	return 0;
}
