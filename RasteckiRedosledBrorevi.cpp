#include <iostream>
using namespace std;

int main() {
    int broevi[30];
    int parniBroevi[30];  // Максимален број на парни броеви
    int brojParni = 0;

    cout << "Внесете 30 цели броеви: " << endl;

    // Внесување на 30 цели броеви
    for (int i = 0; i < 30; i++) {
        cin >> broevi[i];
    }

    // Филтрирање на парни броеви
    for (int i = 0; i < 30; i++) {
        if (broevi[i] % 2 == 0) {
            parniBroevi[brojParni] = broevi[i];
            brojParni++;
        }
    }

    // Подредување на парните броеви во растечки редослед (базично сортирање)
    for (int i = 0; i < brojParni - 1; i++) {
        for (int j = i + 1; j < brojParni; j++) {
            if (parniBroevi[i] > parniBroevi[j]) {
                // Размена на елементи
                int temp = parniBroevi[i];
                parniBroevi[i] = parniBroevi[j];
                parniBroevi[j] = temp;
            }
        }
    }

    // Печатење на подредените парни броеви
    cout << "Парните броеви во растечки редослед се: ";
    for (int i = 0; i < brojParni; i++) {
        cout << parniBroevi[i] << " ";
    }
    cout << endl;

    return 0;
}
