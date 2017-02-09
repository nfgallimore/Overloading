#include <iostream>

using namespace std;
#include "MyDouble.h"
int main()
{
    MyDouble a;
    cout << "Initialized a = " << a << endl;
    a.setValue(5.5);
    cout << "Value after set to 5.5 is " << a <<endl;
    MyDouble b;
    b.setValue(4.4);
    MyDouble c;
    c = a + b;
    cout << "a + b = " << c <<endl;
    c = a + 1.1;
    cout << "a + 1 = " << c <<endl;

    c = 2.2 + a;
    cout << "2.2 + a = "<< c <<endl;

    c += 2.2;
    cout << "c += 2.2 = "<< c <<endl;

    c += MyDouble(1.1);
    cout << "c += MyDouble(1.1) = " << c << endl;

    cout << "Is c = 11? " << boolalpha << (c == 11) << endl;
    cout << "Is c = a? " << boolalpha << (c == a) << endl;
    cout << "Is 11.1 = c? " << boolalpha << (11.1 == c) << endl;

    cout << "++c = " << ++c << "  " << c << endl;

    IntList l(5);
    for(int i = 0; i < l.size(); ++i) {
        cout << l[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < l.size(); ++i) {
        l[i] = i;
    }
    for(int i = 0; i < l.size(); ++i) {
        cout << l[i] << " ";
    }
    cout << endl;
    {
        IntList p = l;
    }
    IntList ls(6);
    for (int i = 0; i < 6; i++) {
        ls[i] = 2 * i;
    }
    cout << "ls = " << ls << endl;
    ls = l;
    cout << "l = " << l << endl;
    cout << "ls = " << ls << endl;
    IntList p = l;
    cout << "p = " << p << endl;
    p += 1;
    cout << "p += 1 sets p to " << p << endl;
    p -= 1;
    cout << "p -= 1 sets p to " << p << endl;
    /* TODO */
    p -= l;
    cout << "p -= l sets p to " << p << endl;

    // p = p - l;
    // cout << "p = p - l" << p << endl;
    // p -= l;
    // cout << "p -= l" << p << endl;
    return 0;
}
