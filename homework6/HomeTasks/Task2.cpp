#include "HomeTasks.h"
using namespace std;

int main()
{
    string infilename = "D:\\Repositories\\2022_C++_Programming\\homework6\\HomeTasks\\StrokaN.txt";

    ifstream infile;
    infile.open(infilename);
    string str;
    int i = 1;
    int N;
    cin >> N;
    while (getline(infile, str)) {
        if (N == i)
            cout << str;
        i++;
    }
    infile.close();
    return 0;
}