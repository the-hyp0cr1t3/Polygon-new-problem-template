#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n = rnd.next(1, 100000);
    cout << n << " ";
    int d = rnd.next(0, 1000000000);
    cout << d << endl;
    for(int i = 0; i < 2*n+1; i++) {
        cout << (i == n? 0 : rnd.next(1, 1000000000));
        if (i < 2*n) cout << " ";
    }
    cout << endl;
    return 0;
}