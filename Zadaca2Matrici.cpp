//Ovaa programa naogja najgolemiot neparen broj i negovata pozicija vo matricata
#include <iostream>
#include <climits>
using namespace std;

int main() {
    int m, n;

    // Внес на димензии на матрицата
    cout << "Внеси број на редици (m): ";
    cin >> m;
    cout << "Внеси број на колони (n): ";
    cin >> n;

    // Дефинирање на матрица
    int matrica[m][n];

    // Внесување на елементи во матрицата
    cout << "Внеси елементи на матрицата:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrica[i][j];
        }
    }

    // Променливи за најголемиот непарен број и неговата позиција
    int maxNeparen = INT_MIN;
    int maxRed = -1, maxKolona = -1;

    // Пребарување на најголемиот непарен број
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrica[i][j] % 2 != 0) { // Проверка дали бројот е непарен
                if (matrica[i][j] > maxNeparen) {
                    maxNeparen = matrica[i][j];
                    maxRed = i;
                    maxKolona = j;
                }
            }
        }
    }

    // Печатење на резултатот
    if (maxRed != -1 && maxKolona != -1) {
        cout << "Најголемиот непарен број е: " << maxNeparen << endl;
        cout << "Неговата позиција е: (" << maxRed + 1 << ", " << maxKolona + 1 << ")" << endl;
    } else {
        cout << "Нема непарни броеви во матрицата." << endl;
    }

    return 0;
}
