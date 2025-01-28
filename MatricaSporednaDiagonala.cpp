#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Внесете број на редови и колони на квадратна матрица: ";
    cin >> n;

    int matrix[n][n];
    cout << "Внесете ги елементите на матрицата:" << endl;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Иницијализирај ги најмалиот и најголемиот елемент со првиот елемент под споредната дијагонала
    int minElement = matrix[1][0];
    int maxElement = matrix[1][0];
    int minRow = 1, minCol = 0;
    int maxRow = 1, maxCol = 0;

    // Пребарување под споредната дијагонала
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j > n - i - 1) { // Под споредната дијагонала
                if (matrix[i][j] < minElement) {
                    minElement = matrix[i][j];
                    minRow = i;
                    minCol = j;
                }
                if (matrix[i][j] > maxElement) {
                    maxElement = matrix[i][j];
                    maxRow = i;
                    maxCol = j;
                }
            }
        }
    }

    cout << "Најмалиот елемент под споредната дијагонала е " << minElement
         << " на позиција (" << minRow << ", " << minCol << ")" << endl;

    cout << "Најголемиот елемент под споредната дијагонала е " << maxElement
         << " на позиција (" << maxRow << ", " << maxCol << ")" << endl;

    return 0;
}
