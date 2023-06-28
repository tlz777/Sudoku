#include"common.h"
set<int> PossibleValueAtPosition(vector<vector<int>>& pz, int row, int col) {
    //计算某个位置的可填写的数字
    int r = row / 3 * 3;
    int c = col / 3 * 3;
    set<int> possible_values{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for (int i = r; i < r + 3; i++) {
        for (int j = c; j < c + 3; j++) {
            //遍历所在的方格，删除已经填写的值，保证方格内不重复
            possible_values.erase(pz[i][j]);
        }
    }
    for (int i = 0; i < 9; i++) {
        //保证同行同列不重复
        possible_values.erase(pz[row][i]);
        possible_values.erase(pz[i][col]);
    }
    return possible_values;
}
Generator::Generator() {
    //初始化game棋盘，未填写的值用0代表
    game = vector<vector<int>>(9, vector<int>(9, 0));
}
void Generator::init() {
    //初始化game棋盘，未填写的值用0代表
    game = vector<vector<int>>(9, vector<int>(9, 0));
}
bool Generator::GenEndgames(int n) {
    srand((unsigned)time(NULL));
    if (n == 81) {//递归结束，9*9全部生成
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
void Generator::GenPuzzle(int m, int r_input) {
    //生成谜题：生成终局->挖洞（递归挖，确保每一步有解）->生成谜题
    //r：空白数  m：难度，根据难度设置空白数
    GenEndgames(0);
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
    //生成一个随机的0-80的排列，利用这个排列来确定对应的挖洞位置
    vector<int> randomlist(81);
    iota(randomlist.begin(), randomlist.end(), 0);
    random_shuffle(randomlist.begin(), randomlist.end());
    DigHoles(randomlist,0,r);
}
void Generator::GenUniPuzzle() {
    init();
    GenEndgames(0);
    vector<int> randomlist(81);
    iota(randomlist.begin(), randomlist.end(), 0);
    random_shuffle(randomlist.begin(), randomlist.end());
    DigHoles(randomlist, 0);
}
void Generator::DigHoles(vector<int>& randomlist,int n,int x) {
    if (n >= x)
        return;
    int row = randomlist[n] / 9;//十位上的数字代表行
    int col = randomlist[n] % 9;//个位上的数字代表列
    if (game[row][col] > 0) {
        vector<vector<int>> pz_check(game);//利用这个变量来检测是否有解
        pz_check[row][col] = 0;
        int Nof_solution = CheckSolve(pz_check, 0, 0);
        if (Nof_solution > 0) {//只需要保证有解，不用只有1个
            game[row][col] = 0;
        }
    }
    DigHoles(randomlist, n + 1,x);
}
void Generator::DigHoles(vector<int>& randomlist, int n) {
    if (n >= 45) {
        return;
    }
    int row = randomlist[n] / 9;//十位上的数字代表行
    int col = randomlist[n] % 9;//个位上的数字代表列
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
