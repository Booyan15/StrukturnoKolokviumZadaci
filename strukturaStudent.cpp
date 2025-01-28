#include <iostream>
#include <string>
using namespace std;

struct Student {
    string ime;
    string prezime;
    double prosek;
    double predmeti[5];  // Вредности за 5 предмети
};

double izracunajProsek(double predmeti[], int brojPredmeti) {
    double suma = 0;
    for (int i = 0; i < brojPredmeti; i++) {
        suma += predmeti[i];
    }
    return suma / brojPredmeti;
}

int main() {
    Student studenti[10];
    int brojStudenti = 10;
    Student studentSoNajvisokProsek;
    double najvisokProsek = 0;

    // Внесување на податоци за 10 студенти
    for (int i = 0; i < brojStudenti; i++) {
        cout << "Внесете податоци за студент " << i + 1 << ":" << endl;
        cout << "Име: ";
        cin >> studenti[i].ime;
        cout << "Презиме: ";
        cin >> studenti[i].prezime;

        // Внесување на оценки од 5 предмети
        for (int j = 0; j < 5; j++) {
            cout << "Оценка за предмет " << j + 1 << ": ";
            cin >> studenti[i].predmeti[j];
        }

        // Пресметување на просек
        studenti[i].prosek = izracunajProsek(studenti[i].predmeti, 5);

        // Провери дали овој студент има највисок просек
        if (studenti[i].prosek > najvisokProsek) {
            najvisokProsek = studenti[i].prosek;
            studentSoNajvisokProsek = studenti[i];
        }
    }

    // Печатење на студентот со највисок просек
    cout << "\nСтудентот со највисок просек е:" << endl;
    cout << "Име: " << studentSoNajvisokProsek.ime << endl;
    cout << "Презиме: " << studentSoNajvisokProsek.prezime << endl;
    cout << "Просек: " << studentSoNajvisokProsek.prosek << endl;

    return 0;
}
