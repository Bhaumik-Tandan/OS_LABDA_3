#include <iostream>
#include <iomanip>
using namespace std;
main()
{
    //cout << "1)FIFO\n2)LRU\n3)OPTIMAL\nEnter your choice : ";
    int o = 1;
    // cin >> o;
    //cout << "Enter the number of elements in page reference string: ";
    int n = 7;
    // cin >> n;
    int *p = (int *)malloc(sizeof(int) * n);
    p[0] = 1;
    p[1] = 3;
    p[2] = 0;
    p[3] = 3;
    p[4] = 5;
    p[5] = 6;
    p[6] = 3;
    // cout << "Enter the page reference string: ";
    // for (int i = 0; i < n; i++)
    //     cin >> p[i];
    //cout << "Enter the number of elements in page reference string: ";
    int fn = 3;
    // cin >> fn;
    int *f = (int *)malloc(sizeof(int) * fn);
    for (int i = 0; i < fn; i++)
        f[i] = -1;
    cout << "\n\n"
         << left << setw(25) << setfill(' ') << "Action";
    cout << left << setw(20) << setfill(' ') << "Before";
    cout << left << setw(20) << setfill(' ') << "After";
    int ph = 0, pf = 0, re = 0;
    for (int i = 0; i < n; i++)
    {
        int fl = 0;
        for (int j = 0; j < fn; j++)
            if (f[j] == p[i])
            {
                fl = 1;
                cout << endl
                     << left << setw(25) << setfill(' ') << "Page Hit";
                ph++;
                break;
            }
        if (fl == 0)
        {
            cout << endl
                 << left << setw(25) << setfill(' ') << "Page Fault";
            cout << left << setw(20) << setfill(' ');
            for (int j = fn - 1; j >= 0; j--)
                cout << f[j] << " ";
            f[re] = p[i];
            re = (re + 1) % fn;
            cout << left << setw(20);
            for (int j = fn - 1; j >= 0; j--)
                cout << f[j] << " ";
            pf++;
        }
    }
}