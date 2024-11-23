class Solution
{
    public:

        bool isSafe(vector<vector < char>> &board, int row, int col, char option)
        {

           	// row check
            for (int k = 0; k < 9; k++)
            {
                if (board[row][k] == option)
                {
                    return false;
                }
            }
           	// column check
            for (int k = 0; k < 9; k++)
            {
                if (board[k][col] == option)
                {
                    return false;
                }
            }
           	// sub block check
            for (int k = 0; k < 9; k++)
            {
                int x = 3 *(row / 3) + k / 3;
                int y = 3 *(col / 3) + k % 3;
                if (board[x][y] == option)
                {
                    return false;
                }
            }

           	// valid case
            return true;
        }

    bool sodukuSolve(vector<vector < char>> &board, int size)
    {
       	// base hai hi ni

       	// find empty space

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (board[i][j] == '.')
                {
                   	// found empty at this place

                    for (char options = '1'; options <= '9'; options++)
                    {
                        if (isSafe(board, i, j, options))
                        {
                            board[i][j] = options;
                            bool ans = sodukuSolve(board, size);
                            if (ans)
                            {
                                return true;
                            }
                            else
                            {
                                board[i][j] = '.';	// backtrack
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector < char>> &board) {
        sodukuSolve(board,9);
    }
};