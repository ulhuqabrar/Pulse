#include <iostream>
#include <vector>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

struct Agent
{
    int r, c, dr, dc;
    char symbol;
};

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
                    "abcdefghijklmnopqrstuvwxyz";

    cout << "Total number of agents: " << range << endl << endl;

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

    for (int i = 0; i < agents.size(); i++) {
        while (agents[i].r != agents[i].dr || agents[i].c != agents[i].dc) {
            int ms = rand() % 1500;
            this_thread::sleep_for(chrono::milliseconds(ms));
            if (agents[i].r < agents[i].dr) {
                agents[i].r++;
            }
            else if (agents[i].r > agents[i].dr) {
                agents[i].r--;
            }
            if (agents[i].c < agents[i].dc) {
                agents[i].c++;
            }
            else if (agents[i].c > agents[i].dc) {
                agents[i].c--;
            }
        }
    }
//add update here
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout <<grid[i][j] << "  ";
        }
        cout << endl;
    }


    return 0;
}