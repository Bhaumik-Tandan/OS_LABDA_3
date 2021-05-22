#include <iostream>
#include <iomanip>
using namespace std;
main()
{
    cout << internal << setw(8) << setfill(' ') << "Bob";
    cout << endl
         << left << setw(8) << setfill(' ') << "Bob";
    cout << endl
         << right << setw(8) << setfill(' ') << "Bob";
}