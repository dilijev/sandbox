#include <iostream>

using namespace std;

/**
 * Adapted from:
 * http://eli.thegreenplace.net/2003/07/23/correct-usage-of-const-with-pointers/
 */
void test1() {
    int i1 = 111;
    int i2 = 222;
    int i3 = 333;
    int i4 = 444;
    int temp = 42;

    // Neither the data nor the pointer are const
    int* a = &i1;

    // Constant data, non-constant pointer
    const int* b = &i2;

    // Constant pointer, non-constant data
    int* const c = &i3;

    // Constant pointer, constant data
    const int* const d = &i4;

    cout << *a << endl; // prints "111"
    (*a)++;
    cout << *a << endl; // prints "112" (data was changed)
    a = &temp;
    cout << *a << endl; // prints "42" (value of temp)
    cout << endl;

    cout << *b << endl; // prints "222"
    // (*b)++; // can't change data
    // cout << *b << endl;
    b = &temp; // CAN point to a new int
    cout << *b << endl; // prints "42"
    cout << endl;

    cout << *c << endl; // prints "333"
    (*c)++;
    cout << *c << endl; // prints "334"
    // c = "CCC hello"; // cannot assign to an immutable pointer (* const)
    // cout << *c << endl;
    cout << endl;

    cout << *d << endl; // prints "444"
    // (*d)++; // can't change data
    // d = &temp; // can't assign to immutable pointer (* const)
    cout << endl;
}

int main(int argc, char **argv) {
    test1();
}
