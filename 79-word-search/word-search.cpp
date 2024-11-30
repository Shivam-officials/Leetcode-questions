class Solution
{
    public:

        bool isSafe(int newX, int newY, vector<vector < bool>> &visited)
        {
            if (newX < 0 || newX >= visited.size() || newY < 0 || newY >= visited[0].size() || visited[newX][newY] == true)
            {
                return false;
            }
            return true;
        }

    bool wordSearch(int curX, int curY, string &word, int index, vector<vector < char>> &grid, vector< vector< bool>> &visited)
    {

       	// base case
        if (index == word.size() - 1)
        {
        	// every index is checked that the word matched at the current coordinates with current index already so if index is at last of word that means we found the words bcz bina check kiye to ayega ni is index pe word 
            return true;
        }

        vector<int> dx
        { 0,
            1,
            0,
            -1 };	// directions R,D,L,U
        vector<int> dy
        { 1,
            0,
            -1,
            0 };

        bool surroundExist = false;
        for (int i = 0; i < 4; i++)
        {
            int newX = curX + dx[i];
            int newY = curY + dy[i];
            if (isSafe(newX, newY, visited))
            {
            	// checks the side note has the next word before going there
                if (grid[newX][newY] == word[index +1 ])
                {

                    visited[newX][newY] = true;
                    bool ans = wordSearch(newX, newY, word, index + 1, grid, visited);
                    visited[newX][newY] = false;
                    surroundExist = surroundExist || ans;
                }
            }
        }
        return surroundExist;
    }

    bool exist(vector<vector < char>> &grid, string &word)
    {

        int m = grid.size(), n = grid[0].size();
        bool exist = false;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == word[0])
                {
                    vector<vector < bool>> visited(m, vector<bool> (n, false));
                    visited[i][j] = true;
                    bool ans = wordSearch(i, j, word, 0, grid, visited);
                    exist = ans || exist;
                }
            }
        }

        return exist;
    }
};