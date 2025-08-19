#include <iostream>
using namespace std;// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    auto lang = "C++";
    int N = 10;
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


    for (int k = 0; k< range; k++){
        char agent = 'A'+ k;
        int i = rand()% N ;
        int j = rand() % N ;

        while (grid[i][j] != '.') {
            i = rand() % N ;
            j = rand() % N ;
        }
        grid[i][j] = agent;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout <<grid[i][j] << ' ';
        }
        cout << endl;
    }


    return 0;
}