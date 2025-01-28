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

    // Иницијализација на најголемиот непарен број
    int maxNeparen = INT_MIN, maxRed = 0, maxKolona = 0;

    // Пребарување на најголемиот непарен број
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrica[i][j] % 2 != 0 && matrica[i][j] > maxNeparen) {
                maxNeparen = matrica[i][j];
                maxRed = i + 1; // Позиции со индекси почнуваат од 1
                maxKolona = j + 1;
            }
        }
    }

    // Печатење на резултатот
    if (maxNeparen == INT_MIN) {
        cout << "Нема непарни броеви во матрицата." << endl;
    } else {
        cout << "Најголемиот непарен број е: " << maxNeparen << endl;
        cout << "Неговата позиција е: (" << maxRed << ", " << maxKolona << ")" << endl;
    }

    return 0;
}
