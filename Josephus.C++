#include <iostream>
#include <chrono>
#include <fstream>
#include <thread>
using namespace std;

void Presentation(int n) {

    bool *eliminated = new bool[n + 1];
    for (int i = 1; i <= n; i++)
        eliminated[i] = false;

    int remain = n;
    int index = 2;

    while (remain > 1) {
        if (remain > 1) {
            eliminated[index] = true;
        }
        remain--;

        index += 2;

        if (index - 1 > n) {
            if (index % 2 == 0) {
                index = (2 * index - 1) % n;
            }
            else
                index = (2 * index + 1) % n;
        }
        else if (index - 1 == n) {
            index = 1;
        }

        for (int i = 1; i <= n; i++) {
            if (eliminated[i])
                cout << "x ";
            else
                cout << i << " ";
        }
        cout << endl;

        this_thread::sleep_for(chrono::seconds(2)); // Delay of 2 seconds
    }

    for (int i = 1; i <= n; i++) {
        if (!eliminated[i])
            cout << i << " Is The Winner!";
    }
    cout << endl;

    delete[] eliminated;
}

int josephus(int n) {
    if (n == 1)
        return 1;
    else if (n % 2 == 0)
        return 2 * josephus(n / 2) - 1;
    else
        return 2 * josephus(n / 2) + 1;
}

int main() {
    int n;
    cout << "Enter the number of people (n): ";
    cin >> n;
    cout << "Visualization!" << endl;
    Presentation(n);
    cout << "Winner using the main Algorithm: ";
    cout << josephus(n) << endl << endl;

    return 0;
}
