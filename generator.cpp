#include"common.h"
Generator::Generator() {
    vector<vector<int>> game(9, vector<int>(9, 0));
}
bool Generator::GenEndgames(int n) {
    if (n == 81) {
        return true;
    }
    int row = n / 9;
    int col = n % 9;
    if (game[row][col] > 0) {
        if (GenEndgames(n + 1)) {
            return true;
        }
    }
    else {
        set<int> l = PossibleValueAtPosition(game, row, col);
        vector<int> values(l.begin(), l.end());
        random_shuffle(values.begin(), values.end());
        for (int v : values) {
            game[row][col] = v;
            if (GenEndgames(n + 1)) {
                return true;
            }
            game[row][col] = 0;
        }
    }
    return false;
}
void Generator::GenPuzzle(int n, int m, int r_input) {
    int r;
    if (r_input == 0) {
        if (m == 1)
            r = 20;
        else if (m == 2)
            r = 40;
        else if (m == 3)
            r = 60;
        else r = 30;
    }
    else r = r_input;
    vector<int> randomlist(81);
    iota(randomlist.begin(), randomlist.end(), 0);
    random_shuffle(randomlist.begin(), randomlist.end());
    DigHoles(randomlist,0,r);
}
void Generator::GenUniPuzzle(int n) {
    vector<int> randomlist(81);
    iota(randomlist.begin(), randomlist.end(), 0);
    random_shuffle(randomlist.begin(), randomlist.end());
    DigHoles(randomlist, 0);
}
void Generator::DigHoles(vector<int>& randomlist,int n,int x) {
    if (n >= x)
        return;
    int row = randomlist[n] / 9;
    int col = randomlist[n] % 9;
    if (game[row][col] > 0) {
        vector<vector<int>> pz_check(game);
        pz_check[row][col] = 0;
        int Nof_solution = CheckSolve(pz_check, 0, 0);
        if (Nof_solution > 0) {
            game[row][col] = 0;
        }
    }
    DigHoles(randomlist, n + 1);
}
void Generator::DigHoles(vector<int>& randomlist, int n) {
    if (n >= 45) {
        return;
    }
    int row = randomlist[n] / 9;
    int col = randomlist[n] % 9;
    if (game[row][col] > 0) {
        vector<vector<int>> pz_check(game);
        pz_check[row][col] = 0;
        int Nof_solution = CheckSolve(pz_check, 0, 0);
        if (Nof_solution == 1) {
            game[row][col] = 0;
        }
    }
    DigHoles(randomlist, n + 1);
}
void Generator::print(){
    cout << " -----------------------------------" << endl;
    for (int i = 0; i < 9; i++) {
        cout << "|";
        for (int j = 0; j < 9; j++) {
            if (game[i][j] != 0)
                cout << " " << game[i][j] << " |";
            else
                cout << "   |";
        }
        cout << endl << " -----------------------------------" << endl;
    }
    cout << endl;

}
int Generator::CheckSolve(vector<vector<int>>& pz, int n, int Nof_solution) {
    if (Nof_solution > 1) {
        return Nof_solution;
    }
    if (n >= 81) {
        Nof_solution += 1;
        return Nof_solution;
    }
    int row = n / 9;
    int col = n % 9;
    if (pz[row][col] > 0) {
        Nof_solution = CheckSolve(pz, n + 1, Nof_solution);
    }
    else {
        set<int> l = PossibleValueAtPosition(pz, row, col);
        for (int v : l) {
            pz[row][col] = v;
            Nof_solution = CheckSolve(pz, n + 1, Nof_solution);
            pz[row][col] = 0;
        }
    }
    return Nof_solution;
}