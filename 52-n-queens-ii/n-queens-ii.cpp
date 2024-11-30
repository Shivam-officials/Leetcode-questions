class Solution {
public:
    
// Global hash maps to track safe placements
unordered_map<int, bool> upDiagonal;
unordered_map<int, bool> rowCheck;
unordered_map<int, bool> downDiagonal;


void storeResult(vector<vector<char>> board, vector<vector<string>> &ans) {
    vector<string> tempAns;
    for (auto row : board) {
        string tempString;
        for (auto chars : row) {
            tempString.push_back(chars);
        }
        tempAns.push_back(tempString);
    }
    ans.push_back(tempAns);
}


bool isSafe(vector<vector<char>> &board, int row, int col) {
    

    if(rowCheck[row]==true)return false;
    if(upDiagonal[row-col] == true) return false;
    if(downDiagonal[row + col] == true ) return false;

    return true;
}


void solveNQueens_Backtrack(vector<vector<char>> &board, int col, int n, vector<vector<string>> &ans) {
    if (col == n) {
        storeResult(board, ans);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 'Q';
            upDiagonal[row - col] = rowCheck[row] = downDiagonal[row + col] = true;

            solveNQueens_Backtrack(board, col + 1, n, ans);

            board[row][col] = '.';
            upDiagonal[row - col] = rowCheck[row] = downDiagonal[row + col] = false;
        }
    }
}


vector<vector<string>> solveNQueens(int n) {
    vector<vector<char>> board(n, vector<char>(n, '.'));
    vector<vector<string>> ans;
    solveNQueens_Backtrack(board, 0, n, ans);
    return ans;
}
    int totalNQueens(int n) {
        return solveNQueens(n).size();
    }
};