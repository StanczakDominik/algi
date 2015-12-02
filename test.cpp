#include <iostream>
#include <random>
using namespace std;

int Max()
{
    return randint(0,2);
}
int main()
{
    for (int i =0; i<10; i++)
        cout << Max() << " "
    cout << endl;
}
