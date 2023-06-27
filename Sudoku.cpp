#include<iostream>
using namespace std;
// 分析需求 需要创建数独题目、格式化读入数独题目、解数独、重定向输出、控制数独难度
int main(int argc, char* argv[]) {
    string help = "-h";
    string SudokuNum = "-c";
    string SudokuPath = "-s";
    string SudokuGameNum = "-n";
    string SudokuGameDiff = "-m";
    string SudokuGameSpace = "-r";
    string SudokuGameSolve = "-u";

    if (!strcmp(help.c_str(), argv[1])) {
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
    
}