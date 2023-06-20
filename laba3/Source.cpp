#include <iostream>
using namespace std;

int main()
{
    int first = 0, second = 1, next = 0;
    float a;
    cout << "Enter a number: ";
    cin >> a;

    while (next <= a)
    {
        next = first + second;
        first = second;
        second = next;
    }

    cout << "The first Fibonacci number greater than " << a << " is " << next << endl;
    return 0;
}