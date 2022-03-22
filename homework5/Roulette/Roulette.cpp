#include <iostream>
#include <vector>
#include <cstdlib> // для функций rand() и srand()
#include <ctime> // для функции time()
#include <random>
#include <cmath>
using namespace std;

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	// Равномерно распределяем рандомное число в нашем диапазоне
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

double getRandomFloatingPointBetween_progressive(int min, int max) {
	std::random_device rd; // uniformly-distributed integer random number generator
	std::mt19937 gen(rd()); //инициализируем Вихрь Мерсенна случайным стартовым числом
	std::uniform_real_distribution<> dis(min, max);//uniform distribution between min and max
	return dis(gen);
}

int main()

{
	
	vector<double> distribution(10);

	for (double& e : distribution)
		e = getRandomFloatingPointBetween_progressive(-2, 2);

	for (double& e : distribution)
		cout << e << " ";
	cout << endl;

	std::sort(distribution.begin(), distribution.end(), [](double left, double right) {return abs(left) < abs(right); });

	for (double& e : distribution)
		cout << e << " ";

	//vector<string> words = { "Monkey", "Banana", "Cherry", "7" };
	//vector<int> res(3);
	//int a;//= getRandomNumber(0, 3);
	//for (int i = 0; i < 3; ++i) {
	//	a = getRandomNumber(0, 3);
	//	res[i] = a;
	//}

	//for (const int& e : res)
	//	cout << words[e]<<endl;

	//if (words[res[0]] == words[res[1]] && words[res[0]] == words[res[2]])
	//	cout << "You won!" << endl;
	//else
	//	cout << "You lost!" << endl;

}
