class Solution
{
    public:
        
    unordered_map<int, bool> upDiogonal;
    unordered_map<int, bool> rowcheck;
    unordered_map<int, bool> downDiogonal;
    void storeResult(vector<vector < char>> board, vector< vector< string>> &ans)
    {
        vector<string> tempAns;
        for (auto row: board)
        {
            string tempString;
            for (auto chars: row)
            {
                tempString.push_back(chars);
            }
            tempAns.push_back(tempString);
        }
        ans.push_back(tempAns);
    }

    bool isSafe(vector<vector < char>> &board, int row, int col)
    {
        if (rowcheck[row] == true)
        {
            return false;
        }

        if (upDiogonal[row - col] == true)
        {
            return false;
        }

        if (downDiogonal[row + col] == true)
        {
            return false;
        }

        return true;
    }

    void solveNQueens_Backtrack(vector<vector < char>> &board, int col, int n, vector< vector< string>> &ans)
    {
       	//base case
        if (col == n)
        {
            storeResult(board, ans);
            return;
        }

       	// 1 case hmara baki recursion ka
        for (int row = 0; row < n; row++)
        {
            if (isSafe(board, row, col))
            {
                board[row][col] = 'Q';

               	//upDiogonal
                upDiogonal[row - col] = true;
               	//left / current row
                rowcheck[row] = true;
               	//lowerDiogonal
                downDiogonal[row + col] = true;

                solveNQueens_Backtrack(board, col + 1, n, ans);
                board[row][col] = '.';

               	//upDiogonal
                upDiogonal[row - col] = false;
               	//left / current row
                rowcheck[row] = false;
               	//lowerDiogonal
                downDiogonal[row + col] = false;
            }
        }
    }
    vector<vector < string>> solveNQueens(int n)
    {
        vector<vector < char>> board(n, vector<char> (n, '.'));
        vector<vector < string>> ans;
        solveNQueens_Backtrack(board, 0, n, ans);
        return ans;
    }
};