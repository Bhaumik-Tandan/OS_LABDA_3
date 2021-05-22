#include <iostream>
#include <iomanip>
using namespace std;
typedef struct
{
    int n;
    int v;
} block;
main()
{
    cout << "1)First Fit\n2)Best Fit\n3)Worst Fit\nEnter your choice :";
    int o;
    cin >> o;
    cout << "Enter the number of processes: ";
    int n;
    cin >> n;
    int *p = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the memory size for process " << i + 1 << ": ";
        cin >> p[i];
    }
    cout << "Enter the number of memory blocks: ";
    int bn;
    cin >> bn;
    block *b = (block *)malloc(sizeof(block) * bn);
    for (int i = 0; i < bn; i++)
    {
        cout << "Enter the memory size for block " << i + 1 << ": ";
        cin >> b[i].v;
        b[i].n = i + 1;
    }
    for (int i = 0; i < bn - 1; i++)
        for (int j = 0; j < bn - i - 1; j++)
            if (o == 2 && b[j].v > b[j + 1].v)
            {

                block t = b[j];
                b[j] = b[j + 1];
                b[j + 1] = t;
            }
            else if (o == 3 && b[j].v < b[j + 1].v)
            {
                block t = b[j];
                b[j] = b[j + 1];
                b[j + 1] = t;
            }
    cout << left << setw(25) << setfill(' ') << "Process Number";
    cout << left << setw(25) << setfill(' ') << "Process Size";
    cout << left << setw(25) << setfill(' ') << "Block Number";
    for (int i = 0; i < n; i++)
    {
        cout << endl
             << left << setw(25) << setfill(' ') << i + 1;
        cout << left << setw(25) << setfill(' ') << p[i];
        int j;
        for (j = 0; j < bn; j++)
            if (p[i] <= b[j].v)
            {
                cout << left << setw(25) << setfill(' ') << b[j].n;
                b[j].v -= p[i];
                break;
            }
        if (j == bn)
            cout << left << setw(25) << setfill(' ') << "Not Allocated";
    }
}
