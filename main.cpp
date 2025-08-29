#include <iostream>
#include <vector>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

void maybeSpawnWall(vector<vector<char>>& grid, int N) {

}


struct Agent
{
    int r, c, dr, dc, new_r, new_c;
    char symbol;
};

void printGrid(const vector<vector<char>>& grid, int N) {
    system("cls");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}


int main() {
    auto lang = "C++";
    int N;
    cout << "Enter the Size of grid: ";
    cin >> N;
    cout << endl;


    vector<vector<char>> grid(N, vector<char>(N, '.'));
;
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
                    "abcdefghijklmnopqrstuvwxyz";

    cout << "Total number of agents: " << range << endl;

    cout << endl;

    vector<Agent> agents;



    Agent a;
    int r, c, dr, dc;
    for (int k = 0; k < range; k++) {

        do {
            r = rand() % N;
            c = rand() % N;
        } while (grid[r][c] != '.');

        a.r =r;
        a.c =c;
        a.symbol = symbols[rand() % symbols.length()];

        grid[r][c] = a.symbol;
        agents.push_back(a);
    }
    for (int i = 0; i < agents.size(); i++) {
        do {
            dr = rand() % N;
            dc = rand() % N;
        } while (grid[dr][dc] != '.');

        agents[i].dr = dr;
        agents[i].dc = dc;


        grid [agents[i].dr][agents[i].dc] = '*';
    }

    int walls = (N * N) * (rand() % (10 - 5 + 1) + 10) / 100;

    int wall_r, wall_c;

    for (int k = 0; k < walls; k++) {

        int maxwalls = 0.2 * N * N;
        int wallcount = 0;
        int chance = rand() % 100;
        if (chance < 30 && wallcount < maxwalls){
            do {
                wall_r = rand() % N;
                wall_c = rand() % N;
            } while (grid[wall_r][wall_c] != '.');

            grid[wall_r][wall_c] = '#';

            wallcount++;
        }
    }

    bool allReached = false;

    while (!allReached) {
        allReached = true;
        for (int i = 0; i < agents.size(); i++) {
            if (agents[i].r != agents[i].dr || agents[i].c != agents[i].dc) {
                allReached = false;

                int old_r = agents[i].r;
                int old_c = agents[i].c;

                int new_r = old_r;
                int new_c = old_c;

                if (old_r > agents[i].dr) new_r = old_r - 1;
                else if (old_r < agents[i].dr) new_r = old_r + 1;

                if (old_c > agents[i].dc) new_c = old_c - 1;
                else if (old_c < agents[i].dc) new_c = old_c + 1;

                if (grid[new_r][old_c] == '#') new_r = old_r;
                if (grid[old_r][new_c] == '#') new_c = old_c;

                grid[old_r][old_c] = '.';
                agents[i].r = new_r;
                agents[i].c = new_c;
                grid[new_r][new_c] = agents[i].symbol;  // agent marker

                printGrid(grid, N);
                int ms = 300;
                this_thread::sleep_for(chrono::milliseconds(ms));

            }
        }
        maybeSpawnWall(grid, N);

        int MS = 1500;
        printGrid(grid, N);
        this_thread::sleep_for(chrono::milliseconds(MS));
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout <<grid[i][j] << "  ";
        }
        cout << endl;
    }


    return 0;
}