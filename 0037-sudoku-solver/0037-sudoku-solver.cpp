class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

    bool solve(vector<vector<char>>& board){
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            if(board[i][j]=='.'){
                for(char c='1';c<='9';c++){
                    if(isvalid(board,i,j,c)){
                        board[i][j]=c;
                        if(solve(board)==true){
                            return true;
                        }else{
                            board[i][j]='.';
                        }
                        
                    }
                }
                return false;
                
            }
        }
        }
        return true;
    }

    bool isvalid(vector<vector<char>>& board,int t,int j,char c){
        for(int i=0;i<9;i++){
            if(board[i][j]==c){
                return false;
            }
            if(board[t][i]==c){
                return false;
            }
            if(board[3*(t/3)+i/3][3*(j/3)+i%3]==c){
                return false;
            }
        }
        return true;
    }
};