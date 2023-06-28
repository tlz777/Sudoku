#include"common.h"
set<int> PossibleValueAtPosition(vector<vector<int>>& pz, int row, int col) {
    //����ĳ��λ�õĿ���д������
    int r = row / 3 * 3;
    int c = col / 3 * 3;
    set<int> possible_values{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for (int i = r; i < r + 3; i++) {
        for (int j = c; j < c + 3; j++) {
            //�������ڵķ���ɾ���Ѿ���д��ֵ����֤�����ڲ��ظ�
            possible_values.erase(pz[i][j]);
        }
    }
    for (int i = 0; i < 9; i++) {
        //��֤ͬ��ͬ�в��ظ�
        possible_values.erase(pz[row][i]);
        possible_values.erase(pz[i][col]);
    }
    return possible_values;
}
Generator::Generator() {
    //��ʼ��game���̣�δ��д��ֵ��0����
    game = vector<vector<int>>(9, vector<int>(9, 0));
}
void Generator::init() {
    //��ʼ��game���̣�δ��д��ֵ��0����
    game = vector<vector<int>>(9, vector<int>(9, 0));
}
bool Generator::GenEndgames(int n) {
    srand((unsigned)time(NULL));
    if (n == 81) {//�ݹ������9*9ȫ������
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
    //�������⣺�����վ�->�ڶ����ݹ��ڣ�ȷ��ÿһ���н⣩->��������
    //r���հ���  m���Ѷȣ������Ѷ����ÿհ���
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
    //����һ�������0-80�����У��������������ȷ����Ӧ���ڶ�λ��
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
    int row = randomlist[n] / 9;//ʮλ�ϵ����ִ�����
    int col = randomlist[n] % 9;//��λ�ϵ����ִ�����
    if (game[row][col] > 0) {
        vector<vector<int>> pz_check(game);//�����������������Ƿ��н�
        pz_check[row][col] = 0;
        int Nof_solution = CheckSolve(pz_check, 0, 0);
        if (Nof_solution > 0) {//ֻ��Ҫ��֤�н⣬����ֻ��1��
            game[row][col] = 0;
        }
    }
    DigHoles(randomlist, n + 1,x);
}
void Generator::DigHoles(vector<int>& randomlist, int n) {
    if (n >= 45) {
        return;
    }
    int row = randomlist[n] / 9;//ʮλ�ϵ����ִ�����
    int col = randomlist[n] % 9;//��λ�ϵ����ִ�����
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
