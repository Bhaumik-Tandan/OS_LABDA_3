#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
main()
{
     char a[10];
     int h = 9;
     sprintf(a, "%d%c", h, ' ');
     sprintf(a, "%d%c", 8, ' ');
     cout << left << setw(20) << a;
     cout << "un";
}