#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Player {
    string firstName;
    string lastName;
    string teamName;
    int jerseyNumber;
    int goalsOrSaves;
    int hits;
    int timeOnField;
};

void sortPlayers(Player players[], int numPlayers) {
    for (int i = 0; i < numPlayers - 1; i++) {
        for (int j = i + 1; j < numPlayers; j++) {
            if (players[i].lastName > players[j].lastName) {
                Player temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }
}

int main() {
    const int MAX_PLAYERS = 30;
    Player players[MAX_PLAYERS];
    int numPlayers;

    cout << "Vnesi broj na igraci (max 30): ";
    cin >> numPlayers;

    while (numPlayers < 1 || numPlayers > 30) {
        cout << "Gresen broj na igraci! Vnesi povtorno: ";
        cin >> numPlayers;
    }

    for (int i = 0; i < numPlayers; i++) {
        cout << "Detali za igrac " << i + 1 << ":\n";
        cout << "Ime: ";
        cin >> players[i].firstName;
        cout << "Prezime: ";
        cin >> players[i].lastName;
        cout << "Tim za koj nastapuva: ";
        cin >> players[i].teamName;
        cout << "Broj na dres (1-15): ";
        cin >> players[i].jerseyNumber;
        while (players[i].jerseyNumber < 1 || players[i].jerseyNumber > 15) {
            cout << "Gresen vnesen broj! Vnesi povtorno: ";
            cin >> players[i].jerseyNumber;
        }
        cout << "Golovi/Odbrani: ";
        cin >> players[i].goalsOrSaves;
        cout << "Udari: ";
        cin >> players[i].hits;
        cout << "Minutaza na teren (0-60 mins): ";
        cin >> players[i].timeOnField;
        while (players[i].timeOnField < 0 || players[i].timeOnField > 60) {
            cout << "Gresno vneseno vreme! Vnesi povtorno: ";
            cin >> players[i].timeOnField;
        }
    }

    // Sort players by last name
    sortPlayers(players, numPlayers);

    // Write sorted players to file
    ofstream outFile("Sort.dat");
    for (int i = 0; i < numPlayers; i++) {
        outFile << players[i].firstName << " " << players[i].lastName << " "
                << players[i].teamName << " " << players[i].jerseyNumber << " "
                << players[i].goalsOrSaves << " " << players[i].hits << " "
                << players[i].timeOnField << endl;
    }
    outFile.close();

    // Determine best player
    Player bestPlayer = players[0];
    for (int i = 1; i < numPlayers; i++) {
        if (players[i].goalsOrSaves > bestPlayer.goalsOrSaves) {
            bestPlayer = players[i];
        }
    }

    // Display results
    int team1Goals = 0, team2Goals = 0;
    string team1 = players[0].teamName;
    string team2;

    for (int i = 0; i < numPlayers; i++) {
        if (players[i].teamName == team1) {
            team1Goals += players[i].goalsOrSaves;
        } else {
            team2 = players[i].teamName;
            team2Goals += players[i].goalsOrSaves;
        }
    }

    cout << "\nKraen rezultat:\n";
    cout << "Tim 1 (" << team1 << "): " << team1Goals << "\n";
    cout << "Tim 2 (" << team2 << "): " << team2Goals << "\n";
    cout << "Najdobar igrac MVP: " << bestPlayer.firstName << " " << bestPlayer.lastName
         << " od " << bestPlayer.teamName << " so " << bestPlayer.goalsOrSaves
         << " golovi/odbrani.\n";

    return 0;
}
