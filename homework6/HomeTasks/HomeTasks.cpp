#include "HomeTasks.h"

using namespace std;
string del_com(string a) {
    string res;
    bool del = false;
    static bool was = false;
    static char b = '|';

    for (int i = 0; i < a.size(); i++) {
        if (i + 1 != a.size()) {
            if (a[i] == '/' && a[i + 1] == '/' && a.substr(i+2).find(';') == string::npos) {
                break;
            }
                
        }
        if(i + 3 < a.size()){
            if (a[i] == '/' && a[i + 1] == '*' && a[i + 2] == '*' && a[i + 3] == '/')
                del = true;
        }
        if (i + 1 != a.size()) {
            if (a[i] == '/' && a[i + 1] == '*') {
                del = true;
                if ((a.substr(a.find('*') + 1)).find('*') == std::string::npos) {
                    
                    was = true;
                }
            }
        }
        if (i - 1 > 0) {
            if (a[i - 2] == '*' && a[i - 1] == '/') {
                del = false;
                was = false;
            }
        }
        
        if (b == '/' && a[i] != '*') {
            
            was = false;
        }
        b = a[i];

        if (del)
            continue;
        if (was) {
           
            continue;
        }
        res.push_back(a[i]);
    }
    
    return res;
}
int main()
{
    string infilename = "D:\\Repositories\\2022_C++_Programming\\homework6\\HomeTasks\\start.txt";
    string outfilename = "D:\\Repositories\\2022_C++_Programming\\homework6\\HomeTasks\\finish.txt";
    vector<string> v;
    
    
    ifstream infile;
    infile.open(infilename);
    string str;
    
    while (getline(infile, str)) {
        str = del_com(str);
        if(str.size() != 0)
            v.push_back(str);
        
    }
    infile.close();

    
    ofstream outfile;
    outfile.open(outfilename);
    for (auto it = v.begin(); it != v.end(); it++) {
        outfile << *it<< endl;
    }
    outfile.close();

    return 0;
}
