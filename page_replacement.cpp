#include <iostream>
#include <iomanip>
using namespace std;
main()
{
    cout << "1)FIFO\n2)LRU\n3)OPTIMAL\nEnter your choice : ";
    int o;
    cin >> o;
    cout << "Enter the number of elements in page reference string: ";
    int n;
    cin >> n;
    int *p = (int *)malloc(sizeof(int) * n);
    cout << "Enter the page reference string: ";
    for (int i = 0; i < n; i++)
        cin >> p[i];
    cout << "Enter the number of page frames: ";
    int fn;
    cin >> fn;
    int *f = (int *)malloc(sizeof(int) * fn), *q;
    for (int i = 0; i < fn; i++)
        f[i] = -1;
    cout << "\n\n"
         << left << setw(25) << setfill(' ') << "Action";
    cout << left << setw(20) << setfill(' ') << "Before";
    cout << left << setw(20) << setfill(' ') << "After";
    int ph = 0, pf = 0, re = 0, e = 0;
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
            for (int j = fn - 1; j >= 0; j--)
                cout << f[j] << " ";
            if (o == 1)
            {
                f[re] = p[i];
                re = (re + 1) % fn;
            }
            else if (o == 2)
            {
                int t = 0, b;
                for (int j = 0; j < fn; j++)
                {
                    int k;
                    for (k = i - 1; k >= 0; k--)
                        if (f[j] == p[k])
                            break;
                    if (i - k > t)
                    {
                        t = i - k;
                        b = j;
                    }
                }
                f[b] = p[i];
            }
            else
            {
                if (e < fn)
                    f[e++] = p[i];
                else
                {
                    int t = 0, b;
                    for (int j = 0; j < fn; j++)
                    {
                        int k;
                        for (k = i + 1; k < n; k++)
                            if (f[j] == p[k])
                                break;
                        if (k - i > t)
                        {
                            t = k - i;
                            b = j;
                        }
                    }
                    f[b] = p[i];
                }
            }

            cout << left << setw(15) << setfill(' ') << " ";
            for (int j = fn - 1; j >= 0; j--)
                cout << f[j] << " ";
            pf++;
        }
    }
    cout << "\n\nTotal Page Faults: " << pf << "\nTotal Page Hits: " << ph;
}