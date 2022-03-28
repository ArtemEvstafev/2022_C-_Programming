#include "CMakeProject1.h"

using namespace std;

ostream& operator<< (std::ostream& stream, const vector<int>& vec)
{
	for (const auto& e : vec)
		cout << e << " ";
	return stream;
}


int main()
{
	vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	/*vector<int> v(10);
	istream_iterator<int> intvecRead(cin);
	copy(intvecRead, istream_iterator<int>(), v.begin());
	cin.clear();*/
	cout << "v " << v << endl;

	//inserter(v, v.end()) =  20;
	//back_insert_iterator<vector<int>> it = back_inserter(v);it = 20;
	//back_inserter(v) = 20;
	int Arr1[] = { 3, 2, 11 };
	copy(Arr1, Arr1 + 3, back_inserter(v));
	cout << "Added elems " << v << endl;

	srand(1337);
	for (int i = 0; i < 10; i++)
		swap(v[rand() % v.size()], v[rand() % v.size()]);
	cout <<"Shaked " << v << endl;

	int n = 0;
	int val;
	for (auto it = v.begin(); it != v.end(); it++) {

		val = *it;
		n = count(v.begin(), v.end(), val);
		if (n > 1) {
			v.erase(remove(v.begin(), v.end(), val), v.end());
		} 
	}
	cout << "Deleted repeating numbers " << v << endl;

	n = count_if(v.begin(), v.end(), [](int x) {return x % 2 == 1;});
	cout << "Odd numbers " << n << endl;

	vector<int>::iterator it = min_element(v.begin(), v.end());
	cout << "Min " << *it;
	it = max_element(v.begin(), v.end());
	cout << " Max " << *it << endl;

	it = find_if(v.begin(), v.end(), [](int x) {
		for (int i = 2; i <= x / 2; i++)
			if ((x % i) == 0)
				return 0;
		return 1; });
	if(it != v.end())
		cout << "Simple " << *it << endl;
	else
		cout << "No Simple" << endl;

	for (auto& it : v)
		it *= it;
	cout << "Square " << v << endl;

	vector<int> v1(v.size());
	for (int i = 0; i < v1.size(); ++i)
		v1[i] = rand();
	cout << "v1 " << v1 << endl;

	cout<< accumulate(v1.begin(), v1.end(), 0)<< endl;

	v1.at(0) = 1;
	v1.at(1) = 1;
	v1.at(2) = 1;
	cout << "Replaced with '1' " << v1 << endl;

	vector<int> v2(v1.size());
	for (int i = 0; i < v1.size(); ++i)
		v2[i] = v[i] - v1[i];
	cout << "v2 " << v2 << endl;

	replace_if(v2.begin(), v2.end(), [](int x) {return x < 0; }, 0);
	cout << "Changed to '0' " << v2 << endl;

	v2.erase(remove_if(v2.begin(), v2.end(), [](int x) {return x == 0;}), v2.end());
	cout << "Deleted '0' " << v2 << endl;

	reverse(v2.begin(), v2.end());
	cout << "Reversed " << v2 << endl;

	vector<int> v2_copy = v2;
	sort(v2_copy.rbegin(), v2_copy.rend());
	cout << v2_copy.at(0) << " " << v2_copy.at(1) << " " << v2_copy.at(2)<<endl;

	sort(v.begin(), v.end());
	sort(v1.begin(), v1.end());
	cout << "Sorted v " << v << endl;
	cout << "Sorted v1 " << v1 << endl;

	vector<int> v3;
	merge(v.begin(), v.end(), v1.begin(), v1.end(), back_inserter(v3));
	cout << "v3 " << v3 << endl;

	return 0; 
}