#include <iostream>
using namespace std;
main()
{
    int *h = (int *)calloc(sizeof(int), 500);
    cout << "1)Sequential\n2)Linked\n3)Indexed\nEnter your choice :";
    int o;
    cin >> o;
    cout << "Enter the number of files: ";
    int n;
    cin >> n;
    int **ind;
    if (o == 3)
        ind = (int **)malloc(sizeof(int *) * 500);
    int *fi = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter the size of file " << i + 1 << ": ";
        int s;
        cin >> s;
        if (o == 1)
            while (true)
            {
                int j, a = rand() % (501 - s), f = 1;
                for (j = a; j < a + s; j++)
                    if (h[j] != 0)
                    {
                        f = 0;
                        break;
                    }
                if (f == 0)
                    continue;
                fi[i] = a;
                for (j = a; j < a + s; j++)
                    h[j] = i + 1;
                break;
            }
        else if (o == 2)
        {
            int *p = fi + i;
            for (int j = 0; j <= s; j++)
            {
                int b;
                while (true)
                {
                    b = rand() % 500;
                    if (h[b] == 0)
                        break;
                }
                *p = b;
                p = h + b;
            }
            *p = -1;
        }
        else
        {
            int in;
            while (true)
            {
                in = rand() % 500;
                if (h[in] == 0)
                    break;
            }
            h[in] = s;
            fi[i] = in;
            ind[in] = (int *)malloc(sizeof(int) * s);
            for (int j = 0; j < s; j++)
            {
                while (true)
                {
                    in = rand() % 500;
                    if (h[in] == 0)
                        break;
                }
                h[in] = i + 1;
                ind[fi[i]][j] = in;
            }
        }
    }
    cout << "\nAssigned blocks are:-\n\n";
    for (int i = 0; i < n; i++)
    {
        int j = fi[i];
        if (o == 1)
            while (h[fi[i]] == h[j++])
                cout << j + 1 << "-->" << i + 1 << endl;
        else if (o == 2)
            while (h[j] != -1)
            {
                cout << j + 1 << "-->" << i + 1 << endl;
                j = h[j];
            }
        else
            for (int k = 0; k < h[j]; k++)
                cout << j + 1 << ":" << ind[j][k] << "-->" << i + 1 << endl;
        cout << endl;
    }
}