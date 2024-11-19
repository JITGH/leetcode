// class Solution {
// public:
//     bool isValidSudoku(vector<vector<char>>& board) {
//         for(int row=0;row<9;row++){
//             unordered_set<char>seen;
//             for(int i=0;i<9;i++){
//                 if(board[row][i]=='.') continue;
//                 if(seen.count(board[row][i])) return false;
//                 seen.insert(board[row][i]);
//             }
//         }

//         for(int col=0;col<9;col++){
//             unordered_set<char>seen;
//             for(int i=0;i<9;i++){
//                 if(board[i][col]=='.') continue;
//                 if(seen.count(board[i][col])) return false;
//                 seen.insert(board[i][col]);
//             }
//         }

//         for(int sq=0;sq<9;sq++){
//             unordered_set<char>seen;
//             for(int i=0;i<3;i++){
//                 for(int j=0;j<3;j++){
//                     int row=(sq/3)*3+i;
//                     int col=(sq%3)*3+j;
//                     if(board[row][col]=='.') continue;
//                     if(seen.count(board[row][col])) return false;
//                     seen.insert(board[row][col]);
//                 }
//             }
//         }
//         return true;
//     }
// };


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // for(int row=0;row<9;row++){
        //     unordered_set<char>seen;
        //     for(int i=0;i<9;i++){
        //         if(board[row][i]=='.') continue;
        //         if(seen.count(board[row][i])) return false;
        //         seen.insert(board[row][i]);
        //     }
        // }

        // for(int col=0;col<9;col++){
        //     unordered_set<char>seen;
        //     for(int i=0;i<9;i++){
        //         if(board[i][col]=='.') continue;
        //         if(seen.count(board[i][col])) return false;
        //         seen.insert(board[i][col]);
        //     }
        // }

        // for(int sq=0;sq<9;sq++){
        //     unordered_set<char>seen;
        //     for(int i=0;i<3;i++){
        //         for(int j=0;j<3;j++){
        //             int row=(sq/3)*3+i;
        //             int col=(sq%3)*3+j;
        //             if(board[row][col]=='.') continue;
        //             if(seen.count(board[row][col])) return false;
        //             seen.insert(board[row][col]);
        //         }
        //     }
        // }
        // return true;

        int m=board.size();
        int n=board[0].size();
        unordered_set<char>row;
        unordered_set<char>col;
        unordered_set<char>g[3][3];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]!='.' && row.count(board[i][j])) return false;
                row.insert(board[i][j]);
                if(board[j][i]!='.' && col.count(board[j][i])) return false;
                col.insert(board[j][i]);

                int r=i/3;
                int c=j/3;
                if(board[i][j]!='.' && g[r][c].count(board[i][j])) return false;
                g[r][c].insert(board[i][j]);

            }
            row.clear();
            col.clear();
        }
        return true;
    }
};
