#include <testlib.h>
#include <bits/stdc++.h>

using namespace std;

int gen(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    string s = "0123456789";
    int n = rnd.next(1, 10);
    cout << n << " ";
    int length = rnd.next(6, 10);
    shuffle(s.begin(), s.end());
    cout << s.substr(0, length) << endl;
    for(int i = 0; i < n; i++) {
        cout << rnd.next(1, 100000) << " ";
        length = rnd.next(1, 5);
        shuffle(s.begin(), s.end());
        cout << s.substr(0, length) << endl;
    }
    return 0;
}

int main () {
    int argc;
    cin >> argc;
    char args[argc+1][10];
    for(int i = 0; i < argc; i++) {
        string s;
        cin >> s;
        cin >> args[i];
    }
    char** argv = args[0].c_str();
    gen(argc, args);
    return 0;
}