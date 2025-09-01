#include <iostream>
#include <vector>
#include <ctime>
#include <thread>
#include <chrono>
#include <map>
#include <utility>

using namespace std;

void maybeSpawnWall(vector<vector<char> > &grid, int N) {
}

using Cell = std::pair<int, int>;
using CellRequests = std::map<Cell, std::vector<int> >;


struct Agent {
    int r, c, dr, dc, new_r, new_c;
    char symbol;
};

void printGrid(const vector<vector<char> > &grid, int N) {
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


    vector<vector<char> > grid(N, vector<char>(N, '.'));;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = '.';
        }
    }
    int maxAgents;
    int minAgents;
    cout << "Enter Minimum Number of Agents: ";
    cin >> minAgents;
    cout << "Enter Maximum Number of Agents: ";
    cin >> maxAgents;

    srand(time(0));
    int range = rand() % (maxAgents - minAgents + 1) + minAgents;

    string symbols = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
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

        a.r = r;
        a.c = c;
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


        grid[agents[i].dr][agents[i].dc] = '*';
    }

    int walls = (N * N) * (rand() % (10 - 5 + 1) + 10) / 100;
    for (int k = 0; k < walls; k++) {
        int r, c;
        do {
            r = rand() % N;
            c = rand() % N;
        } while (grid[r][c] != '.');
        grid[r][c] = '#';
    }


    bool allReached = false;

    while (!allReached) {
        allReached = true;
        CellRequests requests;
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

                // 1. Collect requests
                map<pair<int, int>, vector<int> > cellRequests;
                for (int i = 0; i < agents.size(); i++) {
                    if (agents[i].r == agents[i].dr && agents[i].c == agents[i].dc) continue;

                    int new_r = agents[i].r;
                    int new_c = agents[i].c;

                    if (agents[i].r > agents[i].dr) new_r--;
                    else if (agents[i].r < agents[i].dr) new_r++;

                    if (agents[i].c > agents[i].dc) new_c--;
                    else if (agents[i].c < agents[i].dc) new_c++;

                    if (grid[new_r][agents[i].c] == '#') new_r = agents[i].r;
                    if (grid[agents[i].r][new_c] == '#') new_c = agents[i].c;

                    cellRequests[{new_r, new_c}].push_back(i);
                }

                // 2. Resolve requests
                for (auto &entry: cellRequests) {
                    auto cell = entry.first;
                    auto &v = entry.second;

                    if (v.size() == 1) {
                        int agentIndex = v[0];
                        grid[agents[agentIndex].r][agents[agentIndex].c] = '.';
                        agents[agentIndex].r = cell.first;
                        agents[agentIndex].c = cell.second;
                        grid[cell.first][cell.second] = agents[agentIndex].symbol;
                    } else {
                        int winner = v[0]; // FCFS
                        grid[agents[winner].r][agents[winner].c] = '.';
                        agents[winner].r = cell.first;
                        agents[winner].c = cell.second;
                        grid[cell.first][cell.second] = agents[winner].symbol;
                        // losers stay put, no change
                    }
                }


                grid[old_r][old_c] = '.';
                agents[i].r = new_r;
                agents[i].c = new_c;
                grid[new_r][new_c] = agents[i].symbol; // agent marker

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
            cout << grid[i][j] << "  ";
        }
        cout << endl;
    }


    return 0;
}
