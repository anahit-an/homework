#include <iostream>
using namespace std;
bool SudokuBoard(char board[9][9]) {
    bool row=true;
    bool column=true;
    bool subBox = true;
    for (int i=0; i<9; i++) {
        bool rowused[10]={false};
        bool colused[10]={false};
        for (int j=0; j<9; j++) {
            if (board[i][j]!='.') {
                int num=board[i][j]-'0';
                if (rowused[num]) {
                    row=false;
                }
                rowused[num]=true;
            }
            if (board[j][i]!='.') {
                int num=board[j][i]-'0';
                if (colused[num]) {
                    column=false;
                }
                colused[num]=true;
            }
        }
    }
    for (int boxRow=0; boxRow<9; boxRow +=3) {
        for (int boxCol=0; boxCol<9; boxCol+=3) {
            bool used[10]={false};
            for (int i=0; i<3; i++) {
                for (int j=0; j<3; j++) {
                    char cell=board[boxRow+i][boxCol+j];
                    if (cell!='.') {
                        int num=cell-'0';

                        if (used[num]) {
                            subBox=false;
                        }
                        used[num]=true;
                    }
                }
            }
        }
    }
    if (row && column && subBox) {
        return true;
    }
    return false;
}
int main() {
    const int n = 9;
    char board[n][n] = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    cout<<SudokuBoard(board);
    return 0;
}
