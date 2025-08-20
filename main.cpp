#include <iostream>
#include <vector>
#include <ctime>

using namespace std;
int main() {
    auto lang = "C++";
    int N;
    cout << "Enter the Size of grid: ";
    cin >> N;
    cout << endl;


    char grid[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] ='.';
        }
    }
    int maxAgents;
    int minAgents;
    cout<< "Enter Minimum Number of Agents: ";
    cin >> minAgents;
    cout << "Enter Maximum Number of Agents: ";
    cin >> maxAgents;

    srand(time(0));
    int range = rand() % (maxAgents - minAgents + 1) + minAgents;
    string symbols= "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                    "abcdefghijklmnopqrstuvwxyz"
                    "0123456789"
                    "!@#$%^&*?";

    vector <int> agents = {symbol, r, c, dr, dc}

    for (int k = 0; k < range; k++) {
        char agent = symbols[k % symbols.size()];
        int i = rand()% N ;
        int j = rand() % N ;

        while (grid[i][j] != '.') {
            i = rand() % N ;
            j = rand() % N ;
        } agent& agent = agents[i];
            do {
                 r = rand() % N;
                c = rand() % N;
            } while (grid[r][c] != '.');

                let's do assigning position now
        grid[i][j] = agent;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout <<grid[i][j] << "  ";
        }
        cout << endl;
    }


    return 0;
}