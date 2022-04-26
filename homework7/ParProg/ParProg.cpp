#include <iostream>
#include <cstdlib> // для функций rand() и srand()
#include <ctime> // для функции time()
#include <thread>
#include <chrono>

using namespace std;
using namespace std::chrono;

template<typename T>
T getRandomFloatingPointBetween(int min, int max) {
	return static_cast <T>(min) + static_cast <T>(rand()) / static_cast <T>(RAND_MAX) * static_cast<T>(max - min + 1);
}

bool in_circle(double x, double y, double R2) {
	
	return x * x + y * y <= R2;
}

void without_parallel(int R)
{
	const double NMAX = 100000000.0;
	double x, y, pi;
	double R2 = static_cast<double>(R) * static_cast<double>(R);
	double N = 0.0;
	double Ncirc = 0.0;

	srand(static_cast<unsigned int>(time(0)));

	while (N < NMAX)
	{
		x = getRandomFloatingPointBetween<double>(0, R);
		y = getRandomFloatingPointBetween<double>(0, R);

		if (in_circle(x, y, R2))
			Ncirc++;
		N++;
	}
	pi = 4 * Ncirc / NMAX;
	std::cout <<"R = "<<R << " pi = " << pi << "\n";
}

int main() {
	std::cout << "WITHOUT PARPROG\n";
	auto start = steady_clock::now();
	without_parallel(102400);
	without_parallel(10240);
	without_parallel(1024);
	auto finish = steady_clock::now();
	cout <<"Working time " << duration_cast<milliseconds>(finish - start).count() << " ms" << endl;

	std::cout << "WITH PARPROG\n";
	
	std::thread t1(without_parallel, 102400);
	std::thread t2(without_parallel, 10240);
	std::thread t3(without_parallel, 1024);
	start = steady_clock::now();
	t1.join();
	t2.join();
	t3.join();
	finish = steady_clock::now();
	cout << "Working time " << duration_cast<milliseconds>(finish - start).count() << " ms" << endl;
	return 0;
}