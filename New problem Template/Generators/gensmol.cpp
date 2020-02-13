#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n = rnd.next(1, 100);
    cout << n << " ";
    int d = rnd.next(0, 100);
    cout << d << endl;
    for(int i = 0; i < 2*n+1; i++) {
        cout << (i == n? 0 : rnd.next(1, 100));
        if (i < 2*n) cout << " ";
    }
    cout << endl;
    return 0;
}

/*
gen2 100 > $
gen2 6 > $
gen2 34 > $
genbig 1 > $
genbig 69 > $
genbig 420 > $
gensmol 44 > $
gensmol 36 > $
gensmol 72 > $
*/