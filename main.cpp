#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Strukturata za sekoj igrac.
struct Igrac
{
    string Ime;
    string Prezime;
    string Ime_Na_Tim;
    int Br_Dres;
    int Golovi_Odbrani;
    int Udari;
    int Vreme_teren;
};

// Funkcija za sortiranje gi site igraci preku Bubble sort.
void Sort_Igraci(Igrac igrac[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (igrac[i].Prezime > igrac[j].Prezime ||
                (igrac[i].Prezime == igrac[j].Prezime && igrac[i].Ime > igrac[j].Ime) ||
                (igrac[i].Prezime == igrac[j].Prezime && igrac[i].Ime == igrac[j].Ime &&
                 igrac[i].Golovi_Odbrani < igrac[j].Golovi_Odbrani))
            {
                // Zamena na igraci[i] i igraci[j]
                Igrac temp = igrac[i];
                igrac[i] = igrac[j];
                igrac[j] = temp;
            }
        }
    }
}

int main()
{
    const int Max_igraci = 30; // Max broj na igraci. 15 igraci za sekoj tim posebno.

    Igrac igrac[Max_igraci]; // Struct niza za sekoj igrac.

    int Broj_Igraci; // Promenliva za kolko igraci ima na toj natprevar.

    string Tim1, Tim2; // Iminjata na dvata timovi.

    cout << "Vnesete ime na prviot tim:" << endl;
    cin >> Tim1;

    cout << "Vnesete ime na vtoriot tim:" << endl;
    cin >> Tim2;

    cout << "Kolko igraci nastapuvat vo ovoj natprevar? (Max 30 igraci): " << endl;
    cin >> Broj_Igraci;

    // Proverka za vneseniot broj na igraci.
    while (Broj_Igraci < 0 || Broj_Igraci > 30)
    {
        cout << "Pogresen Vnes! Nemoze tolko igraci da ima! Vnesete Povtorno:" << endl;
        cin >> Broj_Igraci;
    }

    // For ciklus za vnesuvanje na sekoja informacija.
    for (int i = 0; i < Broj_Igraci; i++)
    {
        cout << "Vnesete informaci za igrac #" << i + 1 << ":" << endl;

        cout << "Ime: ";
        cin >> igrac[i].Ime;

        cout << "Prezime: ";
        cin >> igrac[i].Prezime;

        cout << "Ime na Tim: ";
        cin.ignore();
        getline(cin, igrac[i].Ime_Na_Tim);

        cout << "Broj na Dres (1-15): ";
        cin >> igrac[i].Br_Dres;

        // Proverka za broj na dres.
        while (igrac[i].Br_Dres < 1 || igrac[i].Br_Dres > 15)
        {
            cout << "Pogresen vnes! Toj broj na dres ne postoi! Vnesete povtorno:" << endl;
            cin >> igrac[i].Br_Dres;
        }

        cout << "Golovi / Odbrani: ";
        cin >> igrac[i].Golovi_Odbrani;

        // Proverka za Golovi / Odbrani.
        while (igrac[i].Golovi_Odbrani < 0)
        {
            cout << "Pogresen vnes! Nemoze toj broj na Golovi / Odbrani! Vnesete povtorno:" << endl;
            cin >> igrac[i].Golovi_Odbrani;
        }

        cout << "Udari: ";
        cin >> igrac[i].Udari;

        // Proverka za broj na Udari.
        while (igrac[i].Udari < 0)
        {
            cout << "Pogresen vnes! Nemoze toj broj na Udari! Vnesete povtorno:" << endl;
            cin >> igrac[i].Udari;
        }

        cout << "Vreme na teren (0-60 min): ";
        cin >> igrac[i].Vreme_teren;

        // Proverka za vreme na teren.
        while (igrac[i].Vreme_teren < 0 || igrac[i].Vreme_teren > 60)
        {
            cout << "Pogresen vnes! Nemoze toa vreme na teren! Vnesete povtorno:" << endl;
            cin >> igrac[i].Vreme_teren;
        }
    }

    // Povik na funkcija za sortiranje.
    Sort_Igraci(igrac, Broj_Igraci);

    // Vpisuvanje na informaciite za site igraci vo Sort.dat datoteka.
    ofstream OutFile("Sort.dat");

    // Proverka za otvaranje na datotekata.
    if (!OutFile)
    {
        cout << "Datotekata imase problem so otvaranje.";
        return 1;
    }

    for (int i = 0; i < Broj_Igraci; i++)
    {
        OutFile << igrac[i].Ime << " " << igrac[i].Prezime << " " << igrac[i].Ime_Na_Tim << " "
                << igrac[i].Br_Dres << " " << igrac[i].Golovi_Odbrani << " "
                << igrac[i].Udari << " " << igrac[i].Vreme_teren << endl;
    }

    OutFile.close();

    // Citanje na informaciite od Sort.dat datoteka i presmetka za konecen rezultat.
    ifstream InFile("Sort.dat");

    // Proverka za otvaranje na datotekata.
    if (!InFile)
    {
        cout << "Datotekata imase problem so otvaranje.";
        return 1;
    }

    int Tim_1_Golovi = 0, Tim_2_Golovi = 0; // Posebni sumi za brojot na vkupni golovi.

    // For ciklus za sumiranje na golovite na timovite.
    for (int i = 0; i < Broj_Igraci; i++)
    {
        if (igrac[i].Ime_Na_Tim == Tim1)
        {
            Tim_1_Golovi += igrac[i].Golovi_Odbrani;
        }
        else if (igrac[i].Ime_Na_Tim == Tim2)
        {
            Tim_2_Golovi += igrac[i].Golovi_Odbrani;
        }
    }

    // Naoganje na najdobriot igrac.
    int Najmnogu_Golovi = 0; // Broj na golovi na najdobriot igrac.
    Igrac Najdobar_igrac = igrac[0]; // Pretpostavka deka prviot e najdobar.

    for (int i = 0; i < Broj_Igraci; i++)
    {
        if (igrac[i].Golovi_Odbrani > Najmnogu_Golovi)
        {
            Najmnogu_Golovi = igrac[i].Golovi_Odbrani;
            Najdobar_igrac = igrac[i];
        }
    }

    // Printanje na konecni rezultati.
    cout << endl << "Kraen rezultat:" << endl
         << "Tim 1 (" << Tim1 << "): " << Tim_1_Golovi << endl
         << "Tim 2 (" << Tim2 << "): " << Tim_2_Golovi << endl
         << "Najdobar igrac MVP: " << Najdobar_igrac.Ime << " "
         << Najdobar_igrac.Prezime << " od " << Najdobar_igrac.Ime_Na_Tim
         << " so " << Najdobar_igrac.Golovi_Odbrani << " golovi/odbrani.";

    InFile.close();
    return 0;
}
