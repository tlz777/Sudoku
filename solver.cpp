#include"common.h"
Solver::Solver(int** pz) {
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			game[i][j] = pz[i][j];
}
void Solver::SolvePuzzle() {
    //递归求解:找到每个数据中空的表格中可以填充的数字->找到其中可以填充的数字个数最少的表格->分别填充到该表格中
    SudokuPos* pos = FindMinBlank();
    if (!pos->res){
        print();
        if (WriteAnswer())
            cout << "Write the answer into ./answer.txt succefully!" << endl;
        else cout << "Write the answer into ./answer.txt unsuccefully,please check!" << endl;
        return;
    }
    for (int i = 0; i < 9; i++){
        if (pos->res[i] == 0)
            continue;
        game[pos->row][pos->col] = pos->res[i];
        SolvePuzzle();
    }
    game[pos->row][pos->col] = 0;
}
SudokuPos* Solver::FindMinBlank() {
    SudokuPos* pos = new SudokuPos();
    pos->res = 0;
    int* res;
    int total = 0, minum = 10;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++){
            if (game[i][j] != 0)
                continue;
            res = PossibleValueAtPosition(i, j);
            total = 0;
            for (int p = 0; p < 9; p++)
                if (res[p] != 0)
                    total++;
            if (total < minum){
                pos->row = i;
                pos->col = j;
                pos->res = res;
                minum = total;
            }
    }
    return pos;
}
int* Solver::PossibleValueAtPosition(int r, int c) {
    //流程同生成端,更换数据存储类型(其实...也没变) vector->int*
    int* res = new int[9] {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < 9; i++){
        res[game[r][i] - 1] = 0;
        res[game[i][c] - 1] = 0;
    }
    int p = r / 3 * 3;
    int q = c / 3 * 3;
    for (int x = p; x < p + 3; x++)
        for (int y = q; y < q + 3; y++)
            res[game[x][y] - 1] = 0;
    return res;
}
void Solver::print() {
    cout << " -----------------------------------" << endl;
    for (int i = 0; i < 9; i++) {
        cout << "|";
        for (int j = 0; j < 9; j++) {
            cout << " " << game[i][j] << " |";
        }
        cout << endl << " -----------------------------------" << endl;
    }
    cout << endl;
}
bool Solver::WriteAnswer() {
    ofstream file;
    file.open("answer.txt");
    if (file.is_open()) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                file << game[i][j] << " ";
            }
            file << endl;
        }
        file << endl;
        return true;
    }
    else {
        cout << "Unable to write the answer in file";
        return false;
    }
        
}