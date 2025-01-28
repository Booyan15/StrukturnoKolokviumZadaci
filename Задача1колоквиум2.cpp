//Сума на квадрати на првите n природни броеви
#include <iostream>
using namespace std;

// Функција за пресметување на сума на квадрати
int sumaNaKvadrati(int n) {
    // Формула за сума на квадрати: n * (n + 1) * (2n + 1) / 6
    return n * (n + 1) * (2 * n + 1) / 6;
}

int main() {
    int n;
    cout << "Vnesi broj n: ";
    cin >> n;

    int rezultat = sumaNaKvadrati(n);
    cout << "Sumata na kvadratite na prvite " << n << " prirodni broevi e: " << rezultat << endl;

    return 0;
}
