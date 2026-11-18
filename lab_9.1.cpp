// Lab_9_1.cpp
//               головний файл проекту – функція main

#include <iostream>
#include <math.h>
#include <iomanip>

#include "dod.h"
#include "sum.h"
#include "var.h"

using namespace std;

using namespace nsDod;
using namespace nsSum;
using namespace nsVar;

int main()
{
    cout << "x_p = "; cin >> x_p;
    cout << "x_k = "; cin >> x_k;
    cout << "dx  = "; cin >> dx;
    cout << "e   = "; cin >> e;
    cout << endl;

    // заголовок таблиці
    cout << "  ln((x+1)/(x-1)) = 2 * sum 1/((2n+1)*x^(2n+1))" << endl;
    // шапка таблиці
    cout << "-------------------------------------------------" << endl;
    cout << "|" << setw(8)  << "x"
         << "|" << setw(16) << "ln((x+1)/(x-1))"
         << "|" << setw(14) << "S"
         << "|" << setw(6)  << "n" << "|" << endl;
    cout << "-------------------------------------------------" << endl;

    x = x_p;
    while ( x <= x_k ){
        sum();                      // виклик процедури обчислення суми

        cout << "|" << setw(8)  << fixed << setprecision(3) << x
             << "|" << setw(16) << setprecision(6) << log((x + 1) / (x - 1))
             << "|" << setw(14) << s
             << "|" << setw(6)  << n << "|" << endl;   // форматний вивід

        x += dx;
    }
    cout << "-------------------------------------------------" << endl;

    cin.get();
    return 0;
}