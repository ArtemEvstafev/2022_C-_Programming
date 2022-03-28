#include "CMakeProject1.h"

using namespace std;


//http://www.boost.org/doc/libs/1_35_0/doc/html/hash/combine.html

template < typename T >
void hash_combine(std::size_t& seed, const T& value) noexcept
{
	seed ^= std::hash < T >()(value) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

template < typename T >
void hash_value(std::size_t& seed, const T& value) noexcept
{
	hash_combine(seed, value);
}

template < typename T, typename ... Types >
void hash_value(std::size_t& seed, const T& value, const Types & ... args) noexcept
{
	hash_combine(seed, value);
	hash_value(seed, args...);
}

template < typename ... Types >
std::size_t hash_value(const Types & ... args) noexcept
{
	std::size_t seed = 0;
	hash_value(seed, args...);
	return seed;
}

struct Value
{
	double a;
	int b;
	char c;
};

struct Some_Hash
{
	std::size_t operator() (const Value& val) const noexcept
	{
		auto hash = hash_value(val.a, val.b, val.c);
		//cout << hash << endl;
		return hash;
	}
};

struct Some_Equal
{
	bool operator() (const Value& lhs, const Value& rhs) const noexcept
	{
		return (lhs.a == rhs.a && lhs.b == rhs.b && lhs.c == rhs.c);
		//return false;
	}
};

int main(int argc, char** argv)
{
	
	for (int n = 1; n < 10000000; n *= 5) {

		std::unordered_set <Value, Some_Hash, Some_Equal> values;

		double a = 0.;
		int b = 0;
		char c = 65;

		for (int i = 0; i < n; ++i) {

			Value val = { a , b, c };

			values.insert(val);

			a += 0.0001;
			b += 1;
			if (c != 122)
				c += 1;
			else
				c = 65;
		}
		//cout << "size: " << values.size() << " ";// endl;

		/*for (const auto& v : values)
		{
			std::cout << v.a << " " << v.b << " " << v.c << " " << std::endl;
		}*/

		size_t collisions = 0, empty = 0;
		for (auto bucket = values.bucket_count(); bucket--;) {
			if (values.bucket_size(bucket) == 0)
				empty++;
			else
				collisions += values.bucket_size(bucket) - 1;
		}
		/*std::cout << "max_load_factor " << values.max_load_factor() << "\nload_factor " << values.load_factor() << "\nbucket_count " <<
			values.bucket_count() << "\ncollisions " << collisions << "\nempty " << empty << '\n';*/
		cout << n << " " << collisions << endl;
	}

		/*
		1 0
		5 2
		25 4
		125 18
		625 163
		3125 966
		15625 5526
		78125 19113
		390625 115307
		1953125 681841
		9765625 2363886
		*/
	return 0;
}