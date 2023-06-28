#include"common.h"
// 分析需求 需要创建数独题目、格式化读入数独题目、解数独、重定向输出、控制数独难度
int main(int argc, char* argv[]) {
    string help = "-h";
    string SudokuNum = "-c";
    string SudokuPath = "-s";
    string SudokuGameNum = "-n";
    string SudokuGameDiff = "-m";
    string SudokuGameSpace = "-r";
    string SudokuGameSolve = "-u";

    if (argc < 2 || !strcmp(help.c_str(), argv[1])) {
        cout << "Sudoku: usage ： [-h] --help information" << endl;
        cout << "                 [-c] [number(1-100000)]" << endl;
        cout << "                      --to generate n Sudoku endgames" << endl;
        cout << "                 [-s] [game.txt]" << endl;
        cout << "                      --to read several sudoku games from game.txt, and give their solutions, and generate in sudoku.txt" << endl;
        cout << "                 [-n] [number(1-10000)]" << endl;
        cout << "                      --to generate n Sudoku games" << endl;
        cout << "                 [-m] [difficulty(1-3)]" << endl;
        cout << "                      --to input the difficulty of Sudoku games which should be used with -n" << endl;
        cout << "                 [-r] [space(20-55)]" << endl;
        cout << "                      --to input the number of space in Sudoku games which should be used with -n" << endl;
        cout << "                 [-u] [ToSolve]" << endl;
        cout << "                      --to generate Sudoku games which has only one solve which should be used with -n" << endl;
        return 0;
    }
    else if (!strcmp(SudokuNum.c_str(), argv[1])) {//生成终局
        if (argc == 3) {
            int number = atoi(argv[2]);
            Generator* g = new Generator();
            for (int i = 0; i < number; i++) {
                cout << "----------GameNum: " << i + 1 << "----------" << endl;
                g->init();
                g->GenEndgames(0);
                g->print();
            }
        }
        else cout << "incorrect number of parameters,please check number or use '-h' for help" << endl;
    }
    else if (!strcmp(SudokuPath.c_str(), argv[1])) {//文件读取数独
        if (argc == 3) {

        }
        else cout << "incorrect number of parameters,please check number or use '-h' for help" << endl;
    }
    else if (!strcmp(argv[1], "-n")) {//生成数独问题
        int n = 0, m = 0, r = 0;//分别为生成数量、生成难度、生成的问题中空白数
        Generator* g = new Generator();
        if (argc >= 3) {
            n = atoi(argv[2]);
            if (n > 10000 || n < 1) {
                cout << "The value of parameter number is incorrect and should be 1-10000" << endl;
                return 0;
            }
        }
        else {
            cout << "incorrect number of parameters,please check number or use '-h' for help" << endl;
            return 0;
        }
        if (argc == 3) {}
        else if (argc == 4 && !strcmp(argv[3], "-u")) {//生成唯一解问题
            for (int i = 0; i < n; i++) {
                cout << "----------Generate uniGame:" << i + 1 << "----------" << endl;
                g->GenUniPuzzle();
                g->print();
                g->init();
            }
            return 0;
        }
        else if (argc == 5 && !strcmp(argv[3], "-m")) {//确定生成的难度
            m = atoi(argv[4]);
            if (m > 3 || m < 1) {
                cout << "incorrect value of parameter m which should be in 1-3" << endl;
                return 0;
            }
        }
        else if (argc == 5 && !strcmp(argv[3], "-r")) {
            r = atoi(argv[4]);
            if (r > 55 || r < 20) {
                cout << "incorrect value of parameter r which should be in 20-55" << endl;
                return 0;
            }
        }
        else {
            cout << "undefined command" << endl;
            return 0;
        }
        for (int i = 0; i < n; i++) {
            cout << "----------Generate Game:" << i + 1 << "----------" << endl;
            g->GenPuzzle(m, r);
            g->print();
            g->init();
        }
    }
    else {
        cout << "undefined command" << endl;
        return 0;
    }
}