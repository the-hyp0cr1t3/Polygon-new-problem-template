#include "testlib.h"

using namespace std;

int main(int argc, char* argv[])
{
    registerValidation(argc, argv);
    
    int n = inf.readInt(1, 100000, "n");
    inf.readSpace();
    inf.readEoln();
    for (int i = 0; i < 2*n+1; i++) {
        inf.readInt(1, 1000000000, "p");
        if(i < 2*n) inf.readSpace();
    }
    inf.readEoln();
    inf.readEof();
    return 0;
}